/* A Bison parser, made by GNU Bison 1.875.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     SQL_ALLOCATE = 258,
     SQL_AUTOCOMMIT = 259,
     SQL_BOOL = 260,
     SQL_BREAK = 261,
     SQL_CALL = 262,
     SQL_CARDINALITY = 263,
     SQL_CONNECT = 264,
     SQL_CONNECTION = 265,
     SQL_CONTINUE = 266,
     SQL_COUNT = 267,
     SQL_CURRENT = 268,
     SQL_DATA = 269,
     SQL_DATETIME_INTERVAL_CODE = 270,
     SQL_DATETIME_INTERVAL_PRECISION = 271,
     SQL_DESCRIBE = 272,
     SQL_DESCRIPTOR = 273,
     SQL_DISCONNECT = 274,
     SQL_ENUM = 275,
     SQL_FOUND = 276,
     SQL_FREE = 277,
     SQL_GO = 278,
     SQL_GOTO = 279,
     SQL_IDENTIFIED = 280,
     SQL_INDICATOR = 281,
     SQL_KEY_MEMBER = 282,
     SQL_LENGTH = 283,
     SQL_LONG = 284,
     SQL_NAME = 285,
     SQL_NULLABLE = 286,
     SQL_OCTET_LENGTH = 287,
     SQL_OPEN = 288,
     SQL_OUTPUT = 289,
     SQL_RELEASE = 290,
     SQL_REFERENCE = 291,
     SQL_RETURNED_LENGTH = 292,
     SQL_RETURNED_OCTET_LENGTH = 293,
     SQL_SCALE = 294,
     SQL_SECTION = 295,
     SQL_SHORT = 296,
     SQL_SIGNED = 297,
     SQL_SQL = 298,
     SQL_SQLERROR = 299,
     SQL_SQLPRINT = 300,
     SQL_SQLWARNING = 301,
     SQL_START = 302,
     SQL_STOP = 303,
     SQL_STRUCT = 304,
     SQL_UNSIGNED = 305,
     SQL_VALUE = 306,
     SQL_VAR = 307,
     SQL_WHENEVER = 308,
     S_ADD = 309,
     S_AND = 310,
     S_ANYTHING = 311,
     S_AUTO = 312,
     S_CONST = 313,
     S_DEC = 314,
     S_DIV = 315,
     S_DOTPOINT = 316,
     S_EQUAL = 317,
     S_EXTERN = 318,
     S_INC = 319,
     S_LSHIFT = 320,
     S_MEMPOINT = 321,
     S_MEMBER = 322,
     S_MOD = 323,
     S_MUL = 324,
     S_NEQUAL = 325,
     S_OR = 326,
     S_REGISTER = 327,
     S_RSHIFT = 328,
     S_STATIC = 329,
     S_SUB = 330,
     S_VOLATILE = 331,
     S_TYPEDEF = 332,
     TYPECAST = 333,
     ABORT_P = 334,
     ABSOLUTE_P = 335,
     ACCESS = 336,
     ACTION = 337,
     ADD = 338,
     AFTER = 339,
     AGGREGATE = 340,
     ALL = 341,
     ALTER = 342,
     ANALYSE = 343,
     ANALYZE = 344,
     AND = 345,
     ANY = 346,
     ARRAY = 347,
     AS = 348,
     ASC = 349,
     ASSERTION = 350,
     ASSIGNMENT = 351,
     AT = 352,
     AUTHORIZATION = 353,
     BACKWARD = 354,
     BEFORE = 355,
     BEGIN_P = 356,
     BETWEEN = 357,
     BIGINT = 358,
     BINARY = 359,
     BIT = 360,
     BOOLEAN_P = 361,
     BOTH = 362,
     BY = 363,
     CACHE = 364,
     CALLED = 365,
     CASCADE = 366,
     CASE = 367,
     CAST = 368,
     CHAIN = 369,
     CHAR_P = 370,
     CHARACTER = 371,
     CHARACTERISTICS = 372,
     CHECK = 373,
     CHECKPOINT = 374,
     CLASS = 375,
     CLOSE = 376,
     CLUSTER = 377,
     COALESCE = 378,
     COLLATE = 379,
     COLUMN = 380,
     COMMENT = 381,
     COMMIT = 382,
     COMMITTED = 383,
     CONSTRAINT = 384,
     CONSTRAINTS = 385,
     CONVERSION_P = 386,
     CONVERT = 387,
     COPY = 388,
     CREATE = 389,
     CREATEDB = 390,
     CREATEUSER = 391,
     CROSS = 392,
     CURRENT_DATE = 393,
     CURRENT_TIME = 394,
     CURRENT_TIMESTAMP = 395,
     CURRENT_USER = 396,
     CURSOR = 397,
     CYCLE = 398,
     DATABASE = 399,
     DAY_P = 400,
     DEALLOCATE = 401,
     DEC = 402,
     DECIMAL_P = 403,
     DECLARE = 404,
     DEFAULT = 405,
     DEFAULTS = 406,
     DEFERRABLE = 407,
     DEFERRED = 408,
     DEFINER = 409,
     DELETE_P = 410,
     DELIMITER = 411,
     DELIMITERS = 412,
     DESC = 413,
     DISTINCT = 414,
     DO = 415,
     DOMAIN_P = 416,
     DOUBLE_P = 417,
     DROP = 418,
     EACH = 419,
     ELSE = 420,
     ENCODING = 421,
     ENCRYPTED = 422,
     END_P = 423,
     ESCAPE = 424,
     EXCEPT = 425,
     EXCLUSIVE = 426,
     EXCLUDING = 427,
     EXECUTE = 428,
     EXISTS = 429,
     EXPLAIN = 430,
     EXTERNAL = 431,
     EXTRACT = 432,
     FALSE_P = 433,
     FETCH = 434,
     FIRST_P = 435,
     FLOAT_P = 436,
     FOR = 437,
     FORCE = 438,
     FOREIGN = 439,
     FORWARD = 440,
     FREEZE = 441,
     FROM = 442,
     FULL = 443,
     FUNCTION = 444,
     GET = 445,
     GLOBAL = 446,
     GRANT = 447,
     GROUP_P = 448,
     HANDLER = 449,
     HAVING = 450,
     HOLD = 451,
     HOUR_P = 452,
     ILIKE = 453,
     IMMEDIATE = 454,
     IMMUTABLE = 455,
     IMPLICIT_P = 456,
     IN_P = 457,
     INCLUDING = 458,
     INCREMENT = 459,
     INDEX = 460,
     INHERITS = 461,
     INITIALLY = 462,
     INNER_P = 463,
     INOUT = 464,
     INPUT_P = 465,
     INSENSITIVE = 466,
     INSERT = 467,
     INSTEAD = 468,
     INT_P = 469,
     INTEGER = 470,
     INTERSECT = 471,
     INTERVAL = 472,
     INTO = 473,
     INVOKER = 474,
     IS = 475,
     ISNULL = 476,
     ISOLATION = 477,
     JOIN = 478,
     KEY = 479,
     LANCOMPILER = 480,
     LANGUAGE = 481,
     LAST_P = 482,
     LEADING = 483,
     LEFT = 484,
     LEVEL = 485,
     LIKE = 486,
     LIMIT = 487,
     LISTEN = 488,
     LOAD = 489,
     LOCAL = 490,
     LOCATION = 491,
     LOCK_P = 492,
     MATCH = 493,
     MAXVALUE = 494,
     MINUTE_P = 495,
     MINVALUE = 496,
     MODE = 497,
     MONTH_P = 498,
     MOVE = 499,
     NAMES = 500,
     NATIONAL = 501,
     NATURAL = 502,
     NCHAR = 503,
     NEW = 504,
     NEXT = 505,
     NO = 506,
     NOCREATEDB = 507,
     NOCREATEUSER = 508,
     NONE = 509,
     NOT = 510,
     NOTHING = 511,
     NOTIFY = 512,
     NOTNULL = 513,
     NULL_P = 514,
     NULLIF = 515,
     NUMERIC = 516,
     OF = 517,
     OFF = 518,
     OFFSET = 519,
     OIDS = 520,
     OLD = 521,
     ON = 522,
     ONLY = 523,
     OPERATOR = 524,
     OPTION = 525,
     OR = 526,
     ORDER = 527,
     OUT_P = 528,
     OUTER_P = 529,
     OVERLAPS = 530,
     OVERLAY = 531,
     OWNER = 532,
     PARTIAL = 533,
     PASSWORD = 534,
     PATH_P = 535,
     PENDANT = 536,
     PLACING = 537,
     POSITION = 538,
     PRECISION = 539,
     PRESERVE = 540,
     PREPARE = 541,
     PRIMARY = 542,
     PRIOR = 543,
     PRIVILEGES = 544,
     PROCEDURAL = 545,
     PROCEDURE = 546,
     READ = 547,
     REAL = 548,
     RECHECK = 549,
     REFERENCES = 550,
     REINDEX = 551,
     RELATIVE_P = 552,
     RENAME = 553,
     REPLACE = 554,
     RESET = 555,
     RESTART = 556,
     RESTRICT = 557,
     RETURNS = 558,
     REVOKE = 559,
     RIGHT = 560,
     ROLLBACK = 561,
     ROW = 562,
     ROWS = 563,
     RULE = 564,
     SCHEMA = 565,
     SCROLL = 566,
     SECOND_P = 567,
     SECURITY = 568,
     SELECT = 569,
     SEQUENCE = 570,
     SERIALIZABLE = 571,
     SESSION = 572,
     SESSION_USER = 573,
     SET = 574,
     SETOF = 575,
     SHARE = 576,
     SHOW = 577,
     SIMILAR = 578,
     SIMPLE = 579,
     SMALLINT = 580,
     SOME = 581,
     STABLE = 582,
     START = 583,
     STATEMENT = 584,
     STATISTICS = 585,
     STDIN = 586,
     STDOUT = 587,
     STORAGE = 588,
     STRICT_P = 589,
     SUBSTRING = 590,
     SYSID = 591,
     TABLE = 592,
     TEMP = 593,
     TEMPLATE = 594,
     TEMPORARY = 595,
     THEN = 596,
     TIME = 597,
     TIMESTAMP = 598,
     TO = 599,
     TOAST = 600,
     TRAILING = 601,
     TRANSACTION = 602,
     TREAT = 603,
     TRIGGER = 604,
     TRIM = 605,
     TRUE_P = 606,
     TRUNCATE = 607,
     TRUSTED = 608,
     TYPE_P = 609,
     UNENCRYPTED = 610,
     UNION = 611,
     UNIQUE = 612,
     UNKNOWN = 613,
     UNLISTEN = 614,
     UNTIL = 615,
     UPDATE = 616,
     USAGE = 617,
     USER = 618,
     USING = 619,
     VACUUM = 620,
     VALID = 621,
     VALUES = 622,
     VARCHAR = 623,
     VARYING = 624,
     VERBOSE = 625,
     VERSION = 626,
     VIEW = 627,
     VOLATILE = 628,
     WHEN = 629,
     WHERE = 630,
     WITH = 631,
     WITHOUT = 632,
     WORK = 633,
     WRITE = 634,
     YEAR_P = 635,
     ZONE = 636,
     UNIONJOIN = 637,
     IDENT = 638,
     SCONST = 639,
     Op = 640,
     CSTRING = 641,
     CVARIABLE = 642,
     CPP_LINE = 643,
     IP = 644,
     BCONST = 645,
     XCONST = 646,
     ICONST = 647,
     PARAM = 648,
     FCONST = 649,
     POSTFIXOP = 650,
     UMINUS = 651
   };
#endif
#define SQL_ALLOCATE 258
#define SQL_AUTOCOMMIT 259
#define SQL_BOOL 260
#define SQL_BREAK 261
#define SQL_CALL 262
#define SQL_CARDINALITY 263
#define SQL_CONNECT 264
#define SQL_CONNECTION 265
#define SQL_CONTINUE 266
#define SQL_COUNT 267
#define SQL_CURRENT 268
#define SQL_DATA 269
#define SQL_DATETIME_INTERVAL_CODE 270
#define SQL_DATETIME_INTERVAL_PRECISION 271
#define SQL_DESCRIBE 272
#define SQL_DESCRIPTOR 273
#define SQL_DISCONNECT 274
#define SQL_ENUM 275
#define SQL_FOUND 276
#define SQL_FREE 277
#define SQL_GO 278
#define SQL_GOTO 279
#define SQL_IDENTIFIED 280
#define SQL_INDICATOR 281
#define SQL_KEY_MEMBER 282
#define SQL_LENGTH 283
#define SQL_LONG 284
#define SQL_NAME 285
#define SQL_NULLABLE 286
#define SQL_OCTET_LENGTH 287
#define SQL_OPEN 288
#define SQL_OUTPUT 289
#define SQL_RELEASE 290
#define SQL_REFERENCE 291
#define SQL_RETURNED_LENGTH 292
#define SQL_RETURNED_OCTET_LENGTH 293
#define SQL_SCALE 294
#define SQL_SECTION 295
#define SQL_SHORT 296
#define SQL_SIGNED 297
#define SQL_SQL 298
#define SQL_SQLERROR 299
#define SQL_SQLPRINT 300
#define SQL_SQLWARNING 301
#define SQL_START 302
#define SQL_STOP 303
#define SQL_STRUCT 304
#define SQL_UNSIGNED 305
#define SQL_VALUE 306
#define SQL_VAR 307
#define SQL_WHENEVER 308
#define S_ADD 309
#define S_AND 310
#define S_ANYTHING 311
#define S_AUTO 312
#define S_CONST 313
#define S_DEC 314
#define S_DIV 315
#define S_DOTPOINT 316
#define S_EQUAL 317
#define S_EXTERN 318
#define S_INC 319
#define S_LSHIFT 320
#define S_MEMPOINT 321
#define S_MEMBER 322
#define S_MOD 323
#define S_MUL 324
#define S_NEQUAL 325
#define S_OR 326
#define S_REGISTER 327
#define S_RSHIFT 328
#define S_STATIC 329
#define S_SUB 330
#define S_VOLATILE 331
#define S_TYPEDEF 332
#define TYPECAST 333
#define ABORT_P 334
#define ABSOLUTE_P 335
#define ACCESS 336
#define ACTION 337
#define ADD 338
#define AFTER 339
#define AGGREGATE 340
#define ALL 341
#define ALTER 342
#define ANALYSE 343
#define ANALYZE 344
#define AND 345
#define ANY 346
#define ARRAY 347
#define AS 348
#define ASC 349
#define ASSERTION 350
#define ASSIGNMENT 351
#define AT 352
#define AUTHORIZATION 353
#define BACKWARD 354
#define BEFORE 355
#define BEGIN_P 356
#define BETWEEN 357
#define BIGINT 358
#define BINARY 359
#define BIT 360
#define BOOLEAN_P 361
#define BOTH 362
#define BY 363
#define CACHE 364
#define CALLED 365
#define CASCADE 366
#define CASE 367
#define CAST 368
#define CHAIN 369
#define CHAR_P 370
#define CHARACTER 371
#define CHARACTERISTICS 372
#define CHECK 373
#define CHECKPOINT 374
#define CLASS 375
#define CLOSE 376
#define CLUSTER 377
#define COALESCE 378
#define COLLATE 379
#define COLUMN 380
#define COMMENT 381
#define COMMIT 382
#define COMMITTED 383
#define CONSTRAINT 384
#define CONSTRAINTS 385
#define CONVERSION_P 386
#define CONVERT 387
#define COPY 388
#define CREATE 389
#define CREATEDB 390
#define CREATEUSER 391
#define CROSS 392
#define CURRENT_DATE 393
#define CURRENT_TIME 394
#define CURRENT_TIMESTAMP 395
#define CURRENT_USER 396
#define CURSOR 397
#define CYCLE 398
#define DATABASE 399
#define DAY_P 400
#define DEALLOCATE 401
#define DEC 402
#define DECIMAL_P 403
#define DECLARE 404
#define DEFAULT 405
#define DEFAULTS 406
#define DEFERRABLE 407
#define DEFERRED 408
#define DEFINER 409
#define DELETE_P 410
#define DELIMITER 411
#define DELIMITERS 412
#define DESC 413
#define DISTINCT 414
#define DO 415
#define DOMAIN_P 416
#define DOUBLE_P 417
#define DROP 418
#define EACH 419
#define ELSE 420
#define ENCODING 421
#define ENCRYPTED 422
#define END_P 423
#define ESCAPE 424
#define EXCEPT 425
#define EXCLUSIVE 426
#define EXCLUDING 427
#define EXECUTE 428
#define EXISTS 429
#define EXPLAIN 430
#define EXTERNAL 431
#define EXTRACT 432
#define FALSE_P 433
#define FETCH 434
#define FIRST_P 435
#define FLOAT_P 436
#define FOR 437
#define FORCE 438
#define FOREIGN 439
#define FORWARD 440
#define FREEZE 441
#define FROM 442
#define FULL 443
#define FUNCTION 444
#define GET 445
#define GLOBAL 446
#define GRANT 447
#define GROUP_P 448
#define HANDLER 449
#define HAVING 450
#define HOLD 451
#define HOUR_P 452
#define ILIKE 453
#define IMMEDIATE 454
#define IMMUTABLE 455
#define IMPLICIT_P 456
#define IN_P 457
#define INCLUDING 458
#define INCREMENT 459
#define INDEX 460
#define INHERITS 461
#define INITIALLY 462
#define INNER_P 463
#define INOUT 464
#define INPUT_P 465
#define INSENSITIVE 466
#define INSERT 467
#define INSTEAD 468
#define INT_P 469
#define INTEGER 470
#define INTERSECT 471
#define INTERVAL 472
#define INTO 473
#define INVOKER 474
#define IS 475
#define ISNULL 476
#define ISOLATION 477
#define JOIN 478
#define KEY 479
#define LANCOMPILER 480
#define LANGUAGE 481
#define LAST_P 482
#define LEADING 483
#define LEFT 484
#define LEVEL 485
#define LIKE 486
#define LIMIT 487
#define LISTEN 488
#define LOAD 489
#define LOCAL 490
#define LOCATION 491
#define LOCK_P 492
#define MATCH 493
#define MAXVALUE 494
#define MINUTE_P 495
#define MINVALUE 496
#define MODE 497
#define MONTH_P 498
#define MOVE 499
#define NAMES 500
#define NATIONAL 501
#define NATURAL 502
#define NCHAR 503
#define NEW 504
#define NEXT 505
#define NO 506
#define NOCREATEDB 507
#define NOCREATEUSER 508
#define NONE 509
#define NOT 510
#define NOTHING 511
#define NOTIFY 512
#define NOTNULL 513
#define NULL_P 514
#define NULLIF 515
#define NUMERIC 516
#define OF 517
#define OFF 518
#define OFFSET 519
#define OIDS 520
#define OLD 521
#define ON 522
#define ONLY 523
#define OPERATOR 524
#define OPTION 525
#define OR 526
#define ORDER 527
#define OUT_P 528
#define OUTER_P 529
#define OVERLAPS 530
#define OVERLAY 531
#define OWNER 532
#define PARTIAL 533
#define PASSWORD 534
#define PATH_P 535
#define PENDANT 536
#define PLACING 537
#define POSITION 538
#define PRECISION 539
#define PRESERVE 540
#define PREPARE 541
#define PRIMARY 542
#define PRIOR 543
#define PRIVILEGES 544
#define PROCEDURAL 545
#define PROCEDURE 546
#define READ 547
#define REAL 548
#define RECHECK 549
#define REFERENCES 550
#define REINDEX 551
#define RELATIVE_P 552
#define RENAME 553
#define REPLACE 554
#define RESET 555
#define RESTART 556
#define RESTRICT 557
#define RETURNS 558
#define REVOKE 559
#define RIGHT 560
#define ROLLBACK 561
#define ROW 562
#define ROWS 563
#define RULE 564
#define SCHEMA 565
#define SCROLL 566
#define SECOND_P 567
#define SECURITY 568
#define SELECT 569
#define SEQUENCE 570
#define SERIALIZABLE 571
#define SESSION 572
#define SESSION_USER 573
#define SET 574
#define SETOF 575
#define SHARE 576
#define SHOW 577
#define SIMILAR 578
#define SIMPLE 579
#define SMALLINT 580
#define SOME 581
#define STABLE 582
#define START 583
#define STATEMENT 584
#define STATISTICS 585
#define STDIN 586
#define STDOUT 587
#define STORAGE 588
#define STRICT_P 589
#define SUBSTRING 590
#define SYSID 591
#define TABLE 592
#define TEMP 593
#define TEMPLATE 594
#define TEMPORARY 595
#define THEN 596
#define TIME 597
#define TIMESTAMP 598
#define TO 599
#define TOAST 600
#define TRAILING 601
#define TRANSACTION 602
#define TREAT 603
#define TRIGGER 604
#define TRIM 605
#define TRUE_P 606
#define TRUNCATE 607
#define TRUSTED 608
#define TYPE_P 609
#define UNENCRYPTED 610
#define UNION 611
#define UNIQUE 612
#define UNKNOWN 613
#define UNLISTEN 614
#define UNTIL 615
#define UPDATE 616
#define USAGE 617
#define USER 618
#define USING 619
#define VACUUM 620
#define VALID 621
#define VALUES 622
#define VARCHAR 623
#define VARYING 624
#define VERBOSE 625
#define VERSION 626
#define VIEW 627
#define VOLATILE 628
#define WHEN 629
#define WHERE 630
#define WITH 631
#define WITHOUT 632
#define WORK 633
#define WRITE 634
#define YEAR_P 635
#define ZONE 636
#define UNIONJOIN 637
#define IDENT 638
#define SCONST 639
#define Op 640
#define CSTRING 641
#define CVARIABLE 642
#define CPP_LINE 643
#define IP 644
#define BCONST 645
#define XCONST 646
#define ICONST 647
#define PARAM 648
#define FCONST 649
#define POSTFIXOP 650
#define UMINUS 651




#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 284 "preproc.y"
typedef union YYSTYPE {
	double	dval;
	char	*str;
	int     ival;
	struct	when		action;
	struct	index		index;
	int		tagname;
	struct	this_type	type;
	enum	ECPGttype	type_enum;
	enum	ECPGdtype	dtype_enum;
	struct	fetch_desc	descriptor;
	struct  su_symbol	struct_union;
} YYSTYPE;
/* Line 1248 of yacc.c.  */
#line 842 "y.tab.h"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;



