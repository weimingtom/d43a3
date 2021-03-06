/*
 * Rewrite routines of query tree
 * Teodor Sigaev <teodor@stack.net>
 */

#include "postgres.h"

#include <float.h>

#include "access/gist.h"
#include "access/itup.h"
#include "access/rtree.h"
#include "utils/array.h"
#include "utils/builtins.h"
#include "storage/bufpage.h"

#include "query.h"
#include "rewrite.h"

typedef struct NODE
{
	struct NODE *left;
	struct NODE *right;
	ITEM	   *valnode;
}	NODE;

/*
 * make query tree from plain view of query
 */
static NODE *
maketree(ITEM * in)
{
	NODE	   *node = (NODE *) palloc(sizeof(NODE));

	node->valnode = in;
	node->right = node->left = NULL;
	if (in->type == OPR)
	{
		node->right = maketree(in + 1);
		if (in->val != (int4) '!')
			node->left = maketree(in + in->left);
	}
	return node;
}

typedef struct
{
	ITEM	   *ptr;
	int4		len;
	int4		cur;
}	PLAINTREE;

static void
plainnode(PLAINTREE * state, NODE * node)
{
	if (state->cur == state->len)
	{
		state->len *= 2;
		state->ptr = (ITEM *) repalloc((void *) state->ptr, state->len * sizeof(ITEM));
	}
	memcpy((void *) &(state->ptr[state->cur]), (void *) node->valnode, sizeof(ITEM));
	if (node->valnode->type == VAL)
		state->cur++;
	else if (node->valnode->val == (int4) '!')
	{
		state->ptr[state->cur].left = 1;
		state->cur++;
		plainnode(state, node->right);
	}
	else
	{
		int4		cur = state->cur;

		state->cur++;
		plainnode(state, node->right);
		state->ptr[cur].left = state->cur - cur;
		plainnode(state, node->left);
	}
	pfree(node);
}

/*
 * make plain view of tree from 'normal' view of tree
 */
static ITEM *
plaintree(NODE * root, int4 *len)
{
	PLAINTREE	pl;

	pl.cur = 0;
	pl.len = 16;
	if (root && (root->valnode->type == VAL || root->valnode->type == OPR))
	{
		pl.ptr = (ITEM *) palloc(pl.len * sizeof(ITEM));
		plainnode(&pl, root);
	}
	else
		pl.ptr = NULL;
	*len = pl.cur;
	return pl.ptr;
}

static void
freetree(NODE * node)
{
	if (!node)
		return;
	if (node->left)
		freetree(node->left);
	if (node->right)
		freetree(node->right);
	pfree(node);
}

/*
 * clean tree for ! operator.
 * It's useful for debug, but in
 * other case, such view is used with search in index.
 * Operator ! always return TRUE
 */
static NODE *
clean_NOT_intree(NODE * node)
{
	if (node->valnode->type == VAL)
		return node;

	if (node->valnode->val == (int4) '!')
	{
		freetree(node);
		return NULL;
	}

	/* operator & or | */
	if (node->valnode->val == (int4) '|')
	{
		if ((node->left = clean_NOT_intree(node->left)) == NULL ||
			(node->right = clean_NOT_intree(node->right)) == NULL)
		{
			freetree(node);
			return NULL;
		}
	}
	else
	{
		NODE	   *res = node;

		node->left = clean_NOT_intree(node->left);
		node->right = clean_NOT_intree(node->right);
		if (node->left == NULL && node->right == NULL)
		{
			pfree(node);
			res = NULL;
		}
		else if (node->left == NULL)
		{
			res = node->right;
			pfree(node);
		}
		else if (node->right == NULL)
		{
			res = node->left;
			pfree(node);
		}
		return res;
	}
	return node;
}

ITEM *
clean_NOT(ITEM * ptr, int4 *len)
{
	NODE	   *root = maketree(ptr);

	return plaintree(clean_NOT_intree(root), len);
}

#define V_UNKNOWN	0
#define V_TRUE		1
#define V_FALSE		2

/*
 * Clean query tree from values which is always in
 * text (stopword)
 */
static NODE *
clean_fakeval_intree(NODE * node, char *result)
{
	char		lresult = V_UNKNOWN,
				rresult = V_UNKNOWN;

	if (node->valnode->type == VAL)
		return node;
	else if (node->valnode->type == VALTRUE)
	{
		pfree(node);
		*result = V_TRUE;
		return NULL;
	}


	if (node->valnode->val == (int4) '!')
	{
		node->right = clean_fakeval_intree(node->right, &rresult);
		if (!node->right)
		{
			*result = (rresult == V_TRUE) ? V_FALSE : V_TRUE;
			freetree(node);
			return NULL;
		}
	}
	else if (node->valnode->val == (int4) '|')
	{
		NODE	   *res = node;

		node->left = clean_fakeval_intree(node->left, &lresult);
		node->right = clean_fakeval_intree(node->right, &rresult);
		if (lresult == V_TRUE || rresult == V_TRUE)
		{
			freetree(node);
			*result = V_TRUE;
			return NULL;
		}
		else if (lresult == V_FALSE && rresult == V_FALSE)
		{
			freetree(node);
			*result = V_FALSE;
			return NULL;
		}
		else if (lresult == V_FALSE)
		{
			res = node->right;
			pfree(node);
		}
		else if (rresult == V_FALSE)
		{
			res = node->left;
			pfree(node);
		}
		return res;
	}
	else
	{
		NODE	   *res = node;

		node->left = clean_fakeval_intree(node->left, &lresult);
		node->right = clean_fakeval_intree(node->right, &rresult);
		if (lresult == V_FALSE || rresult == V_FALSE)
		{
			freetree(node);
			*result = V_FALSE;
			return NULL;
		}
		else if (lresult == V_TRUE && rresult == V_TRUE)
		{
			freetree(node);
			*result = V_TRUE;
			return NULL;
		}
		else if (lresult == V_TRUE)
		{
			res = node->right;
			pfree(node);
		}
		else if (rresult == V_TRUE)
		{
			res = node->left;
			pfree(node);
		}
		return res;
	}
	return node;
}

ITEM *
clean_fakeval(ITEM * ptr, int4 *len)
{
	NODE	   *root = maketree(ptr);
	char		result = V_UNKNOWN;
	NODE	   *resroot;

	resroot = clean_fakeval_intree(root, &result);
	if (result != V_UNKNOWN)
	{
		elog(NOTICE, "query contains only stopword(s) or doesn't contain lexeme(s), ignored");
		*len = 0;
		return NULL;
	}

	return plaintree(resroot, len);
}
