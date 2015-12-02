.\\" auto-generated by docbook2man-spec $Revision: 1.25 $
.TH "ALTER TABLE" "l" "2003-11-02" "SQL - Language Statements" "SQL Commands"
.SH NAME
ALTER TABLE \- change the definition of a table

.SH SYNOPSIS
.sp
.nf
ALTER TABLE [ ONLY ] \fIname\fR [ * ]
    ADD [ COLUMN ] \fIcolumn\fR \fItype\fR [ \fIcolumn_constraint\fR [ ... ] ]
ALTER TABLE [ ONLY ] \fIname\fR [ * ]
    DROP [ COLUMN ] \fIcolumn\fR [ RESTRICT | CASCADE ]
ALTER TABLE [ ONLY ] \fIname\fR [ * ]
    ALTER [ COLUMN ] \fIcolumn\fR { SET DEFAULT \fIexpression\fR | DROP DEFAULT }
ALTER TABLE [ ONLY ] \fIname\fR [ * ]
    ALTER [ COLUMN ] \fIcolumn\fR { SET | DROP } NOT NULL
ALTER TABLE [ ONLY ] \fIname\fR [ * ]
    ALTER [ COLUMN ] \fIcolumn\fR SET STATISTICS \fIinteger\fR
ALTER TABLE [ ONLY ] \fIname\fR [ * ]
    ALTER [ COLUMN ] \fIcolumn\fR SET STORAGE { PLAIN | EXTERNAL | EXTENDED | MAIN }
ALTER TABLE [ ONLY ] \fIname\fR [ * ]
    SET WITHOUT OIDS
ALTER TABLE [ ONLY ] \fIname\fR [ * ]
    RENAME [ COLUMN ] \fIcolumn\fR TO \fInew_column\fR
ALTER TABLE \fIname\fR
    RENAME TO \fInew_name\fR
ALTER TABLE [ ONLY ] \fIname\fR [ * ]
    ADD \fItable_constraint\fR
ALTER TABLE [ ONLY ] \fIname\fR [ * ]
    DROP CONSTRAINT \fIconstraint_name\fR [ RESTRICT | CASCADE ]
ALTER TABLE \fIname\fR
    OWNER TO \fInew_owner\fR
ALTER TABLE \fIname\fR
    CLUSTER ON \fIindex_name\fR
.sp
.fi
.SH "DESCRIPTION"
.PP
\fBALTER TABLE\fR changes the definition of an existing table.
There are several subforms:
.TP
\fBADD COLUMN\fR
This form adds a new column to the table using the same syntax as
CREATE TABLE [\fBcreate_table\fR(l)].
.TP
\fBDROP COLUMN\fR
This form drops a column from a table. Indexes and
table constraints involving the column will be automatically
dropped as well. You will need to say CASCADE if
anything outside the table depends on the column, for example,
foreign key references or views.
.TP
\fBSET/DROP DEFAULT\fR
These forms set or remove the default value for a column.
The default values only apply to subsequent \fBINSERT\fR
commands; they do not cause rows already in the table to change.
Defaults may also be created for views, in which case they are
inserted into \fBINSERT\fR statements on the view before
the view's ON INSERT rule is applied.
.TP
\fBSET/DROP NOT NULL\fR
These forms change whether a column is marked to allow null
values or to reject null values. You can only use SET
NOT NULL when the column contains no null values.
.TP
\fBSET STATISTICS\fR
This form
sets the per-column statistics-gathering target for subsequent
ANALYZE [\fBanalyze\fR(l)] operations.
The target can be set in the range 0 to 1000; alternatively, set it
to -1 to revert to using the system default statistics target.
.TP
\fBSET STORAGE\fR
This form sets the storage mode for a column. This controls whether this
column is held inline or in a supplementary table, and whether the data
should be compressed or not. PLAIN must be used
for fixed-length values such as \fBinteger\fR and is
inline, uncompressed. MAIN is for inline,
compressible data. EXTERNAL is for external,
uncompressed data, and EXTENDED is for external,
compressed data. EXTENDED is the default for all
data types that support it. The use of EXTERNAL will, for example,
make substring operations on a \fBtext\fR column faster, at the penalty of
increased storage space.
.TP
\fBSET WITHOUT OIDS\fR
This form removes the oid column from the
table. Removing OIDs from a table does not occur immediately.
The space that the OID uses will be reclaimed when the row is
updated. Without updating the row, both the space and the value
of the OID are kept indefinitely. This is semantically similar
to the DROP COLUMN process.
.TP
\fBRENAME\fR
The RENAME forms change the name of a table
(or an index, sequence, or view) or the name of an individual column in
a table. There is no effect on the stored data.
.TP
\fBADD \fItable_constraint\fB\fR
This form adds a new constraint to a table using the same syntax as
CREATE TABLE [\fBcreate_table\fR(l)]. 
.TP
\fBDROP CONSTRAINT\fR
This form drops constraints on a table.
Currently, constraints on tables are not required to have unique
names, so there may be more than one constraint matching the specified
name. All such constraints will be dropped.
.TP
\fBOWNER\fR
This form changes the owner of the table, index, sequence, or view to the
specified user.
.TP
\fBCLUSTER\fR
This form marks a table for future CLUSTER [\fBcluster\fR(l)]
operations.
.PP
.PP
You must own the table to use \fBALTER TABLE\fR; except for
\fBALTER TABLE OWNER\fR, which may only be executed by a superuser.
.SH "PARAMETERS"
.TP
\fB\fIname\fB\fR
The name (possibly schema-qualified) of an existing table to
alter. If ONLY is specified, only that table is
altered. If ONLY is not specified, the table and all
its descendant tables (if any) are updated. * can be
appended to the table name to indicate that descendant tables are
to be altered, but in the current version, this is the default
behavior. (In releases before 7.1, ONLY was the
default behavior. The default can be altered by changing the
configuration parameter sql_inheritance.)
.TP
\fB\fIcolumn\fB\fR
Name of a new or existing column.
.TP
\fB\fItype\fB\fR
Data type of the new column.
.TP
\fB\fInew_column\fB\fR
New name for an existing column.
.TP
\fB\fInew_name\fB\fR
New name for the table.
.TP
\fB\fItable_constraint\fB\fR
New table constraint for the table.
.TP
\fB\fIconstraint_name\fB\fR
Name of an existing constraint to drop.
.TP
\fB\fInew_owner\fB\fR
The user name of the new owner of the table.
.TP
\fB\fIindex_name\fB\fR
The index name on which the table should be marked for clustering.
.TP
\fBCASCADE\fR
Automatically drop objects that depend on the dropped column
or constraint (for example, views referencing the column).
.TP
\fBRESTRICT\fR
Refuse to drop the column or constraint if there are any dependent
objects. This is the default behavior.
.SH "NOTES"
.PP
The key word COLUMN is noise and can be omitted.
.PP
In the current implementation of ADD COLUMN,
default and NOT NULL clauses for the new column are not supported.
The new column always comes into being with all values null.
You can use the SET DEFAULT form
of \fBALTER TABLE\fR to set the default afterward.
(You may also want to update the already existing rows to the
new default value, using
UPDATE [\fBupdate\fR(l)].)
If you want to mark the column non-null, use the SET NOT NULL
form after you've entered non-null values for the column in all rows.
.PP
The DROP COLUMN form does not physically remove
the column, but simply makes it invisible to SQL operations. Subsequent
insert and update operations in the table will store a null value for the column.
Thus, dropping a column is quick but it will not immediately reduce the
on-disk size of your table, as the space occupied 
by the dropped column is not reclaimed. The space will be
reclaimed over time as existing rows are updated.
To reclaim the space at once, do a dummy \fBUPDATE\fR of all rows
and then vacuum, as in:
.sp
.nf
UPDATE table SET col = col;
VACUUM FULL table;
.sp
.fi
.PP
If a table has any descendant tables, it is not permitted to add
or rename a column in the parent table without doing the same to
the descendants. That is, \fBALTER TABLE ONLY\fR
will be rejected. This ensures that the descendants always have
columns matching the parent.
.PP
A recursive DROP COLUMN operation will remove a
descendant table's column only if the descendant does not inherit
that column from any other parents and never had an independent
definition of the column. A nonrecursive DROP
COLUMN (i.e., \fBALTER TABLE ONLY ... DROP
COLUMN\fR) never removes any descendant columns, but
instead marks them as independently defined rather than inherited.
.PP
Changing any part of a system catalog table is not permitted.
.PP
Refer to \fBCREATE TABLE\fR for a further description
of valid parameters. The chapter called ``Data Definition'' in the documentation has further information on
inheritance.
.SH "EXAMPLES"
.PP
To add a column of type \fBvarchar\fR to a table:
.sp
.nf
ALTER TABLE distributors ADD COLUMN address varchar(30);
.sp
.fi
.PP
To drop a column from a table:
.sp
.nf
ALTER TABLE distributors DROP COLUMN address RESTRICT;
.sp
.fi
.PP
To rename an existing column:
.sp
.nf
ALTER TABLE distributors RENAME COLUMN address TO city;
.sp
.fi
.PP
To rename an existing table:
.sp
.nf
ALTER TABLE distributors RENAME TO suppliers;
.sp
.fi
.PP
To add a not-null constraint to a column:
.sp
.nf
ALTER TABLE distributors ALTER COLUMN street SET NOT NULL;
.sp
.fi
To remove a not-null constraint from a column:
.sp
.nf
ALTER TABLE distributors ALTER COLUMN street DROP NOT NULL;
.sp
.fi
.PP
To add a check constraint to a table:
.sp
.nf
ALTER TABLE distributors ADD CONSTRAINT zipchk CHECK (char_length(zipcode) = 5);
.sp
.fi
.PP
To remove a check constraint from a table and all its children:
.sp
.nf
ALTER TABLE distributors DROP CONSTRAINT zipchk;
.sp
.fi
.PP
To add a foreign key constraint to a table:
.sp
.nf
ALTER TABLE distributors ADD CONSTRAINT distfk FOREIGN KEY (address) REFERENCES addresses (address) MATCH FULL;
.sp
.fi
.PP
To add a (multicolumn) unique constraint to a table:
.sp
.nf
ALTER TABLE distributors ADD CONSTRAINT dist_id_zipcode_key UNIQUE (dist_id, zipcode);
.sp
.fi
.PP
To add an automatically named primary key constraint to a table, noting
that a table can only ever have one primary key:
.sp
.nf
ALTER TABLE distributors ADD PRIMARY KEY (dist_id);
.sp
.fi
.SH "COMPATIBILITY"
.PP
The ADD COLUMN form conforms with the SQL
standard, with the exception that it does not support defaults and
not-null constraints, as explained above. The ALTER
COLUMN form is in full conformance.
.PP
The clauses to rename tables, columns, indexes, views, and sequences are
PostgreSQL extensions of the SQL standard.
.PP
\fBALTER TABLE DROP COLUMN\fR can be used to drop the only
column of a table, leaving a zero-column table. This is an
extension of SQL, which disallows zero-column tables.