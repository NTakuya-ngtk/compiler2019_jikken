/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

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
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     SBEGIN = 258,
     DO = 259,
     ELSE = 260,
     SEND = 261,
     FOR = 262,
     FORWARD = 263,
     FUNCTION = 264,
     IF = 265,
     PROCEDURE = 266,
     PROGRAM = 267,
     READ = 268,
     THEN = 269,
     TO = 270,
     VAR = 271,
     WHILE = 272,
     WRITE = 273,
     MINUS = 274,
     PLUS = 275,
     DIV = 276,
     MULT = 277,
     EQ = 278,
     NEQ = 279,
     LE = 280,
     LT = 281,
     GE = 282,
     GT = 283,
     LPAREN = 284,
     RPAREN = 285,
     LBRACKET = 286,
     RBRACKET = 287,
     COMMA = 288,
     SEMICOLON = 289,
     COLON = 290,
     INTERVAL = 291,
     PERIOD = 292,
     ASSIGN = 293,
     NUMBER = 294,
     IDENT = 295
   };
#endif
/* Tokens.  */
#define SBEGIN 258
#define DO 259
#define ELSE 260
#define SEND 261
#define FOR 262
#define FORWARD 263
#define FUNCTION 264
#define IF 265
#define PROCEDURE 266
#define PROGRAM 267
#define READ 268
#define THEN 269
#define TO 270
#define VAR 271
#define WHILE 272
#define WRITE 273
#define MINUS 274
#define PLUS 275
#define DIV 276
#define MULT 277
#define EQ 278
#define NEQ 279
#define LE 280
#define LT 281
#define GE 282
#define GT 283
#define LPAREN 284
#define RPAREN 285
#define LBRACKET 286
#define RBRACKET 287
#define COMMA 288
#define SEMICOLON 289
#define COLON 290
#define INTERVAL 291
#define PERIOD 292
#define ASSIGN 293
#define NUMBER 294
#define IDENT 295




/* Copy the first part of user declarations.  */
#line 1 "parser.y"

/*
 * parser; Parser for PL-*
 */

#define MAXLENGTH 16

#include <stdio.h>
#include <string.h>
#include "table.h"
#include "table.c"
#include "createllvm.h"
#include "createllvm.c"

  extern int yylineno;
  extern char *yytext;

	Scope flag = GLOBAL_VAR;
	//init_fstack();  // スタックの初期化を行う
       int cnrt = 0;     // レジスタ番号
extern int readflag;
extern int writeflag;
       int procArgCount = 0;
       int procArgFlag = 0;
       int callCount;
	


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 29 "parser.y"
{
    int num;
    char ident[MAXLENGTH+1];
}
/* Line 193 of yacc.c.  */
#line 209 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 222 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   110

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  80
/* YYNRULES -- Number of states.  */
#define YYNSTATES  140

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     4,     5,     6,    15,    19,    20,    23,
      27,    29,    32,    33,    36,    40,    42,    44,    49,    57,
      58,    61,    62,    66,    70,    72,    74,    76,    78,    80,
      82,    84,    86,    88,    90,    94,    95,    96,   104,   105,
     109,   110,   111,   112,   119,   120,   121,   132,   134,   135,
     141,   143,   147,   152,   157,   158,   162,   166,   170,   174,
     178,   182,   184,   187,   190,   194,   198,   200,   204,   208,
     210,   212,   216,   218,   220,   224,   225,   228,   229,   234,
     236
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      42,     0,    -1,    -1,    -1,    -1,    43,    12,    40,    44,
      34,    46,    45,    37,    -1,    47,    50,    59,    -1,    -1,
      48,    34,    -1,    48,    34,    49,    -1,    49,    -1,    16,
      85,    -1,    -1,    51,    34,    -1,    51,    34,    52,    -1,
      52,    -1,    53,    -1,    11,    54,    34,    56,    -1,    11,
      54,    29,    88,    30,    34,    56,    -1,    -1,    40,    55,
      -1,    -1,    57,    47,    59,    -1,    58,    34,    59,    -1,
      59,    -1,    60,    -1,    61,    -1,    66,    -1,    69,    -1,
      72,    -1,    78,    -1,    75,    -1,    76,    -1,    77,    -1,
      40,    38,    80,    -1,    -1,    -1,    10,    79,    62,    14,
      63,    59,    64,    -1,    -1,     5,    65,    59,    -1,    -1,
      -1,    -1,    17,    67,    79,    68,     4,    59,    -1,    -1,
      -1,     7,    40,    38,    80,    70,    15,    80,    71,     4,
      59,    -1,    74,    -1,    -1,    74,    29,    73,    84,    30,
      -1,    40,    -1,     3,    58,     6,    -1,    13,    29,    40,
      30,    -1,    18,    29,    80,    30,    -1,    -1,    80,    23,
      80,    -1,    80,    24,    80,    -1,    80,    26,    80,    -1,
      80,    25,    80,    -1,    80,    28,    80,    -1,    80,    27,
      80,    -1,    81,    -1,    20,    81,    -1,    19,    81,    -1,
      80,    20,    81,    -1,    80,    19,    81,    -1,    82,    -1,
      81,    22,    82,    -1,    81,    21,    82,    -1,    83,    -1,
      39,    -1,    29,    80,    30,    -1,    40,    -1,    80,    -1,
      84,    33,    80,    -1,    -1,    40,    86,    -1,    -1,    85,
      33,    40,    87,    -1,    40,    -1,    88,    33,    40,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    52,    52,    59,    72,    52,    98,   101,   103,   107,
     108,   112,   118,   187,   260,   261,   265,   269,   270,   274,
     274,   357,   357,   376,   377,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   393,   424,   448,   423,   474,   474,
     564,   612,   646,   611,   732,   783,   731,   977,   978,   978,
     983,  1000,  1004,  1028,  1051,  1056,  1089,  1121,  1153,  1185,
    1217,  1252,  1253,  1254,  1255,  1280,  1309,  1310,  1334,  1361,
    1362,  1379,  1383,  1436,  1437,  1441,  1441,  1483,  1483,  1523,
    1571
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SBEGIN", "DO", "ELSE", "SEND", "FOR",
  "FORWARD", "FUNCTION", "IF", "PROCEDURE", "PROGRAM", "READ", "THEN",
  "TO", "VAR", "WHILE", "WRITE", "MINUS", "PLUS", "DIV", "MULT", "EQ",
  "NEQ", "LE", "LT", "GE", "GT", "LPAREN", "RPAREN", "LBRACKET",
  "RBRACKET", "COMMA", "SEMICOLON", "COLON", "INTERVAL", "PERIOD",
  "ASSIGN", "NUMBER", "IDENT", "$accept", "program", "@1", "@2", "@3",
  "outblock", "var_decl_part", "var_decl_list", "var_decl",
  "subprog_decl_part", "subprog_decl_list", "subprog_decl", "proc_decl",
  "proc_name", "@4", "inblock", "@5", "statement_list", "statement",
  "assignment_statement", "if_statement", "@6", "@7", "else_statement",
  "@8", "while_statement", "@9", "@10", "for_statement", "@11", "@12",
  "proc_call_statement", "@13", "proc_call_name", "block_statement",
  "read_statement", "write_statement", "null_statement", "condition",
  "expression", "term", "factor", "var_name", "arg_list", "id_list", "@14",
  "@15", "proc_id_list", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    43,    44,    45,    42,    46,    47,    47,    48,
      48,    49,    50,    50,    51,    51,    52,    53,    53,    55,
      54,    57,    56,    58,    58,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    60,    62,    63,    61,    65,    64,
      64,    67,    68,    66,    70,    71,    69,    72,    73,    72,
      74,    75,    76,    77,    78,    79,    79,    79,    79,    79,
      79,    80,    80,    80,    80,    80,    81,    81,    81,    82,
      82,    82,    83,    84,    84,    86,    85,    87,    85,    88,
      88
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     0,     8,     3,     0,     2,     3,
       1,     2,     0,     2,     3,     1,     1,     4,     7,     0,
       2,     0,     3,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     0,     0,     7,     0,     3,
       0,     0,     0,     6,     0,     0,    10,     1,     0,     5,
       1,     3,     4,     4,     0,     3,     3,     3,     3,     3,
       3,     1,     2,     2,     3,     3,     1,     3,     3,     1,
       1,     3,     1,     1,     3,     0,     2,     0,     4,     1,
       3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,     0,     3,     0,     7,     0,     4,
      12,     0,    10,    75,    11,     0,     0,    54,     0,    15,
      16,     8,    76,     0,     5,    19,     0,    54,     0,     0,
       0,    41,     0,    50,     6,    25,    26,    27,    28,    29,
      47,    31,    32,    33,    30,    13,     9,    77,    20,     0,
      21,     0,    24,     0,     0,     0,     0,    70,    72,    35,
       0,    61,    66,    69,     0,     0,     0,     0,    48,    14,
      78,    79,     0,    17,     7,    51,    54,     0,    63,    62,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    42,     0,    34,     0,     0,     0,    54,
      23,    44,    71,    36,    65,    64,    55,    56,    58,    57,
      60,    59,    68,    67,    52,     0,    53,    73,     0,    21,
      80,    22,     0,    54,    54,    49,     0,    18,     0,    40,
      43,    74,    45,    38,    37,     0,    54,    54,    39,    46
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     6,    15,     9,    10,    11,    12,    17,
      18,    19,    20,    26,    48,    73,    74,    51,    34,    35,
      36,    81,   123,   134,   136,    37,    65,   115,    38,   122,
     135,    39,    96,    40,    41,    42,    43,    44,    59,    60,
      61,    62,    63,   118,    14,    22,    70,    72
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -56
static const yytype_int8 yypact[] =
{
     -56,     2,    -8,   -56,   -21,   -56,     1,    39,    19,   -56,
      49,    33,   -56,   -56,    35,    32,    30,     0,    40,   -56,
     -56,    39,   -56,    36,   -56,   -56,   -13,     0,    37,   -14,
      46,   -56,    50,    42,   -56,   -56,   -56,   -56,   -56,   -56,
      52,   -56,   -56,   -56,   -56,    49,   -56,   -56,   -56,    43,
     -56,     8,   -56,    44,    -1,    -1,   -14,   -56,   -56,   -56,
      38,    29,   -56,   -56,    45,   -14,   -14,   -14,   -56,   -56,
     -56,   -56,   -10,   -56,    39,   -56,     0,   -14,    29,    29,
      24,    64,    -1,    -1,   -14,   -14,   -14,   -14,   -14,   -14,
      -1,    -1,    54,   -56,    26,    28,   -14,    53,    48,     0,
     -56,    28,   -56,   -56,    29,    29,    28,    28,    28,    28,
      28,    28,   -56,   -56,   -56,    82,   -56,    28,    -6,   -56,
     -56,   -56,    74,     0,     0,   -56,   -14,   -56,   -14,    85,
     -56,    28,    28,   -56,   -56,    87,     0,     0,   -56,   -56
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -56,   -56,   -56,   -56,   -56,   -56,    18,   -56,    72,   -56,
     -56,    55,   -56,   -56,   -56,   -25,   -56,   -56,   -27,   -56,
     -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,
     -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,    34,   -55,
     -46,   -38,   -56,   -56,   -56,   -56,   -56,   -56
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      52,    80,     3,    27,     4,    54,    55,    28,    78,    79,
      29,    94,    95,    30,    75,    56,    49,    31,    32,     5,
      97,    50,   101,    98,   125,    57,    58,   126,    56,   106,
     107,   108,   109,   110,   111,     7,   104,   105,    57,    58,
      33,   117,    76,    82,    83,    82,    83,    82,    83,   100,
      90,    91,   112,   113,   102,     8,   116,    82,    83,    13,
      16,    84,    85,    86,    87,    88,    89,    21,    23,    24,
      25,   131,   121,   132,    45,    64,    47,    53,   103,    66,
      67,    68,    77,    71,   114,    92,   124,   119,   120,   128,
     133,   137,    99,    46,   127,     0,   129,   130,     0,    93,
      69,     0,     0,     0,     0,     0,     0,     0,     0,   138,
     139
};

static const yytype_int16 yycheck[] =
{
      27,    56,     0,     3,    12,    19,    20,     7,    54,    55,
      10,    66,    67,    13,     6,    29,    29,    17,    18,    40,
      30,    34,    77,    33,    30,    39,    40,    33,    29,    84,
      85,    86,    87,    88,    89,    34,    82,    83,    39,    40,
      40,    96,    34,    19,    20,    19,    20,    19,    20,    76,
      21,    22,    90,    91,    30,    16,    30,    19,    20,    40,
      11,    23,    24,    25,    26,    27,    28,    34,    33,    37,
      40,   126,    99,   128,    34,    29,    40,    40,    14,    29,
      38,    29,    38,    40,    30,    40,     4,    34,    40,    15,
       5,     4,    74,    21,   119,    -1,   123,   124,    -1,    65,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,
     137
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    42,    43,     0,    12,    40,    44,    34,    16,    46,
      47,    48,    49,    40,    85,    45,    11,    50,    51,    52,
      53,    34,    86,    33,    37,    40,    54,     3,     7,    10,
      13,    17,    18,    40,    59,    60,    61,    66,    69,    72,
      74,    75,    76,    77,    78,    34,    49,    40,    55,    29,
      34,    58,    59,    40,    19,    20,    29,    39,    40,    79,
      80,    81,    82,    83,    29,    67,    29,    38,    29,    52,
      87,    40,    88,    56,    57,     6,    34,    38,    81,    81,
      80,    62,    19,    20,    23,    24,    25,    26,    27,    28,
      21,    22,    40,    79,    80,    80,    73,    30,    33,    47,
      59,    80,    30,    14,    81,    81,    80,    80,    80,    80,
      80,    80,    82,    82,    30,    68,    30,    80,    84,    34,
      40,    59,    70,    63,     4,    30,    33,    56,    15,    59,
      59,    80,    80,     5,    64,    71,    65,     4,    59,    59
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 52 "parser.y"
    {
                     /* 出力ファイルを書き込む部分 */
                     if((fp = fopen("result.ll","w")) == NULL){
                            fprintf(stderr, "result.llのオープンに失敗しました\n");
                            exit(1);
                     }
              }
    break;

  case 3:
#line 59 "parser.y"
    {      
                            // 大域変数を格納するfundeclを作るコード
                            Fundecl *new;
				new = (Fundecl *)malloc(sizeof(Fundecl)); //メモリを動的に確保
				new->next = NULL;

                             /* 線形リストのポインタを更新 */
                            declhd = new;
                            decltl = new;
                            
                            insert_data((yyvsp[(3) - (3)].ident),PROC_NAME,0);
                     }
    break;

  case 4:
#line 72 "parser.y"
    {
                            {  
                                   /* main関数からRetするコード*/
                                   LLVMcode* tmp;
                                   Factor arg1;

                                   tmp = memoryGet(tmp); 

                                   tmp->command=Ret;

                                   arg1.type = CONSTANT;
                                   arg1.val = 0; 

                                   (tmp->args).ret.arg1 = arg1;
                                   addList(tmp);
                                   }

                     }
    break;

  case 5:
#line 91 "parser.y"
    {      
	       	displayLLVMfundecl(declhd);
                     fclose(fp);
              }
    break;

  case 11:
#line 112 "parser.y"
    {
       }
    break;

  case 12:
#line 118 "parser.y"
    { // ここがメイン関数の入るところ
         
                                   Fundecl *mainfunc;
					mainfunc = (Fundecl *)malloc(sizeof(Fundecl)); //メモリを動的に確保
					mainfunc->next = NULL;
                                   

                                   // main関数のため，"main"を格納
					strcpy(mainfunc->fname,"main");
                                   mainfunc->ret = 1;

                                   /* 線形リストのポインタを更新 */
                                    if(decltl == NULL) {   /* 関数定義の線形リストの最初であるとき*/
                                          declhd = decltl = mainfunc;
                                   } else {             /* 関数定義の線形リストに1つ以上存在する時*/
                                          decltl->next = mainfunc;  // 関数定義列の末尾に*newを追加
                                          decltl = mainfunc;        // 関数定義列の末尾として*newを保存する
                                   }

                                   // decltl->next = mainfunc;  // 関数定義列の末尾に*newを追加
                                   // decltl = mainfunc;        // 関数定義列の末尾として*newを保存する

                                   /* codehdおよびcodetlのリセット */
                                   codehd = codetl = NULL;

                                   /* main関数をAllocaするコード*/
                                   LLVMcode* tmp;
                                   Factor retval;

                                   tmp = memoryGet(tmp); 

                                   tmp->command=Alloca;
                                   cnrt = 1; // cnrtの初期化を行う

                                   retval.type = LOCAL_VAR;
                                   retval.val = cnrt;
                                   cnrt++;

                                   (tmp->args).alloca.retval = retval;
                                   
                                   factorpush(retval);

                                   addList(tmp);

                                   /* ----------------- */

                                   /* main関数のコード番地をstoreするコード*/

                                   LLVMcode* tmp1;
                                   Factor arg1,arg2;

                                   tmp1 = memoryGet(tmp1); 

                                   tmp1->command=Store;

                                   arg2 = factorpop();  /* 局所変数%1を取り出す*/
                                   
                                   // strcpy(arg1.vname,$1);
                                   arg1.type = CONSTANT;
                                   arg1.val = 0; // 記号表の番地を代入する

                                   // factorpush(arg2);

                                   (tmp1->args).store.arg1 = arg1;
                                   (tmp1->args).store.arg2 = arg2;

                                   addList(tmp1);

       }
    break;

  case 13:
#line 187 "parser.y"
    { // ここがメイン関数の入るところ
         
					// printf("debug");
                                   Fundecl *mainfunc;
					mainfunc = (Fundecl *)malloc(sizeof(Fundecl)); //メモリを動的に確保
					mainfunc->next = NULL;
                                   
                                   mainfunc->ret = 1; // 返り値の数

                                   // main関数のため，"main"を格納
					strcpy(mainfunc->fname,"main");

                                   /* 線形リストのポインタを更新 */
                                    if(decltl == NULL) {   /* 関数定義の線形リストの最初であるとき*/
                                          declhd = decltl = mainfunc;
                                   } else {             /* 関数定義の線形リストに1つ以上存在する時*/
                                          decltl->next = mainfunc;  // 関数定義列の末尾に*newを追加
                                          decltl = mainfunc;        // 関数定義列の末尾として*newを保存する
                                   }

                                   // decltl->next = mainfunc;  // 関数定義列の末尾に*newを追加
                                   // decltl = mainfunc;        // 関数定義列の末尾として*newを保存する

                                   /* codehdおよびcodetlのリセット */
                                   codehd = codetl = NULL;

                                   /* main関数をAllocaするコード*/
                                   LLVMcode* tmp;
                                   Factor retval;

                                   tmp = memoryGet(tmp); 

                                   tmp->command=Alloca;
                                   cnrt = 1; // cnrtの初期化を行う

                                   retval.type = LOCAL_VAR;
                                   retval.val = cnrt;
                                   cnrt++;

                                   (tmp->args).alloca.retval = retval;
                                   
                                   factorpush(retval);

                                   addList(tmp);

                                   /* ----------------- */

                                   /* main関数のコード番地をstoreするコード*/

                                   LLVMcode* tmp1;
                                   Factor arg1,arg2;

                                   tmp1 = memoryGet(tmp1); 

                                   tmp1->command=Store;

                                   arg2 = factorpop();  /* 局所変数%1を取り出す*/
                                   
                                   // strcpy(arg1.vname,$1);
                                   arg1.type = CONSTANT;
                                   arg1.val = 0; // 記号表の番地を代入する

                                   // factorpush(arg2);

                                   (tmp1->args).store.arg1 = arg1;
                                   (tmp1->args).store.arg2 = arg2;

                                   addList(tmp1);

       }
    break;

  case 17:
#line 269 "parser.y"
    {delete_data();}
    break;

  case 18:
#line 270 "parser.y"
    {delete_data();}
    break;

  case 19:
#line 274 "parser.y"
    {flag = PROC_NAME; insert_data((yyvsp[(1) - (1)].ident),flag,0);}
    break;

  case 20:
#line 275 "parser.y"
    {

		                     /*-----------------------------------------------------*/

                                   /* 以下プログラム名から関数のLLVMコードを生成するCプログラム*/

					
                                   Fundecl *new;
                                   
					new = (Fundecl *)malloc(sizeof(Fundecl)); //メモリを動的に確保
					new->next = NULL;
                                   // 関数名等を保存
                                   strcpy(new->fname,(yyvsp[(1) - (2)].ident));
                                   new->ret = 0;
					                            
                                    /* 線形リストのポインタを更新 */
                                    if(decltl == NULL) {   /* 関数定義の線形リストの最初であるとき*/
                                          declhd = decltl = new;
                                   } else {             /* 関数定義の線形リストに1つ以上存在する時*/
                                          decltl->next = new;  // 関数定義列の末尾に*newを追加
                                          decltl = new;        // 関数定義列の末尾として*newを保存する
                                   
                                   }

                                   // 新しい関数列ができたので，codehdとcodetlをnullにする
                                   codehd = codetl = NULL;
                                   // decltl->next = new;  // 関数定義列の末尾に*newを追加
                                   // decltl = new;        // 関数定義列の末尾として*newを保存する

                                   cnrt = 1; // cnrtの初期化

                                   /* -------------------------------------- */
                                   /* procedureをAllocaするコード*/
                                   // LLVMcode* tmp;
                                   // Factor retval;

                                   // tmp = memoryGet(tmp); 

                                   // tmp->command=Alloca;

                                   // cnrt = 1; // cnrtの初期化を行う

                                   // etval.type = LOCAL_VAR;
                                   // retval.val = cnrt;
                                   // cnrt++;

                                   // (tmp->args).alloca.retval = retval;
                                   
                                   // factorpush(retval);

                                   // addList(tmp);

                                   /* ----------------- */

                                   /* prodecureのコード番地をstoreするコード*/

                                   // LLVMcode* tmp1;
                                   // Factor arg1,arg2;

                                   // tmp1 = memoryGet(tmp1); 

                                   // tmp1->command=Store;

                                   // arg2 = factorpop();  /* 局所変数%1を取り出す*/
                                   
                                   // strcpy(arg1.vname,$1);
                                   // arg1.type = CONSTANT;
                                   // arg1.val = 0;        /* 記号表の番地を代入する */       

                                   // factorpush(arg2);

                                   // (tmp1->args).store.arg1 = arg1;
                                   // (tmp1->args).store.arg2 = arg2;

                                   // addList(tmp1);
					/*-----------------------------------------------------*/		
                                  
					
                            }
    break;

  case 21:
#line 357 "parser.y"
    { flag = LOCAL_VAR; }
    break;

  case 22:
#line 359 "parser.y"
    {  
                                   /* procedureからRetするコード*/
                                   LLVMcode* tmp;
                                   Factor arg1;

                                   tmp = memoryGet(tmp); 

                                   tmp->command=Ret;

                                   arg1.type = LOCAL_VAR;

                                   (tmp->args).ret.arg1 = arg1;
                                   addList(tmp);
                                   }
    break;

  case 34:
#line 394 "parser.y"
    {
                                  /*変数引数をスタックからpopしてレジスタへ格納する ｜Store*/

                                   LLVMcode* tmp;
                                   Factor arg1,arg2;

                                   tmp = memoryGet(tmp); 

                                   tmp->command=Store;

                                   arg1 = factorpop(); 
                                    
                                   strcpy(arg2.vname,(yyvsp[(1) - (3)].ident));
                                   
                                   arg2 = lookup_data((yyvsp[(1) - (3)].ident));

                                   factorpush(arg2);

                                   (tmp->args).store.arg1 = arg1;
                                   (tmp->args).store.arg2 = arg2;

                                   addList(tmp);
                                   
                                   /*----------------------------*/
                            }
    break;

  case 35:
#line 424 "parser.y"
    {

                                   /* 制御文を記述する */ // | Brcond

                                   LLVMcode* tmp;
                                   Factor arg1;
                                   int arg2;

                                   tmp = memoryGet(tmp); 

                                   tmp->command=BrCond;

                                   arg1 = factorpop();
                                   arg2 = cnrt;

                                   (tmp->args).brcond.arg1 = arg1;
                                   (tmp->args).brcond.arg2 = arg2;

                                   addList(tmp);
                                   brpush(tmp);
                                   
                                   /*----------------------------*/
                     }
    break;

  case 36:
#line 448 "parser.y"
    {

                                   /* 制御文を記述する */  // | Label

                                   LLVMcode* tmp;
                                   int l;

                                   tmp = memoryGet(tmp); 

                                   tmp->command=Label;

                                   l = cnrt;
                                   cnrt++;

                                   (tmp->args).label.l = l;

                                   addList(tmp);
                                   /*----------------------------*/
                     }
    break;

  case 38:
#line 474 "parser.y"
    {

                                   
                                   /* 制御文を記述する */ // | BrUncond 

                                   LLVMcode* tmp1;
                                   int arg1;

                                   tmp1 = memoryGet(tmp1); 

                                   tmp1->command=BrUncond;

                                   addList(tmp1);


                                    /* 制御文を記述する */  // | Label

                                   LLVMcode* tmp2;
                                   int l;

                                   tmp2 = memoryGet(tmp2); 

                                   tmp2->command=Label;

                                   l = cnrt;
                                   cnrt++;

                                   (tmp2->args).label.l = l;

                                   addList(tmp2);

                                   // brスタックの管理 of label

                                   LLVMcode* backpatch1;

                                   backpatch1 = brpop();
                                   if(backpatch1->command == BrCond){
                                          (backpatch1->args).brcond.arg3 = l;
                                   }

                                   // brスタックの管理 of BrUncond
                                   brpush(tmp1);
                                   
                                   
                                   /*----------------------------*/
                     }
    break;

  case 39:
#line 521 "parser.y"
    {             /* 制御文を記述する */ // | BrUncond 

                                   LLVMcode* tmp1;
                                   int arg1;

                                   tmp1 = memoryGet(tmp1); 
                                   arg1 = cnrt;
                                   tmp1->command=BrUncond;

                                   (tmp1->args).bruncond.arg1 = arg1;

                                   addList(tmp1);

                                   /* 制御文を記述する */  // | Label

                                   LLVMcode* tmp;
                                   int l;

                                   tmp = memoryGet(tmp); 

                                   tmp->command=Label;

                                   l = cnrt;
                                   cnrt++;

                                   (tmp->args).label.l = l;

                                   addList(tmp);

                                   // brスタックの管理

                                   LLVMcode* backpatch;

                                   backpatch = brpop();
                                   if(backpatch->command == BrCond){
                                          (backpatch->args).brcond.arg3 = l;
                                   }else{
                                          (backpatch->args).bruncond.arg1 = l;
                                   }
                                   
                                   /*----------------------------*/
                     }
    break;

  case 40:
#line 564 "parser.y"
    {            
                                    /* 制御文を記述する */ // | BrUncond 

                                   LLVMcode* tmp1;
                                   int arg1;

                                   tmp1 = memoryGet(tmp1); 
                                   arg1 = cnrt;
                                   tmp1->command=BrUncond;

                                   (tmp1->args).bruncond.arg1 = arg1;

                                   addList(tmp1);

                                   /* 制御文を記述する */  // | Label

                                   LLVMcode* tmp;
                                   int l;

                                   tmp = memoryGet(tmp); 

                                   tmp->command=Label;

                                   l = cnrt;
                                   cnrt++;

                                   (tmp->args).label.l = l;

                                   addList(tmp);

                                   // brスタックの管理

                                   LLVMcode* backpatch;

                                   backpatch = brpop();
                                   if(backpatch->command == BrCond){
                                          (backpatch->args).brcond.arg3 = l;
                                   }else{
                                          (backpatch->args).bruncond.arg1 = l;
                                   }
                                   
                                   /*----------------------------*/
                     }
    break;

  case 41:
#line 612 "parser.y"
    {                    
                                   /* 制御文を記述する */ // | BrUncond 

                                   LLVMcode* tmp1;
                                   int arg1;

                                   tmp1 = memoryGet(tmp1); 

                                   tmp1->command=BrUncond;
                                   (tmp1->args).bruncond.arg1 = cnrt; // cnrt++; は不要

                                   addList(tmp1);

                                   
                                   
                                   
                                   /* 制御文を記述する */  // | Label

                                   LLVMcode* tmp;
                                   int l;

                                   tmp = memoryGet(tmp); 

                                   tmp->command=Label;

                                   l = jumpid= cnrt;
                                   cnrt++;

                                   (tmp->args).label.l = l;

                                   addList(tmp);
                            
                     }
    break;

  case 42:
#line 646 "parser.y"
    {
                                   /* 制御文を記述する */ // | Brcond

                                   LLVMcode* tmp;
                                   Factor arg1;
                                   int arg2;

                                   tmp = memoryGet(tmp); 

                                   tmp->command=BrCond;

                                   arg1 = factorpop();
                                   arg2 = cnrt;

                                   (tmp->args).brcond.arg1 = arg1;
                                   (tmp->args).brcond.arg2 = arg2;

                                   addList(tmp);
                                   brpush(tmp);
                                   
                                   /*----------------------------*/

                                   /* 制御文を記述する */  // | Label

                                   LLVMcode* tmp2;
                                   int l;

                                   tmp2 = memoryGet(tmp2); 

                                   tmp2->command=Label;

                                   l = cnrt;
                                   cnrt++;

                                   (tmp2->args).label.l = l;

                                   addList(tmp2);
                                   /*----------------------------*/

                     }
    break;

  case 43:
#line 687 "parser.y"
    {
                            /* 制御文を記述する */ // | BrUncond 

                                   LLVMcode* tmp1;
                                   int arg1;

                                   tmp1 = memoryGet(tmp1); 

                                   tmp1->command=BrUncond;

                                   (tmp1->args).bruncond.arg1 = jumpid;

                                   addList(tmp1);


                            /* 制御文を記述する */  // | Label

                                   LLVMcode* tmp2;
                                   int l;

                                   tmp2 = memoryGet(tmp2); 

                                   tmp2->command=Label;

                                   l = cnrt;
                                   cnrt++;

                                   (tmp2->args).label.l = l;

                                   addList(tmp2);

                            // brスタックの管理 

                                   LLVMcode* backpatch;

                                   backpatch = brpop();
                                   if(backpatch->command == BrCond){
                                          (backpatch->args).brcond.arg3 = l;
                                   }

                     }
    break;

  case 44:
#line 732 "parser.y"
    {

                                  /* IDENTの番地に、expressionの値をstoreするコード*/

                                   LLVMcode* tmp1;
                                   Factor arg1,arg2;

                                   tmp1 = memoryGet(tmp1); 

                                   tmp1->command=Store;

                                   arg2 = lookup_data((yyvsp[(2) - (4)].ident));
                                   arg1 = factorpop(); // IDENTの初期値
                                       
                                   (tmp1->args).store.arg1 = arg1;
                                   (tmp1->args).store.arg2 = arg2;

                                   addList(tmp1);

                   
                                   /* 制御文を記述する */ // | BrUncond 

                                   LLVMcode* tmp2;

                                   tmp2 = memoryGet(tmp2); 

                                   tmp2->command=BrUncond;

                                   (tmp2->args).bruncond.arg1 = cnrt; // cnrt++;は不要

                                   addList(tmp2);


                            /* 制御文を記述する */  // | Label

                                   LLVMcode* tmp3;
                                   int l;

                                   tmp3 = memoryGet(tmp3); 

                                   tmp3->command=Label;

                                   l = jumpid = cnrt;
                                   cnrt++;

                                   (tmp3->args).label.l = l;

                                   addList(tmp3);

                            }
    break;

  case 45:
#line 783 "parser.y"
    {

                                   /* 与えられた引数を新引数をレジスタへ格納後スタック へプッシュする | Load*/
                                   LLVMcode* tmp0;

                                   Factor arg1L,retvalL;
                                   tmp0 = memoryGet(tmp0); 

                                   tmp0->command=Load;


                                   /* 記号表から引数のデータを取得 */
                                   arg1L = lookup_data((yyvsp[(2) - (7)].ident));
                                   
                                   retvalL.type = LOCAL_VAR; /* 新規に変数を格納するのは局所変数 */
                                   retvalL.val = cnrt;
                                   cnrt++;

                                   (tmp0->args).load.arg1 = arg1L;
                                   (tmp0->args).load.retval = retvalL;

                                   addList(tmp0);
                                   
                                   factorpush(retvalL);




                                   /* 整数比較命令（SLE）でIDENTとTO後の値を比較する*/

                                   LLVMcode* tmp;
                                   Cmptype type;
                                   Factor arg1,arg2,retval;

                                   tmp = memoryGet(tmp); 

                                   tmp->command=Icmp;

                                   
                                   arg1 = factorpop();
                                   
                                   arg2 = factorpop();
                                   
                                   (tmp->args).icmp.type = SLE;

                                   retval.type = LOCAL_VAR;
                                   retval.val = cnrt;
                                   cnrt++;

                                   factorpush(retval);

                                   (tmp->args).icmp.arg1 = arg1;
                                   (tmp->args).icmp.arg2 = arg2;
                                   (tmp->args).icmp.retval = retval;

                                   addList(tmp);
                                   
                                   /*----------------------------*/


                                   /* 制御文を記述する */ // | Brcond

                                   LLVMcode* tmp2;
                                   Factor arg1_1;

                                   tmp2 = memoryGet(tmp2); 

                                   tmp2->command=BrCond;

                                   arg1_1 = factorpop();

                                   (tmp2->args).brcond.arg1 = arg1_1;
                                   (tmp2->args).brcond.arg2 = cnrt;

                                   addList(tmp2);
                                   brpush(tmp2);
                                   
                                   /* ----------------------------*/

                                   /* ----------------------------*/

                                   /* 制御文を記述する */  // | Label

                                   LLVMcode* tmp3;
                                   int l;

                                   tmp3 = memoryGet(tmp3); 

                                   tmp3->command=Label;

                                   l = cnrt;
                                   cnrt++;

                                   (tmp3->args).label.l = l;

                                   addList(tmp3);
                                   /* ----------------------------*/


                            }
    break;

  case 46:
#line 884 "parser.y"
    {

                                   /* 加算命令でIDENTを1インクリメントする */
                                   LLVMcode *tmp;                //生成した命令へのポインタ
                                   Factor arg1, arg2,retval;      //加算の引数、結果
                                   tmp = memoryGet(tmp);          //mallocによるメモリ確保

                                   tmp->command = Add;
                                   
                                   arg2.type = CONSTANT;
                                   arg2.val = 1;

                                   arg1 = lookup_data((yyvsp[(2) - (10)].ident));
                                   
                                   retval.type = LOCAL_VAR;  //結果を格納するレジスタは局所変数
                                   retval.val = cnrt;        // 新規のレジスタ番号を取得
                                   cnrt++;

                                   (tmp->args).add.arg1 = arg1;   /* 命令の第1引数を指定 */
                                   (tmp->args).add.arg2 = arg2;   /* 命令の第2引数を指定 */
                                   (tmp->args).add.retval = retval; /* 結果のレジスタを指定*/

                                   addList(tmp);                /* 新規命令として、命令列へ追加する*/
                                   
                                   factorpush( retval );       // 加算の結果をスタックへプッシュ

                                   /*-----------------------------------------*/


                                  /* インクリメントしたIDENTをstoreする */

                                   LLVMcode* tmp0;
                                   Factor arg1_1,arg2_1;

                                   tmp0 = memoryGet(tmp0); 

                                   tmp0->command=Store;

                                   arg2_1 = lookup_data((yyvsp[(2) - (10)].ident));
                                   

                                   arg1_1 = factorpop(); 
                                       
                                   (tmp0->args).store.arg1 = arg1_1;
                                   (tmp0->args).store.arg2 = arg2_1;

                                   addList(tmp0);
                                   


                                    /* 制御文を記述する */ // | BrUncond 

                                   LLVMcode* tmp1;

                                   tmp1 = memoryGet(tmp1); 

                                   tmp1->command=BrUncond;

                                   (tmp1->args).bruncond.arg1 = jumpid;

                                   addList(tmp1);


                                    /* 制御文を記述する */  // | Label

                                   LLVMcode* tmp2;
                                   int l;

                                   tmp2 = memoryGet(tmp2); 

                                   tmp2->command=Label;

                                   l = cnrt;
                                   cnrt++;

                                   (tmp2->args).label.l = l;

                                   addList(tmp2);

                                   // brスタックの管理 

                                          LLVMcode* backpatch;

                                          backpatch = brpop();
                                          if(backpatch->command == BrCond){
                                                 (backpatch->args).brcond.arg3 = l;
                                          }


                            }
    break;

  case 48:
#line 978 "parser.y"
    {procArgFlag =1; callCount = 0;}
    break;

  case 49:
#line 979 "parser.y"
    {procArgFlag = 0; LLVMcode*tmp; tmp = procCallpop(); addList(tmp);}
    break;

  case 50:
#line 984 "parser.y"
    {             /* ----------- */
                     /* Call statement */
                     LLVMcode *tmp;
                     char name[10];

                     tmp = memoryGet(tmp);
                     tmp->command = Call;

                     strcpy(name,(yyvsp[(1) - (1)].ident));

                     strcpy(tmp->args.call.name,name);
                     procCallpush(tmp);
       }
    break;

  case 52:
#line 1005 "parser.y"
    {
                     LLVMcode *tmp;
                     Factor arg1,retval;

                     tmp = memoryGet(tmp);
                     tmp->command = Read;

                     arg1 = lookup_data((yyvsp[(3) - (4)].ident));
                     retval.type = LOCAL_VAR;
                     retval.val = cnrt;
                     cnrt++;

                     (tmp->args).read.arg1 = arg1;
                     (tmp->args).read.retval = retval;

                     addList(tmp);

                     readflag=2;

       }
    break;

  case 53:
#line 1029 "parser.y"
    {
                     LLVMcode *tmp;
                     Factor arg1,retval;

                     tmp = memoryGet(tmp);

                     tmp->command = Write;

                     arg1 = factorpop();
                     retval.type = LOCAL_VAR;
                     retval.val = cnrt;
                     cnrt++;

                     (tmp->args).write.arg1 = arg1;
                     (tmp->args).write.retval = retval;

                     addList(tmp);

                     writeflag =2;
       }
    break;

  case 55:
#line 1057 "parser.y"
    {                           

                                   /*整数比較命令を記述する*/

                                   LLVMcode* tmp;
                                   Cmptype type;
                                   Factor arg1,arg2,retval;

                                   tmp = memoryGet(tmp); 

                                   tmp->command=Icmp;

                                   arg1 = factorpop();
                                   arg2 = factorpop();
                                   
                                   (tmp->args).icmp.type = EQUAL;

                                   retval.type = LOCAL_VAR;
                                   retval.val = cnrt;
                                   cnrt++;

                                   factorpush(retval);

                                   (tmp->args).icmp.arg1 = arg1;
                                   (tmp->args).icmp.arg2 = arg2;
                                   (tmp->args).icmp.retval = retval;

                                   addList(tmp);
                                   
                                   /*----------------------------*/
       }
    break;

  case 56:
#line 1090 "parser.y"
    {                           

                                   /*整数比較命令を記述する*/

                                   LLVMcode* tmp;
                                   Cmptype type;
                                   Factor arg1,arg2,retval;

                                   tmp = memoryGet(tmp); 

                                   tmp->command=Icmp;

                                   arg1 = factorpop();
                                   arg2 = factorpop();
                                   
                                   (tmp->args).icmp.type = NE;

                                   retval.type = LOCAL_VAR;
                                   retval.val = cnrt;
                                   cnrt++;

                                   factorpush(retval);

                                   (tmp->args).icmp.arg1 = arg1;
                                   (tmp->args).icmp.arg2 = arg2;
                                   (tmp->args).icmp.retval = retval;

                                   addList(tmp);
                                   
                                   /*----------------------------*/
              }
    break;

  case 57:
#line 1122 "parser.y"
    {                           

                                   /*整数比較命令を記述する*/

                                   LLVMcode* tmp;
                                   Cmptype type;
                                   Factor arg1,arg2,retval;

                                   tmp = memoryGet(tmp); 

                                   tmp->command=Icmp;

                                   arg1 = factorpop();
                                   arg2 = factorpop();
                                   
                                   (tmp->args).icmp.type = SLT;

                                   retval.type = LOCAL_VAR;
                                   retval.val = cnrt;
                                   cnrt++;

                                   factorpush(retval);

                                   (tmp->args).icmp.arg1 = arg1;
                                   (tmp->args).icmp.arg2 = arg2;
                                   (tmp->args).icmp.retval = retval;

                                   addList(tmp);
                                   
                                   /*----------------------------*/
              }
    break;

  case 58:
#line 1154 "parser.y"
    {                           

                                   /*整数比較命令を記述する*/

                                   LLVMcode* tmp;
                                   Cmptype type;
                                   Factor arg1,arg2,retval;

                                   tmp = memoryGet(tmp); 

                                   tmp->command=Icmp;

                                   arg1 = factorpop();
                                   arg2 = factorpop();
                                   
                                   (tmp->args).icmp.type = SLE;

                                   retval.type = LOCAL_VAR;
                                   retval.val = cnrt;
                                   cnrt++;

                                   factorpush(retval);

                                   (tmp->args).icmp.arg1 = arg1;
                                   (tmp->args).icmp.arg2 = arg2;
                                   (tmp->args).icmp.retval = retval;

                                   addList(tmp);
                                   
                                   /*----------------------------*/
              }
    break;

  case 59:
#line 1186 "parser.y"
    {                           

                                   /*整数比較命令を記述する*/

                                   LLVMcode* tmp;
                                   Cmptype type;
                                   Factor arg1,arg2,retval;

                                   tmp = memoryGet(tmp); 

                                   tmp->command=Icmp;

                                   arg1 = factorpop();
                                   arg2 = factorpop();
                                   
                                   (tmp->args).icmp.type = SGT;

                                   retval.type = LOCAL_VAR;
                                   retval.val = cnrt;
                                   cnrt++;

                                   factorpush(retval);

                                   (tmp->args).icmp.arg1 = arg1;
                                   (tmp->args).icmp.arg2 = arg2;
                                   (tmp->args).icmp.retval = retval;

                                   addList(tmp);
                                   
                                   /*----------------------------*/
              }
    break;

  case 60:
#line 1218 "parser.y"
    {                           

                                   /*整数比較命令を記述する*/

                                   LLVMcode* tmp;
                                   Cmptype type;
                                   Factor arg1,arg2,retval;

                                   tmp = memoryGet(tmp); 

                                   tmp->command=Icmp;

                                   arg1 = factorpop();
                                   arg2 = factorpop();
                                   
                                   (tmp->args).icmp.type = SLE;

                                   retval.type = LOCAL_VAR;
                                   retval.val = cnrt;
                                   cnrt++;

                                   factorpush(retval);

                                   (tmp->args).icmp.arg1 = arg1;
                                   (tmp->args).icmp.arg2 = arg2;
                                   (tmp->args).icmp.retval = retval;

                                   addList(tmp);
                                   
                                   /*----------------------------*/
              }
    break;

  case 64:
#line 1257 "parser.y"
    {
				 /* 加算命令をLLVMコードとして生成するCプログラム */
				 LLVMcode *tmp;                //生成した命令へのポインタ
				 Factor arg1, arg2,retval;      //加算の引数、結果
				 tmp = memoryGet(tmp);          //mallocによるメモリ確保

				 tmp->command = Add;
				 arg2 = factorpop();       //スタックから第2引数をポップ
				 arg1 = factorpop();       //スタックから第1引数をポップ
				 retval.type = LOCAL_VAR;  //結果を格納するレジスタは局所変数
				 retval.val = cnrt;        // 新規のレジスタ番号を取得
				 cnrt++;

				 (tmp->args).add.arg1 = arg1;   /* 命令の第1引数を指定 */
				 (tmp->args).add.arg2 = arg2;   /* 命令の第2引数を指定 */
				 (tmp->args).add.retval = retval; /* 結果のレジスタを指定*/

				 addList(tmp);                /* 新規命令として、命令列へ追加する*/
				 
				 factorpush( retval );       // 加算の結果をスタックへプッシュ

				 /*-----------------------------------------*/
			 }
    break;

  case 65:
#line 1281 "parser.y"
    {
                            
                            /* 減算命令をLLVMコードとして生成するCプログラム */
				 LLVMcode *tmp;                //生成した命令へのポインタ
				 Factor arg1, arg2,retval;      //減算の引数、結果
				 tmp = memoryGet(tmp);          //mallocによるメモリ確保

				 tmp->command = Sub;
				 arg2 = factorpop();       //スタックから第2引数をポップ
				 arg1 = factorpop();       //スタックから第1引数をポップ
				 retval.type = LOCAL_VAR;  //結果を格納するレジスタは局所変数
				 retval.val = cnrt;        // 新規のレジスタ番号を取得
				 cnrt++;

				 (tmp->args).add.arg1 = arg1;   /* 命令の第1引数を指定 */
				 (tmp->args).add.arg2 = arg2;   /* 命令の第2引数を指定 */
				 (tmp->args).add.retval = retval; /* 結果のレジスタを指定*/

				 addList(tmp);                /* 新規命令として、命令列へ追加する*/
				 
				 factorpush( retval );       // 減算の結果をスタックへプッシュ

				 /*-----------------------------------------*/

                     }
    break;

  case 67:
#line 1311 "parser.y"
    {
                            /* 乗算命令をLLVMコードとして生成するCプログラム */
				 LLVMcode *tmp;               //生成した命令へのポインタ
				 Factor arg1, arg2,retval;      //乗算の引数、結果
				 tmp = memoryGet(tmp);          //mallocによるメモリ確保

				 tmp->command = Mul;
				 arg2 = factorpop();       //スタックから第2引数をポップ
				 arg1 = factorpop();       //スタックから第1引数をポップ
				 retval.type = LOCAL_VAR;  //結果を格納するレジスタは局所変数
				 retval.val = cnrt;        // 新規のレジスタ番号を取得
				 cnrt++;

				 (tmp->args).add.arg1 = arg1;   /* 命令の第1引数を指定 */
				 (tmp->args).add.arg2 = arg2;   /* 命令の第2引数を指定 */
				 (tmp->args).add.retval = retval; /* 結果のレジスタを指定*/

				 addList(tmp);                /* 新規命令として、命令列へ追加する*/
				 
				 factorpush( retval );       // 乗算の結果をスタックへプッシュ

				 /*-----------------------------------------*/
                     }
    break;

  case 68:
#line 1335 "parser.y"
    {
                            /* 除算命令をLLVMコードとして生成するCプログラム */
				 LLVMcode *tmp;             //生成した命令へのポインタ
				 Factor arg1, arg2,retval;      //除算の引数、結果
				 tmp = memoryGet(tmp);          //mallocによるメモリ確保

				 tmp->command = Div;
				 arg2 = factorpop();       //スタックから第2引数をポップ
				 arg1 = factorpop();       //スタックから第1引数をポップ
				 retval.type = LOCAL_VAR;  //結果を格納するレジスタは局所変数
				 retval.val = cnrt;        // 新規のレジスタ番号を取得
				 cnrt++;

				 (tmp->args).add.arg1 = arg1;   /* 命令の第1引数を指定 */
				 (tmp->args).add.arg2 = arg2;   /* 命令の第2引数を指定 */
				 (tmp->args).add.retval = retval; /* 結果のレジスタを指定*/

				 addList(tmp);                /* 新規命令として、命令列へ追加する*/
				 
				 factorpush( retval );       // 除算の結果をスタックへプッシュ

				 /*-----------------------------------------*/
                     }
    break;

  case 70:
#line 1362 "parser.y"
    {
				 /*定数引数をスタックへプッシュする*/

				 Factor number;
				 number.val = ((yyvsp[(1) - (1)].num));
				 number.type = CONSTANT;
				 factorpush(number);

                             if(procArgFlag == 1 ){       //手続き呼び出しの引数の場合
                                   LLVMcode* call;
                                   call = procCallpop();
                                   (call->args).call.arg_list[callCount] = number.val;
                                   callCount++;
                                   procCallpush(call);
                             }
                             /*----------------------------*/
         }
    break;

  case 72:
#line 1385 "parser.y"
    { 
                            
                            
                           

                                          /*与えられた引数を新引数をレジスタへ格納後スタック へプッシュする | Load*/
                                          LLVMcode* tmp;

                                          Factor arg1,retval;
                                          tmp = memoryGet(tmp); 

                                          tmp->command=Load;


                                          /* 記号表から引数のデータを取得 */
                                          arg1 = lookup_data((yyvsp[(1) - (1)].ident));
                                          

                                          retval.type = LOCAL_VAR; /* 新規に変数を格納するのは局所変数 */
                                          retval.val = cnrt;
                                          cnrt++;

                                          (tmp->args).load.arg1 = arg1;
                                          (tmp->args).load.retval = retval;

                                          addList(tmp);
                                          
                                          factorpush(retval);

                                                                          
                                          /*----------------------------*/
                                          printf("\nprocArgFlag:%d\n",procArgFlag);

                                          if(procArgFlag == 1 ){       //手続き呼び出しの引数の場合
                                                 LLVMcode* call;


                                                 call = procCallpop();
                                                 ((call->args).call.arg_list)[callCount] = retval.val;
                                                 callCount++;
                                                 printf("\narglist[%d]:%d\n",callCount-1,((call->args).call.arg_list)[callCount-1]);
                                                 procCallpush(call);


                                          }
                            }
    break;

  case 75:
#line 1441 "parser.y"
    { insert_data((yyvsp[(1) - (1)].ident),flag,cnrt);}
    break;

  case 76:
#line 1442 "parser.y"
    { 
                                   LLVMcode* tmp;
                                   tmp = memoryGet(tmp); 
                                   Factor retval;

                                   switch(flag){
                                          case GLOBAL_VAR:
                                                 /* 大域変数を出力する*/
                                                 displayGlobalVar((yyvsp[(1) - (2)].ident));
                                                 break;
                                          
                                          case LOCAL_VAR:
                                         
                                                 /* 局所変数の領域をAllocaするコード*/
                                                 tmp = memoryGet(tmp); 

                                                 tmp->command=Alloca;

                                                 // cnrt = 1; // cnrtの初期化を行う

                                                 retval.type = LOCAL_VAR;
                                                 retval.val = cnrt;
                                                 cnrt++;

                                                 (tmp->args).alloca.retval = retval;
                                                 
                                                 factorpush(retval);

                                                 addList(tmp);

                                                 break;
                                   
                                          default:
                                                 break;
                                     
                                     }

                                   /*----------------------------*/
                            }
    break;

  case 77:
#line 1483 "parser.y"
    {insert_data((yyvsp[(3) - (3)].ident),flag,cnrt);}
    break;

  case 78:
#line 1484 "parser.y"
    {
                                   LLVMcode* tmp;
                                   tmp = memoryGet(tmp); 
                                   Factor arg1,retval;
                                   switch(flag){
                                          case GLOBAL_VAR:
                                                 /* 大域変数を出力する*/
                                                 displayGlobalVar((yyvsp[(3) - (4)].ident));
                                                 break;
                                          case LOCAL_VAR:
                                                 /* 局所変数の領域をAllocaするコード*/

                                                 tmp = memoryGet(tmp); 

                                                 tmp->command=Alloca;

                                                 // cnrt = 1; // cnrtの初期化を行う

                                                 retval.type = LOCAL_VAR;
                                                 retval.val = cnrt;
                                                 cnrt++;

                                                 (tmp->args).alloca.retval = retval;
                                                 
                                                 factorpush(retval);

                                                 addList(tmp);
                                                 break;
                                   
                                          default:
                                                 break;
                                  }


                                   /*----------------------------*/
                            }
    break;

  case 79:
#line 1524 "parser.y"
    {      LLVMcode* tmp;
              tmp = memoryGet(tmp); 
              Factor retval;

              tmp = memoryGet(tmp); 

              tmp->command=Alloca;

               insert_data((yyvsp[(1) - (1)].ident),LOCAL_VAR,cnrt); 
               cnrt++;

              // cnrt = 1; // cnrtの初期化を行う

              retval.type = LOCAL_VAR;
              retval.val = cnrt;
              cnrt++;
              procArgCount++;

              (tmp->args).alloca.retval = retval;
              
              factorpush(retval);

              addList(tmp);   

               /* allocaした番地を番地をstoreするコード*/

              LLVMcode* tmp1;
              Factor arg1,arg2;

              tmp1 = memoryGet(tmp1); 

              tmp1->command=Store;

              arg2 = factorpop();  /* 局所変数を取り出す*/
              
              // strcpy(arg1.vname,$1);
              arg1.type = CONSTANT;
              arg1.val = 0; // 記号表の番地を代入する

              // factorpush(arg2);

              (tmp1->args).store.arg1 = arg1;
              (tmp1->args).store.arg2 = arg2;

              addList(tmp1);        
             
       }
    break;

  case 80:
#line 1572 "parser.y"
    {      LLVMcode* tmp;
              tmp = memoryGet(tmp); 
              Factor retval;

              tmp = memoryGet(tmp); 

              tmp->command=Alloca;

               insert_data((yyvsp[(3) - (3)].ident),LOCAL_VAR,cnrt); 
               cnrt++;

              // cnrt = 1; // cnrtの初期化を行う

              retval.type = LOCAL_VAR;
              retval.val = cnrt;
              cnrt++;
              procArgCount++;

              (tmp->args).alloca.retval = retval;
              
              factorpush(retval);

              addList(tmp);

              /* allocaした番地を番地をstoreするコード*/

              LLVMcode* tmp1;
              Factor arg1,arg2;

              tmp1 = memoryGet(tmp1); 

              tmp1->command=Store;

              arg2 = factorpop();  /* 局所変数を取り出す*/
              
              // strcpy(arg1.vname,$1);
              arg1.type = CONSTANT;
              arg1.val = 0; // 記号表の番地を代入する

              // factorpush(arg2);

              (tmp1->args).store.arg1 = arg1;
              (tmp1->args).store.arg2 = arg2;

              addList(tmp1);
       }
    break;


/* Line 1267 of yacc.c.  */
#line 3137 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 1620 "parser.y"

yyerror(char *s)
{
  fprintf(stderr, "%s line:%d token:%s\n", s ,yylineno,yytext);
}

