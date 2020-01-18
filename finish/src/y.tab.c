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
#include <stdlib.h>
#include "table.h"
#include "control.h"
#include "output.h"

extern int yylineno;
extern char *yytext;
extern FILE *yyout;

extern LLVMcode *codehd; /* 命令列の先頭のアドレスを保持するポインタ */
extern LLVMcode *codetl; /* 命令列の末尾のアドレスを保持するポインタ */

extern Factorstack fstack; /* 整数もしくはレジスタ番号を保持するスタック */

/* 関数定義の線形リストの先頭の要素のアドレスを保持するポインタ */
extern Fundecl *declhd;
/* 関数定義の線形リストの末尾の要素のアドレスを保持するポインタ */
extern Fundecl *decltl;

extern int readflag;
extern int writeflag;

Scope flag;
int cntr=1;



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
#line 36 "parser.y"
{
    int num;
    char ident[MAXLENGTH+1];
}
/* Line 193 of yacc.c.  */
#line 216 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 229 "y.tab.c"

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   100

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  55
/* YYNRULES -- Number of rules.  */
#define YYNRULES  83
/* YYNRULES -- Number of states.  */
#define YYNSTATES  135

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
       0,     0,     3,     4,    11,    12,    17,    20,    21,    25,
      27,    30,    33,    34,    38,    40,    42,    43,    49,    51,
      54,    58,    60,    62,    64,    66,    68,    70,    72,    74,
      76,    78,    82,    83,    84,    85,    94,    95,    99,   100,
     101,   102,   103,   104,   105,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   146,   147,   150,
     152,   156,   161,   166,   167,   171,   175,   179,   183,   187,
     191,   193,   196,   199,   203,   207,   209,   213,   217,   219,
     221,   225,   227,   229
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      42,     0,    -1,    -1,    12,    40,    43,    34,    44,    37,
      -1,    -1,    46,    49,    45,    57,    -1,    47,    34,    -1,
      -1,    47,    34,    48,    -1,    48,    -1,    16,    95,    -1,
      50,    34,    -1,    -1,    50,    34,    51,    -1,    51,    -1,
      52,    -1,    -1,    11,    53,    54,    34,    55,    -1,    40,
      -1,    46,    57,    -1,    56,    34,    57,    -1,    57,    -1,
      58,    -1,    59,    -1,    65,    -1,    71,    -1,    83,    -1,
      89,    -1,    86,    -1,    87,    -1,    88,    -1,    40,    38,
      91,    -1,    -1,    -1,    -1,    10,    90,    60,    14,    61,
      57,    62,    63,    -1,    -1,    64,     5,    57,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    66,    67,    90,    68,
       4,    69,    57,    70,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     7,    40,    38,    91,
      72,    15,    73,    74,    91,    75,    76,    77,     4,    78,
      57,    79,    80,    81,    82,    -1,    -1,    85,    84,    -1,
      40,    -1,     3,    56,     6,    -1,    13,    29,    40,    30,
      -1,    18,    29,    91,    30,    -1,    -1,    91,    23,    91,
      -1,    91,    24,    91,    -1,    91,    26,    91,    -1,    91,
      25,    91,    -1,    91,    28,    91,    -1,    91,    27,    91,
      -1,    92,    -1,    20,    92,    -1,    19,    92,    -1,    91,
      20,    92,    -1,    91,    19,    92,    -1,    93,    -1,    92,
      22,    93,    -1,    92,    21,    93,    -1,    94,    -1,    39,
      -1,    29,    91,    30,    -1,    40,    -1,    40,    -1,    95,
      33,    40,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    60,    60,    59,    73,    72,   108,   109,   112,   113,
     116,   119,   120,   123,   124,   127,   131,   130,   140,   177,
     180,   181,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   195,   221,   242,   260,   220,   280,   280,   317,   339,
     353,   370,   391,   407,   338,   443,   464,   478,   497,   521,
     549,   568,   584,   606,   630,   649,   442,   682,   681,   715,
     732,   736,   757,   777,   781,   806,   831,   856,   881,   906,
     933,   934,   935,   936,   961,   988,   989,  1014,  1041,  1042,
    1050,  1053,  1084,  1109
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
  "ASSIGN", "NUMBER", "IDENT", "$accept", "program", "@1", "outblock",
  "@2", "var_decl_part", "var_decl_list", "var_decl", "subprog_decl_part",
  "subprog_decl_list", "subprog_decl", "proc_decl", "@3", "proc_name",
  "inblock", "statement_list", "statement", "assignment_statement",
  "if_statement", "@4", "@5", "@6", "else_statement", "@7",
  "while_statement", "@8", "@9", "@10", "@11", "@12", "for_statement",
  "@13", "@14", "@15", "@16", "@17", "@18", "@19", "@20", "@21", "@22",
  "@23", "proc_call_statement", "@24", "proc_call_name", "block_statement",
  "read_statement", "write_statement", "null_statement", "condition",
  "expression", "term", "factor", "var_name", "id_list", 0
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
       0,    41,    43,    42,    45,    44,    46,    46,    47,    47,
      48,    49,    49,    50,    50,    51,    53,    52,    54,    55,
      56,    56,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    58,    60,    61,    62,    59,    64,    63,    63,    66,
      67,    68,    69,    70,    65,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    71,    84,    83,    85,
      86,    87,    88,    89,    90,    90,    90,    90,    90,    90,
      91,    91,    91,    91,    91,    92,    92,    92,    93,    93,
      93,    94,    95,    95
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     6,     0,     4,     2,     0,     3,     1,
       2,     2,     0,     3,     1,     1,     0,     5,     1,     2,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     0,     0,     0,     8,     0,     3,     0,     0,
       0,     0,     0,     0,     9,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    19,     0,     2,     1,
       3,     4,     4,     0,     3,     3,     3,     3,     3,     3,
       1,     2,     2,     3,     3,     1,     3,     3,     1,     1,
       3,     1,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     1,     0,     7,     0,     0,    12,
       0,     9,    82,    10,     3,    16,     4,     0,    14,    15,
       6,     0,     0,    63,    11,     8,    83,    18,     0,    63,
       0,     0,     0,    39,     0,    59,     5,    22,    23,    24,
      25,    26,    57,    28,    29,    30,    27,    13,     7,     0,
      21,     0,     0,     0,     0,    79,    81,    32,     0,    70,
      75,    78,     0,    40,     0,     0,    58,    63,    17,    60,
      63,     0,    72,    71,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    31,
      19,    20,    45,    80,    33,    74,    73,    64,    65,    67,
      66,    69,    68,    77,    76,    61,    41,    62,     0,    63,
       0,    46,    34,    42,    47,    38,    63,     0,    35,     0,
      43,    48,    63,    44,    49,    37,    50,     0,    51,    63,
      52,    53,    54,    55,    56
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     5,     8,    23,     9,    10,    11,    16,    17,
      18,    19,    22,    28,    68,    49,    36,    37,    38,    75,
     109,   115,   118,   119,    39,    63,    87,   110,   116,   123,
      40,   108,   114,   117,   124,   126,   127,   129,   131,   132,
     133,   134,    41,    66,    42,    43,    44,    45,    46,    57,
      58,    59,    60,    61,    13
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -63
static const yytype_int8 yypact[] =
{
     -10,   -33,    17,   -63,   -63,   -15,    21,     2,    14,    43,
      28,   -63,   -63,    30,   -63,   -63,   -63,    31,   -63,   -63,
      21,    26,    27,     3,    43,   -63,   -63,   -63,    34,     3,
      32,    -5,    40,   -63,    41,    35,   -63,   -63,   -63,   -63,
     -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,    21,    -3,
     -63,    36,     7,     7,    -5,   -63,   -63,   -63,    33,   -17,
     -63,   -63,    37,   -63,    -5,    -5,   -63,     3,   -63,   -63,
       3,    -5,   -17,   -17,    20,    57,     7,     7,    -5,    -5,
      -5,    -5,    -5,    -5,     7,     7,    45,    -5,    25,    29,
     -63,   -63,    29,   -63,   -63,   -17,   -17,    29,    29,    29,
      29,    29,    29,   -63,   -63,   -63,   -63,   -63,    61,     3,
      74,   -63,   -63,   -63,   -63,    76,     3,    -5,   -63,    77,
     -63,    29,     3,   -63,   -63,   -63,   -63,    75,   -63,     3,
     -63,   -63,   -63,   -63,   -63
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -63,   -63,   -63,   -63,   -63,    38,   -63,    63,   -63,   -63,
      60,   -63,   -63,   -63,   -63,   -63,   -29,   -63,   -63,   -63,
     -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,
     -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,
     -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,    -2,
     -53,   -44,   -62,   -63,   -63
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -37
static const yytype_int16 yytable[] =
{
      50,    74,     1,    69,    84,    85,    29,     3,    72,    73,
      30,    88,    89,    31,    52,    53,    32,     4,    92,     6,
      33,    34,   103,   104,    54,    97,    98,    99,   100,   101,
     102,    70,    95,    96,    55,    56,    54,     7,    90,    76,
      77,    91,    12,    35,    76,    77,    55,    56,    76,    77,
      93,    14,    76,    77,    15,   107,    78,    79,    80,    81,
      82,    83,    20,    21,   121,    24,    26,    27,    48,    62,
      64,    94,    51,    65,    71,   105,   111,    86,   113,   128,
     112,   -36,   122,    25,    47,   106,    67,   120,     0,     0,
       0,     0,     0,   125,     0,     0,     0,     0,     0,     0,
     130
};

static const yytype_int16 yycheck[] =
{
      29,    54,    12,     6,    21,    22,     3,    40,    52,    53,
       7,    64,    65,    10,    19,    20,    13,     0,    71,    34,
      17,    18,    84,    85,    29,    78,    79,    80,    81,    82,
      83,    34,    76,    77,    39,    40,    29,    16,    67,    19,
      20,    70,    40,    40,    19,    20,    39,    40,    19,    20,
      30,    37,    19,    20,    11,    30,    23,    24,    25,    26,
      27,    28,    34,    33,   117,    34,    40,    40,    34,    29,
      29,    14,    40,    38,    38,    30,    15,    40,     4,     4,
     109,     5,     5,    20,    24,    87,    48,   116,    -1,    -1,
      -1,    -1,    -1,   122,    -1,    -1,    -1,    -1,    -1,    -1,
     129
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    12,    42,    40,     0,    43,    34,    16,    44,    46,
      47,    48,    40,    95,    37,    11,    49,    50,    51,    52,
      34,    33,    53,    45,    34,    48,    40,    40,    54,     3,
       7,    10,    13,    17,    18,    40,    57,    58,    59,    65,
      71,    83,    85,    86,    87,    88,    89,    51,    34,    56,
      57,    40,    19,    20,    29,    39,    40,    90,    91,    92,
      93,    94,    29,    66,    29,    38,    84,    46,    55,     6,
      34,    38,    92,    92,    91,    60,    19,    20,    23,    24,
      25,    26,    27,    28,    21,    22,    40,    67,    91,    91,
      57,    57,    91,    30,    14,    92,    92,    91,    91,    91,
      91,    91,    91,    93,    93,    30,    90,    30,    72,    61,
      68,    15,    57,     4,    73,    62,    69,    74,    63,    64,
      57,    91,     5,    70,    75,    57,    76,    77,     4,    78,
      57,    79,    80,    81,    82
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
#line 60 "parser.y"
    {
                 init_fstack();
                 insert_data((yyvsp[(2) - (2)].ident),PROC_NAME,0);
                 
         }
    break;

  case 3:
#line 66 "parser.y"
    {
                displayLlvmfundecl(declhd);
        }
    break;

  case 4:
#line 73 "parser.y"
    {       
                Fundecl *func;
                func =(Fundecl *)malloc(sizeof(Fundecl));
                strcpy(func->fname,"main");
                func->ret = 1;
                codehd = codetl = func->codes;
                if(declhd == NULL){
                        declhd = decltl = func;
                }else{
                        decltl->next = func;
                        decltl = func;
                }

                
                LLVMcode *tmp;             /* 生成した命令へのポインタ */
                Factor retval; /* Allocaの結果 */
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL;          /* 次の命令へのポインタを初期化 */
                tmp->command = Alloca;        /* 命令の種類を加算に設定 */
                retval.type = LOCAL_VAR;   /* 結果を格納するレジスタは局所 */
                retval.val = cntr;         /* 新規のレジスタ番号を取得 */
                cntr++;                   /* カウンタをインクリメント */
                (tmp->args).alloca.retval = retval; /* 結果のレジスタを指定 */
                if( codetl == NULL ){ /* 解析中の関数の最初の命令の場合 */
                        decltl->codes = tmp;   /* 関数定義の命令列の先頭の命令に設定 */
                        codehd = codetl = tmp; /* 生成中の命令列の末尾の命令として記憶 */
                } else { /* 解析中の関数の命令列に1つ以上命令が存在する場合 */
                        codetl->next = tmp; /* 命令列の末尾に追加 */
                      codetl = tmp;       /* 命令列の末尾の命令として記憶 */
                }
                factorpush(retval);
        }
    break;

  case 16:
#line 131 "parser.y"
    {flag = LOCAL_VAR;}
    break;

  case 17:
#line 133 "parser.y"
    {
                delete_data(); 
                flag = GLOBAL_VAR;
                cntr=1;
        }
    break;

  case 18:
#line 141 "parser.y"
    {
                Fundecl *func;
                func =(Fundecl *)malloc(sizeof(Fundecl));
                strcpy(func->fname,(yyvsp[(1) - (1)].ident));
                func->ret = 0;
                codehd = codetl = func->codes;
                if(declhd == NULL){
                        declhd = decltl = func;
                }else{
                        decltl->next = func;
                        decltl = func;
                }
                insert_data((yyvsp[(1) - (1)].ident),PROC_NAME,0);
                
                

                LLVMcode *tmp;             /* 生成した命令へのポインタ */
                Factor retval; /* allocaの結果 */
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL;          /* 次の命令へのポインタを初期化 */
                tmp->command = Alloca;        /* 命令の種類を加算に設定 */
                retval.type = LOCAL_VAR;   /* 結果を格納するレジスタは局所 */
                retval.val = cntr;         /* 新規のレジスタ番号を取得 */
                cntr++;                   /* カウンタをインクリメント */
                (tmp->args).alloca.retval = retval; /* 結果のレジスタを指定 */
                if( codetl == NULL ){ /* 解析中の関数の最初の命令の場合 */
                        decltl->codes = tmp;   /* 関数定義の命令列の先頭の命令に設定 */
                        codehd = codetl = tmp; /* 生成中の命令列の末尾の命令として記憶 */
                } else { /* 解析中の関数の命令列に1つ以上命令が存在する場合 */
                        codetl->next = tmp; /* 命令列の末尾に追加 */
                        codetl = tmp;       /* 命令列の末尾の命令として記憶 */
                }
                factorpush(retval);
        }
    break;

  case 31:
#line 196 "parser.y"
    {
                
                 
                LLVMcode *tmp;             /* 生成した命令へのポインタ */
                Factor arg1, arg2; /* ストアの引数・結果 */
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL;          /* 次の命令へのポインタを初期化 */
                tmp->command = Store;        /* 命令の種類をストアに設定 */
                arg1 = factorpop();        /* スタックから第2引数をポップ */
                arg2 = lookup_data((yyvsp[(1) - (3)].ident));        /* スタックから第1引数をポップ */
                (tmp->args).add.arg1 = arg1; /* 命令の第1引数を指定 */
                (tmp->args).add.arg2 = arg2; /* 命令の第2引数を指定 */
                if( codetl == NULL ){ /* 解析中の関数の最初の命令の場合 */
                        
                        decltl->codes = tmp;   /* 関数定義の命令列の先頭の命令に設定 */
                        codehd = codetl = tmp; /* 生成中の命令列の末尾の命令として記憶 */
                } else { /* 解析中の関数の命令列に1つ以上命令が存在する場合 */
                        codetl->next = tmp; /* 命令列の末尾に追加 */
                        codetl = tmp;       /* 命令列の末尾の命令として記憶 */
                }
         }
    break;

  case 32:
#line 221 "parser.y"
    {
                
                
                LLVMcode *tmp;             /* 生成した命令へのポインタ */
                Factor arg1; /* brcondの条件 */
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL;          /* 次の命令へのポインタを初期化 */
                tmp->command = BrCond;        /* 命令の種類を加算に設定 */
                arg1 = factorpop();
                (tmp->args).brcond.arg1 = arg1; /* 結果のレジスタを指定 */
                (tmp->args).brcond.arg2 = cntr;
                if( codetl == NULL ){ /* 解析中の関数の最初の命令の場合 */
                        decltl->codes = tmp;   /* 関数定義の命令列の先頭の命令に設定 */
                        codehd = codetl = tmp; /* 生成中の命令列の末尾の命令として記憶 */
                } else { /* 解析中の関数の命令列に1つ以上命令が存在する場合 */
                        codetl->next = tmp; /* 命令列の末尾に追加 */
                        codetl = tmp;       /* 命令列の末尾の命令として記憶 */
                }
                add_add(tmp);
        }
    break;

  case 33:
#line 242 "parser.y"
    {
                
                
                LLVMcode *tmp;             /* 生成した命令へのポインタ */
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL;          /* 次の命令へのポインタを初期化 */
                tmp->command = Label;        /* 命令の種類を加算に設定 */
                (tmp->args).label.l = cntr; /* 結果のレジスタを指定 */
                cntr++;
                if( codetl == NULL ){ /* 解析中の関数の最初の命令の場合 */
                        decltl->codes = tmp;   /* 関数定義の命令列の先頭の命令に設定 */
                        codehd = codetl = tmp; /* 生成中の命令列の末尾の命令として記憶 */
                } else { /* 解析中の関数の命令列に1つ以上命令が存在する場合 */
                        codetl->next = tmp; /* 命令列の末尾に追加 */
                        codetl = tmp;       /* 命令列の末尾の命令として記憶 */
                }   
        }
    break;

  case 34:
#line 260 "parser.y"
    {
                
                LLVMcode *tmp;             /* 生成した命令へのポインタ */
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL;          /* 次の命令へのポインタを初期化 */
                tmp->command = BrUncond;        /* 命令の種類を加算に設定 */
                if( codetl == NULL ){ /* 解析中の関数の最初の命令の場合 */
                        decltl->codes = tmp;   /* 関数定義の命令列の先頭の命令に設定 */
                        codehd = codetl = tmp; /* 生成中の命令列の末尾の命令として記憶 */
                } else { /* 解析中の関数の命令列に1つ以上命令が存在する場合 */
                        codetl->next = tmp; /* 命令列の末尾に追加 */
                        codetl = tmp;       /* 命令列の末尾の命令として記憶 */
                }
                add_add(tmp);
        }
    break;

  case 36:
#line 280 "parser.y"
    {
                
                LLVMcode *tmp;             /* 生成した命令へのポインタ */
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL;          /* 次の命令へのポインタを初期化 */
                tmp->command = Label;        /* 命令の種類を加算に設定 */
                (tmp->args).label.l = cntr; /* 結果のレジスタを指定 */
                patch_if_else_1(cntr);
                cntr++;
                if( codetl == NULL ){ /* 解析中の関数の最初の命令の場合 */
                        decltl->codes = tmp;   /* 関数定義の命令列の先頭の命令に設定 */
                        codehd = codetl = tmp; /* 生成中の命令列の末尾の命令として記憶 */
                } else { /* 解析中の関数の命令列に1つ以上命令が存在する場合 */
                        codetl->next = tmp; /* 命令列の末尾に追加 */
                        codetl = tmp;       /* 命令列の末尾の命令として記憶 */
                }     
        }
    break;

  case 37:
#line 298 "parser.y"
    {
                

                LLVMcode *tmp;             /* 生成した命令へのポインタ */
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL;          /* 次の命令へのポインタを初期化 */
                tmp->command = Label;        /* 命令の種類を加算に設定 */
                (tmp->args).label.l = cntr; /* 結果のレジスタを指定 */
                patch_if_else_2(cntr);
                cntr++;
                if( codetl == NULL ){ /* 解析中の関数の最初の命令の場合 */
                        decltl->codes = tmp;   /* 関数定義の命令列の先頭の命令に設定 */
                        codehd = codetl = tmp; /* 生成中の命令列の末尾の命令として記憶 */
                } else { /* 解析中の関数の命令列に1つ以上命令が存在する場合 */
                        codetl->next = tmp; /* 命令列の末尾に追加 */
                        codetl = tmp;       /* 命令列の末尾の命令として記憶 */
                }     
        }
    break;

  case 38:
#line 317 "parser.y"
    {
                     
                LLVMcode *tmp;             /* 生成した命令へのポインタ */
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL;          /* 次の命令へのポインタを初期化 */
                tmp->command = Label;        /* 命令の種類を加算に設定 */
                (tmp->args).label.l = cntr; /* 結果のレジスタを指定 */
                patch_if_else_2(cntr);
                patch_if(cntr);
                cntr++;  
                if( codetl == NULL ){ /* 解析中の関数の最初の命令の場合 */
                        decltl->codes = tmp;   /* 関数定義の命令列の先頭の命令に設定 */
                        codehd = codetl = tmp; /* 生成中の命令列の末尾の命令として記憶 */
                } else { /* 解析中の関数の命令列に1つ以上命令が存在する場合 */
                        codetl->next = tmp; /* 命令列の末尾に追加 */
                        codetl = tmp;       /* 命令列の末尾の命令として記憶 */
                }       
        }
    break;

  case 39:
#line 339 "parser.y"
    {
                LLVMcode *tmp;             /* 生成した命令へのポインタ */
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL;          /* 次の命令へのポインタを初期化 */
                tmp->command = BrUncond;        /* 命令の種類を加算に設定 */
                (tmp->args).bruncond.arg1 = cntr;
                if( codetl == NULL ){ /* 解析中の関数の最初の命令の場合 */
                        decltl->codes = tmp;   /* 関数定義の命令列の先頭の命令に設定 */
                        codehd = codetl = tmp; /* 生成中の命令列の末尾の命令として記憶 */
                } else { /* 解析中の関数の命令列に1つ以上命令が存在する場合 */
                        codetl->next = tmp; /* 命令列の末尾に追加 */
                        codetl = tmp;       /* 命令列の末尾の命令として記憶 */
                }
        }
    break;

  case 40:
#line 353 "parser.y"
    {
                LLVMcode *tmp;             /* 生成した命令へのポインタ */
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL;          /* 次の命令へのポインタを初期化 */
                tmp->command = Label;        /* 命令の種類を加算に設定 */
                (tmp->args).label.l = cntr; /* 結果のレジスタを指定 */
                add_label(cntr);
                cntr++;
                if( codetl == NULL ){ /* 解析中の関数の最初の命令の場合 */
                        decltl->codes = tmp;   /* 関数定義の命令列の先頭の命令に設定 */
                        codehd = codetl = tmp; /* 生成中の命令列の末尾の命令として記憶 */
                } else { /* 解析中の関数の命令列に1つ以上命令が存在する場合 */
                        codetl->next = tmp; /* 命令列の末尾に追加 */
                        codetl = tmp;       /* 命令列の末尾の命令として記憶 */
                }
        }
    break;

  case 41:
#line 370 "parser.y"
    {
                

                LLVMcode *tmp;             /* 生成した命令へのポインタ */
                Factor arg1; /* brcondの条件 */
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL;          /* 次の命令へのポインタを初期化 */
                tmp->command = BrCond;        /* 命令の種類を加算に設定 */
                arg1 = factorpop();
                (tmp->args).brcond.arg1 = arg1; /* 結果のレジスタを指定 */
                (tmp->args).brcond.arg2 = cntr;
                if( codetl == NULL ){ /* 解析中の関数の最初の命令の場合 */
                        decltl->codes = tmp;   /* 関数定義の命令列の先頭の命令に設定 */
                        codehd = codetl = tmp; /* 生成中の命令列の末尾の命令として記憶 */
                } else { /* 解析中の関数の命令列に1つ以上命令が存在する場合 */
                        codetl->next = tmp; /* 命令列の末尾に追加 */
                        codetl = tmp;       /* 命令列の末尾の命令として記憶 */
                }
                add_add(tmp);
        }
    break;

  case 42:
#line 391 "parser.y"
    {
                LLVMcode *tmp;             /* 生成した命令へのポインタ */
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL;          /* 次の命令へのポインタを初期化 */
                tmp->command = Label;        /* 命令の種類を加算に設定 */
                (tmp->args).label.l = cntr; /* 結果のレジスタを指定 */
                cntr++;
                if( codetl == NULL ){ /* 解析中の関数の最初の命令の場合 */
                        decltl->codes = tmp;   /* 関数定義の命令列の先頭の命令に設定 */
                        codehd = codetl = tmp; /* 生成中の命令列の末尾の命令として記憶 */
                } else { /* 解析中の関数の命令列に1つ以上命令が存在する場合 */
                        codetl->next = tmp; /* 命令列の末尾に追加 */
                        codetl = tmp;       /* 命令列の末尾の命令として記憶 */
                }   
        }
    break;

  case 43:
#line 407 "parser.y"
    {
                
                LLVMcode *tmp;             /* 生成した命令へのポインタ */
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL;          /* 次の命令へのポインタを初期化 */
                tmp->command = BrUncond;        /* 命令の種類を加算に設定 */
                patch_label(tmp);
                if( codetl == NULL ){ /* 解析中の関数の最初の命令の場合 */
                        decltl->codes = tmp;   /* 関数定義の命令列の先頭の命令に設定 */
                        codehd = codetl = tmp; /* 生成中の命令列の末尾の命令として記憶 */
                } else { /* 解析中の関数の命令列に1つ以上命令が存在する場合 */
                        codetl->next = tmp; /* 命令列の末尾に追加 */
                        codetl = tmp;       /* 命令列の末尾の命令として記憶 */
                }
        }
    break;

  case 44:
#line 422 "parser.y"
    {
                

                LLVMcode *tmp;             /* 生成した命令へのポインタ */
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL;          /* 次の命令へのポインタを初期化 */
                tmp->command = Label;        /* 命令の種類を加算に設定 */
                (tmp->args).label.l = cntr; /* 結果のレジスタを指定 */
                patch_if(cntr);
                cntr++;
                if( codetl == NULL ){ /* 解析中の関数の最初の命令の場合 */
                        decltl->codes = tmp;   /* 関数定義の命令列の先頭の命令に設定 */
                        codehd = codetl = tmp; /* 生成中の命令列の末尾の命令として記憶 */
                } else { /* 解析中の関数の命令列に1つ以上命令が存在する場合 */
                        codetl->next = tmp; /* 命令列の末尾に追加 */
                        codetl = tmp;       /* 命令列の末尾の命令として記憶 */
                }   
        }
    break;

  case 45:
#line 443 "parser.y"
    {
                
                LLVMcode *tmp;             /* 生成した命令へのポインタ */
                Factor arg1, arg2; /* ストアの引数・結果 */
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL;          /* 次の命令へのポインタを初期化 */
                tmp->command = Store;        /* 命令の種類をストアに設定 */
                arg1 = factorpop();        /* スタックから第2引数をポップ */
                arg2 = lookup_data((yyvsp[(2) - (4)].ident));        /* スタックから第1引数をポップ */
                (tmp->args).add.arg1 = arg1; /* 命令の第1引数を指定 */
                (tmp->args).add.arg2 = arg2; /* 命令の第2引数を指定 */
                if( codetl == NULL ){ /* 解析中の関数の最初の命令の場合 */
                        
                        decltl->codes = tmp;   /* 関数定義の命令列の先頭の命令に設定 */
                        codehd = codetl = tmp; /* 生成中の命令列の末尾の命令として記憶 */
                } else { /* 解析中の関数の命令列に1つ以上命令が存在する場合 */
                        codetl->next = tmp; /* 命令列の末尾に追加 */
                        codetl = tmp;       /* 命令列の末尾の命令として記憶 */
                }
        }
    break;

  case 46:
#line 464 "parser.y"
    {
                LLVMcode *tmp;             /* 生成した命令へのポインタ */
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL;          /* 次の命令へのポインタを初期化 */
                tmp->command = BrUncond;        /* 命令の種類を加算に設定 */
                (tmp->args).bruncond.arg1 = cntr;
                if( codetl == NULL ){ /* 解析中の関数の最初の命令の場合 */
                        decltl->codes = tmp;   /* 関数定義の命令列の先頭の命令に設定 */
                        codehd = codetl = tmp; /* 生成中の命令列の末尾の命令として記憶 */
                } else { /* 解析中の関数の命令列に1つ以上命令が存在する場合 */
                        codetl->next = tmp; /* 命令列の末尾に追加 */
                        codetl = tmp;       /* 命令列の末尾の命令として記憶 */
                }
        }
    break;

  case 47:
#line 478 "parser.y"
    {
                

                LLVMcode *tmp;             /* 生成した命令へのポインタ */
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL;          /* 次の命令へのポインタを初期化 */
                tmp->command = Label;        /* 命令の種類を加算に設定 */
                (tmp->args).label.l = cntr; /* 結果のレジスタを指定 */
                add_label(cntr);
                cntr++;
                if( codetl == NULL ){ /* 解析中の関数の最初の命令の場合 */
                        decltl->codes = tmp;   /* 関数定義の命令列の先頭の命令に設定 */
                        codehd = codetl = tmp; /* 生成中の命令列の末尾の命令として記憶 */
                } else { /* 解析中の関数の命令列に1つ以上命令が存在する場合 */
                        codetl->next = tmp; /* 命令列の末尾に追加 */
                        codetl = tmp;       /* 命令列の末尾の命令として記憶 */
                }
        }
    break;

  case 48:
#line 497 "parser.y"
    {
                

                LLVMcode *tmp;             /* 生成した命令へのポインタ */
                Factor arg1, retval; /* ロードの引数・結果 */
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL;          /* 次の命令へのポインタを初期化 */
                tmp->command = Load;        /* 命令の種類をロードに設定 */
                arg1 = lookup_data((yyvsp[(2) - (9)].ident));        /* スタックから第1引数をポップ */
                retval.type = LOCAL_VAR;   /* 結果を格納するレジスタは局所 */
                retval.val = cntr;         /* 新規のレジスタ番号を取得 */
                cntr++;                   /* カウンタをインクリメント */
                (tmp->args).load.arg1 = arg1; /* 命令の第1引数を指定 */
                (tmp->args).load.retval = retval; /* 結果のレジスタを指定 */
                if( codetl == NULL ){ /* 解析中の関数の最初の命令の場合 */
                        
                        decltl->codes = tmp;   /* 関数定義の命令列の先頭の命令に設定 */
                        codehd = codetl = tmp; /* 生成中の命令列の末尾の命令として記憶 */
                } else { /* 解析中の関数の命令列に1つ以上命令が存在する場合 */
                        codetl->next = tmp; /* 命令列の末尾に追加 */
                        codetl = tmp;       /* 命令列の末尾の命令として記憶 */
                }
                factorpush( retval ); /* ロードの結果をスタックにプッシュ */
        }
    break;

  case 49:
#line 521 "parser.y"
    {
                

                LLVMcode *tmp;             /* 生成した命令へのポインタ */
                Factor arg1, arg2, retval; /* 比較演算の引数・結果 */
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL;          /* 次の命令へのポインタを初期化 */
                tmp->command = Icmp;        /* 命令の種類を比較に設定 */
                arg1 = factorpop();        /* スタックから第2引数をポップ */
                arg2 = factorpop();       /* スタックから第1引数をポップ */
                retval.type = LOCAL_VAR;   /* 結果を格納するレジスタは局所 */
                retval.val = cntr;         /* 新規のレジスタ番号を取得 */
                cntr++;                   /* カウンタをインクリメント */
                (tmp->args).icmp.type = SLT; /* 比較演算子を<に設定 */
                (tmp->args).icmp.arg1 = arg1; /* 命令の第1引数を指定 */
                (tmp->args).icmp.arg2 = arg2; /* 命令の第2引数を指定 */
                (tmp->args).icmp.retval = retval; /* 結果のレジスタを指定 */
                if( codetl == NULL ){ /* 解析中の関数の最初の命令の場合 */
                        decltl->codes = tmp;   /* 関数定義の命令列の先頭の命令に設定 */
                        codehd = codetl = tmp; /* 生成中の命令列の末尾の命令として記憶 */
                } else { /* 解析中の関数の命令列に1つ以上命令が存在する場合 */
                        codetl->next = tmp; /* 命令列の末尾に追加 */
                        codetl = tmp;       /* 命令列の末尾の命令として記憶 */
                }

                factorpush( retval ); /* 比較演算の結果をスタックにプッシュ */
        
        }
    break;

  case 50:
#line 549 "parser.y"
    {
                LLVMcode *tmp;             /* 生成した命令へのポインタ */
                Factor arg1; /* brcondの条件 */
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL;          /* 次の命令へのポインタを初期化 */
                tmp->command = BrCond;        /* 命令の種類を加算に設定 */
                arg1 = factorpop();
                (tmp->args).brcond.arg1 = arg1; /* 結果のレジスタを指定 */
                (tmp->args).brcond.arg2 =cntr;
                if( codetl == NULL ){ /* 解析中の関数の最初の命令の場合 */
                        decltl->codes = tmp;   /* 関数定義の命令列の先頭の命令に設定 */
                        codehd = codetl = tmp; /* 生成中の命令列の末尾の命令として記憶 */
                } else { /* 解析中の関数の命令列に1つ以上命令が存在する場合 */
                        codetl->next = tmp; /* 命令列の末尾に追加 */
                        codetl = tmp;       /* 命令列の末尾の命令として記憶 */
                }
                add_add(tmp);
        }
    break;

  case 51:
#line 568 "parser.y"
    {
                LLVMcode *tmp;             /* 生成した命令へのポインタ */
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL;          /* 次の命令へのポインタを初期化 */
                tmp->command = Label;        /* 命令の種類を加算に設定 */
                (tmp->args).label.l = cntr; /* 結果のレジスタを指定 */
                cntr++;
                if( codetl == NULL ){ /* 解析中の関数の最初の命令の場合 */
                        decltl->codes = tmp;   /* 関数定義の命令列の先頭の命令に設定 */
                        codehd = codetl = tmp; /* 生成中の命令列の末尾の命令として記憶 */
                } else { /* 解析中の関数の命令列に1つ以上命令が存在する場合 */
                        codetl->next = tmp; /* 命令列の末尾に追加 */
                        codetl = tmp;       /* 命令列の末尾の命令として記憶 */
                }   
        }
    break;

  case 52:
#line 584 "parser.y"
    {
                LLVMcode *tmp;             /* 生成した命令へのポインタ */
                Factor arg1, retval; /* ロードの引数・結果 */
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL;          /* 次の命令へのポインタを初期化 */
                tmp->command = Load;        /* 命令の種類をロードに設定 */
                arg1 = lookup_data((yyvsp[(2) - (15)].ident));        /* スタックから第1引数をポップ */
                retval.type = LOCAL_VAR;   /* 結果を格納するレジスタは局所 */
                retval.val = cntr;         /* 新規のレジスタ番号を取得 */
                cntr++;                   /* カウンタをインクリメント */
                (tmp->args).load.arg1 = arg1; /* 命令の第1引数を指定 */
                (tmp->args).load.retval = retval; /* 結果のレジスタを指定 */
                if( codetl == NULL ){ /* 解析中の関数の最初の命令の場合 */
                        
                        decltl->codes = tmp;   /* 関数定義の命令列の先頭の命令に設定 */
                        codehd = codetl = tmp; /* 生成中の命令列の末尾の命令として記憶 */
                } else { /* 解析中の関数の命令列に1つ以上命令が存在する場合 */
                        codetl->next = tmp; /* 命令列の末尾に追加 */
                        codetl = tmp;       /* 命令列の末尾の命令として記憶 */
                }
                factorpush( retval ); /* ロードの結果をスタックにプッシュ */
        }
    break;

  case 53:
#line 606 "parser.y"
    {
                LLVMcode *tmp;             /* 生成した命令へのポインタ */
                Factor arg1, arg2, retval; /* 加算の引数・結果 */
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL;          /* 次の命令へのポインタを初期化 */
                tmp->command = Add;        /* 命令の種類を加算に設定 */
                arg1 = factorpop();        /* スタックから第2引数をポップ */
                arg2.type = CONSTANT;        /* スタックから第1引数をポップ */
                arg2.val = 1;
                retval.type = LOCAL_VAR;   /* 結果を格納するレジスタは局所 */
                retval.val = cntr;         /* 新規のレジスタ番号を取得 */
                cntr++;                   /* カウンタをインクリメント */
                (tmp->args).add.arg1 = arg1; /* 命令の第1引数を指定 */
                (tmp->args).add.arg2 = arg2; /* 命令の第2引数を指定 */
                (tmp->args).add.retval = retval; /* 結果のレジスタを指定 */
                if( codetl == NULL ){ /* 解析中の関数の最初の命令の場合 */
                        decltl->codes = tmp;   /* 関数定義の命令列の先頭の命令に設定 */
                        codehd = codetl = tmp; /* 生成中の命令列の末尾の命令として記憶 */
                } else { /* 解析中の関数の命令列に1つ以上命令が存在する場合 */
                        codetl->next = tmp; /* 命令列の末尾に追加 */
                        codetl = tmp;       /* 命令列の末尾の命令として記憶 */
                }
                factorpush( retval ); /* 加算の結果をスタックにプッシュ */
        }
    break;

  case 54:
#line 630 "parser.y"
    {
                LLVMcode *tmp;             /* 生成した命令へのポインタ */
                Factor arg1, arg2; /* ストアの引数・結果 */
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL;          /* 次の命令へのポインタを初期化 */
                tmp->command = Store;        /* 命令の種類をストアに設定 */
                arg1 = factorpop();        /* スタックから第2引数をポップ */
                arg2 = lookup_data((yyvsp[(2) - (17)].ident));        /* スタックから第1引数をポップ */
                (tmp->args).add.arg1 = arg1; /* 命令の第1引数を指定 */
                (tmp->args).add.arg2 = arg2; /* 命令の第2引数を指定 */
                if( codetl == NULL ){ /* 解析中の関数の最初の命令の場合 */
                        
                        decltl->codes = tmp;   /* 関数定義の命令列の先頭の命令に設定 */
                        codehd = codetl = tmp; /* 生成中の命令列の末尾の命令として記憶 */
                } else { /* 解析中の関数の命令列に1つ以上命令が存在する場合 */
                        codetl->next = tmp; /* 命令列の末尾に追加 */
                        codetl = tmp;       /* 命令列の末尾の命令として記憶 */
                }
        }
    break;

  case 55:
#line 649 "parser.y"
    {
                LLVMcode *tmp;             /* 生成した命令へのポインタ */
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL;          /* 次の命令へのポインタを初期化 */
                tmp->command = BrUncond;        /* 命令の種類を加算に設定 */
                patch_label(tmp);
                if( codetl == NULL ){ /* 解析中の関数の最初の命令の場合 */
                        decltl->codes = tmp;   /* 関数定義の命令列の先頭の命令に設定 */
                        codehd = codetl = tmp; /* 生成中の命令列の末尾の命令として記憶 */
                } else { /* 解析中の関数の命令列に1つ以上命令が存在する場合 */
                        codetl->next = tmp; /* 命令列の末尾に追加 */
                        codetl = tmp;       /* 命令列の末尾の命令として記憶 */
                }
        }
    break;

  case 56:
#line 663 "parser.y"
    {
                LLVMcode *tmp;             /* 生成した命令へのポインタ */
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL;          /* 次の命令へのポインタを初期化 */
                tmp->command = Label;        /* 命令の種類を加算に設定 */
                (tmp->args).label.l = cntr; /* 結果のレジスタを指定 */
                patch_if(cntr);
                cntr++;  
                if( codetl == NULL ){ /* 解析中の関数の最初の命令の場合 */
                        decltl->codes = tmp;   /* 関数定義の命令列の先頭の命令に設定 */
                        codehd = codetl = tmp; /* 生成中の命令列の末尾の命令として記憶 */
                } else { /* 解析中の関数の命令列に1つ以上命令が存在する場合 */
                        codetl->next = tmp; /* 命令列の末尾に追加 */
                        codetl = tmp;       /* 命令列の末尾の命令として記憶 */
                }
        }
    break;

  case 57:
#line 682 "parser.y"
    {
                LLVMcode *tmp;             /* 生成した命令へのポインタ */
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL;          /* 次の命令へのポインタを初期化 */
                tmp->command = BrUncond;        /* 命令の種類を加算に設定 */
                (tmp->args).bruncond.arg1 = cntr;
                if( codetl == NULL ){ /* 解析中の関数の最初の命令の場合 */
                        decltl->codes = tmp;   /* 関数定義の命令列の先頭の命令に設定 */
                        codehd = codetl = tmp; /* 生成中の命令列の末尾の命令として記憶 */
                } else { /* 解析中の関数の命令列に1つ以上命令が存在する場合 */
                        codetl->next = tmp; /* 命令列の末尾に追加 */
                        codetl = tmp;       /* 命令列の末尾の命令として記憶 */
                }
        }
    break;

  case 58:
#line 696 "parser.y"
    {
                

                LLVMcode *tmp;             /* 生成した命令へのポインタ */
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL;          /* 次の命令へのポインタを初期化 */
                tmp->command = Label;        /* 命令の種類を加算に設定 */
                (tmp->args).label.l = cntr; /* 結果のレジスタを指定 */
                cntr++;
                if( codetl == NULL ){ /* 解析中の関数の最初の命令の場合 */
                        decltl->codes = tmp;   /* 関数定義の命令列の先頭の命令に設定 */
                        codehd = codetl = tmp; /* 生成中の命令列の末尾の命令として記憶 */
                } else { /* 解析中の関数の命令列に1つ以上命令が存在する場合 */
                        codetl->next = tmp; /* 命令列の末尾に追加 */
                        codetl = tmp;       /* 命令列の末尾の命令として記憶 */
                }
        }
    break;

  case 59:
#line 716 "parser.y"
    {
                LLVMcode *tmp;             /* 生成した命令へのポインタ */
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL;          /* 次の命令へのポインタを初期化 */
                tmp->command = Call;        /* 命令の種類を加算に設定 */
                strcpy((tmp->args).call.name,(yyvsp[(1) - (1)].ident))   ; /* 結果のレジスタを指定 */  
                if( codetl == NULL ){ /* 解析中の関数の最初の命令の場合 */
                        decltl->codes = tmp;   /* 関数定義の命令列の先頭の命令に設定 */
                        codehd = codetl = tmp; /* 生成中の命令列の末尾の命令として記憶 */
                } else { /* 解析中の関数の命令列に1つ以上命令が存在する場合 */
                        codetl->next = tmp; /* 命令列の末尾に追加 */
                        codetl = tmp;       /* 命令列の末尾の命令として記憶 */
                }
        }
    break;

  case 61:
#line 737 "parser.y"
    {
                LLVMcode *tmp;             /* 生成した命令へのポインタ */
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL;          /* 次の命令へのポインタを初期化 */
                tmp->command = Read;        /* 命令の種類を加算に設定 */
                (tmp->args).read.arg1 = lookup_data((yyvsp[(3) - (4)].ident)); /* 結果のレジスタを指定 */  
                (tmp->args).read.retval.type = LOCAL_VAR;
                (tmp->args).read.retval.val = cntr;
                cntr++;
                if( codetl == NULL ){ /* 解析中の関数の最初の命令の場合 */
                        decltl->codes = tmp;   /* 関数定義の命令列の先頭の命令に設定 */
                        codehd = codetl = tmp; /* 生成中の命令列の末尾の命令として記憶 */
                } else { /* 解析中の関数の命令列に1つ以上命令が存在する場合 */
                        codetl->next = tmp; /* 命令列の末尾に追加 */
                        codetl = tmp;       /* 命令列の末尾の命令として記憶 */
                }
                readflag=2;
        }
    break;

  case 62:
#line 758 "parser.y"
    {
                LLVMcode *tmp;             /* 生成した命令へのポインタ */
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL;          /* 次の命令へのポインタを初期化 */
                tmp->command = Write;        /* 命令の種類を加算に設定 */
                (tmp->args).write.arg1 = factorpop(); /* 結果のレジスタを指定 */  
                (tmp->args).read.retval.type = LOCAL_VAR;
                (tmp->args).read.retval.val = cntr;
                cntr++;
                if( codetl == NULL ){ /* 解析中の関数の最初の命令の場合 */
                        decltl->codes = tmp;   /* 関数定義の命令列の先頭の命令に設定 */
                        codehd = codetl = tmp; /* 生成中の命令列の末尾の命令として記憶 */
                } else { /* 解析中の関数の命令列に1つ以上命令が存在する場合 */
                        codetl->next = tmp; /* 命令列の末尾に追加 */
                        codetl = tmp;       /* 命令列の末尾の命令として記憶 */
                }
                writeflag=2;
        }
    break;

  case 64:
#line 782 "parser.y"
    {
                LLVMcode *tmp;             /* 生成した命令へのポインタ */
                Factor arg1, arg2, retval; /* 比較演算の引数・結果 */
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL;          /* 次の命令へのポインタを初期化 */
                tmp->command = Icmp;        /* 命令の種類を比較に設定 */
                arg2 = factorpop();        /* スタックから第2引数をポップ */
                arg1 = factorpop();       /* スタックから第1引数をポップ */
                retval.type = LOCAL_VAR;   /* 結果を格納するレジスタは局所 */
                retval.val = cntr;         /* 新規のレジスタ番号を取得 */
                cntr++;                   /* カウンタをインクリメント */
                (tmp->args).icmp.type = EQUAL; /* 比較演算子を==に設定 */
                (tmp->args).icmp.arg1 = arg1; /* 命令の第1引数を指定 */
                (tmp->args).icmp.arg2 = arg2; /* 命令の第2引数を指定 */
                (tmp->args).icmp.retval = retval; /* 結果のレジスタを指定 */
                if( codetl == NULL ){ /* 解析中の関数の最初の命令の場合 */
                        decltl->codes = tmp;   /* 関数定義の命令列の先頭の命令に設定 */
                        codehd = codetl = tmp; /* 生成中の命令列の末尾の命令として記憶 */
                } else { /* 解析中の関数の命令列に1つ以上命令が存在する場合 */
                        codetl->next = tmp; /* 命令列の末尾に追加 */
                        codetl = tmp;       /* 命令列の末尾の命令として記憶 */
                }
                factorpush( retval ); /* 比較演算の結果をスタックにプッシュ */
        }
    break;

  case 65:
#line 807 "parser.y"
    {
                LLVMcode *tmp;             /* 生成した命令へのポインタ */
                Factor arg1, arg2, retval; /* 比較演算の引数・結果 */
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL;          /* 次の命令へのポインタを初期化 */
                tmp->command = Icmp;        /* 命令の種類を比較に設定 */
                arg2 = factorpop();        /* スタックから第2引数をポップ */
                arg1 = factorpop();       /* スタックから第1引数をポップ */
                retval.type = LOCAL_VAR;   /* 結果を格納するレジスタは局所 */
                retval.val = cntr;         /* 新規のレジスタ番号を取得 */
                cntr++;                   /* カウンタをインクリメント */
                (tmp->args).icmp.type = NE; /* 比較演算子を!=に設定 */
                (tmp->args).icmp.arg1 = arg1; /* 命令の第1引数を指定 */
                (tmp->args).icmp.arg2 = arg2; /* 命令の第2引数を指定 */
                (tmp->args).icmp.retval = retval; /* 結果のレジスタを指定 */
                if( codetl == NULL ){ /* 解析中の関数の最初の命令の場合 */
                        decltl->codes = tmp;   /* 関数定義の命令列の先頭の命令に設定 */
                        codehd = codetl = tmp; /* 生成中の命令列の末尾の命令として記憶 */
                } else { /* 解析中の関数の命令列に1つ以上命令が存在する場合 */
                        codetl->next = tmp; /* 命令列の末尾に追加 */
                        codetl = tmp;       /* 命令列の末尾の命令として記憶 */
                }
                factorpush( retval ); /* 比較演算の結果をスタックにプッシュ */
        }
    break;

  case 66:
#line 832 "parser.y"
    {
                LLVMcode *tmp;             /* 生成した命令へのポインタ */
                Factor arg1, arg2, retval; /* 比較演算の引数・結果 */
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL;          /* 次の命令へのポインタを初期化 */
                tmp->command = Icmp;        /* 命令の種類を比較に設定 */
                arg2 = factorpop();        /* スタックから第2引数をポップ */
                arg1 = factorpop();       /* スタックから第1引数をポップ */
                retval.type = LOCAL_VAR;   /* 結果を格納するレジスタは局所 */
                retval.val = cntr;         /* 新規のレジスタ番号を取得 */
                cntr++;                   /* カウンタをインクリメント */
                (tmp->args).icmp.type = SLT; /* 比較演算子を<に設定 */
                (tmp->args).icmp.arg1 = arg1; /* 命令の第1引数を指定 */
                (tmp->args).icmp.arg2 = arg2; /* 命令の第2引数を指定 */
                (tmp->args).icmp.retval = retval; /* 結果のレジスタを指定 */
                if( codetl == NULL ){ /* 解析中の関数の最初の命令の場合 */
                        decltl->codes = tmp;   /* 関数定義の命令列の先頭の命令に設定 */
                        codehd = codetl = tmp; /* 生成中の命令列の末尾の命令として記憶 */
                } else { /* 解析中の関数の命令列に1つ以上命令が存在する場合 */
                        codetl->next = tmp; /* 命令列の末尾に追加 */
                        codetl = tmp;       /* 命令列の末尾の命令として記憶 */
                }
                factorpush( retval ); /* 比較演算の結果をスタックにプッシュ */
        }
    break;

  case 67:
#line 857 "parser.y"
    {
                LLVMcode *tmp;             /* 生成した命令へのポインタ */
                Factor arg1, arg2, retval; /* 比較演算の引数・結果 */
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL;          /* 次の命令へのポインタを初期化 */
                tmp->command = Icmp;        /* 命令の種類を比較に設定 */
                arg2 = factorpop();        /* スタックから第2引数をポップ */
                arg1 = factorpop();       /* スタックから第1引数をポップ */
                retval.type = LOCAL_VAR;   /* 結果を格納するレジスタは局所 */
                retval.val = cntr;         /* 新規のレジスタ番号を取得 */
                cntr++;                   /* カウンタをインクリメント */
                (tmp->args).icmp.type = SLE; /* 比較演算子を<=に設定 */
                (tmp->args).icmp.arg1 = arg1; /* 命令の第1引数を指定 */
                (tmp->args).icmp.arg2 = arg2; /* 命令の第2引数を指定 */
                (tmp->args).icmp.retval = retval; /* 結果のレジスタを指定 */
                if( codetl == NULL ){ /* 解析中の関数の最初の命令の場合 */
                        decltl->codes = tmp;   /* 関数定義の命令列の先頭の命令に設定 */
                        codehd = codetl = tmp; /* 生成中の命令列の末尾の命令として記憶 */
                } else { /* 解析中の関数の命令列に1つ以上命令が存在する場合 */
                        codetl->next = tmp; /* 命令列の末尾に追加 */
                        codetl = tmp;       /* 命令列の末尾の命令として記憶 */
                }
                factorpush( retval ); /* 比較演算の結果をスタックにプッシュ */
        }
    break;

  case 68:
#line 882 "parser.y"
    {
                LLVMcode *tmp;             /* 生成した命令へのポインタ */
                Factor arg1, arg2, retval; /* 比較演算の引数・結果 */
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL;          /* 次の命令へのポインタを初期化 */
                tmp->command = Icmp;        /* 命令の種類を比較に設定 */
                arg2 = factorpop();        /* スタックから第2引数をポップ */
                arg1 = factorpop();       /* スタックから第1引数をポップ */
                retval.type = LOCAL_VAR;   /* 結果を格納するレジスタは局所 */
                retval.val = cntr;         /* 新規のレジスタ番号を取得 */
                cntr++;                   /* カウンタをインクリメント */
                (tmp->args).icmp.type = SGT; /* 比較演算子を>に設定 */
                (tmp->args).icmp.arg1 = arg1; /* 命令の第1引数を指定 */
                (tmp->args).icmp.arg2 = arg2; /* 命令の第2引数を指定 */
                (tmp->args).icmp.retval = retval; /* 結果のレジスタを指定 */
                if( codetl == NULL ){ /* 解析中の関数の最初の命令の場合 */
                        decltl->codes = tmp;   /* 関数定義の命令列の先頭の命令に設定 */
                        codehd = codetl = tmp; /* 生成中の命令列の末尾の命令として記憶 */
                } else { /* 解析中の関数の命令列に1つ以上命令が存在する場合 */
                        codetl->next = tmp; /* 命令列の末尾に追加 */
                        codetl = tmp;       /* 命令列の末尾の命令として記憶 */
                }
                factorpush( retval ); /* 比較演算の結果をスタックにプッシュ */
        }
    break;

  case 69:
#line 907 "parser.y"
    {
                LLVMcode *tmp;             /* 生成した命令へのポインタ */
                Factor arg1, arg2, retval; /* 比較演算の引数・結果 */
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL;          /* 次の命令へのポインタを初期化 */
                tmp->command = Icmp;        /* 命令の種類を比較に設定 */
                arg2 = factorpop();        /* スタックから第2引数をポップ */
                arg1 = factorpop();       /* スタックから第1引数をポップ */
                retval.type = LOCAL_VAR;   /* 結果を格納するレジスタは局所 */
                retval.val = cntr;         /* 新規のレジスタ番号を取得 */
                cntr++;                   /* カウンタをインクリメント */
                (tmp->args).icmp.type = SGE; /* 比較演算子を>=に設定 */
                (tmp->args).icmp.arg1 = arg1; /* 命令の第1引数を指定 */
                (tmp->args).icmp.arg2 = arg2; /* 命令の第2引数を指定 */
                (tmp->args).icmp.retval = retval; /* 結果のレジスタを指定 */
                if( codetl == NULL ){ /* 解析中の関数の最初の命令の場合 */
                        decltl->codes = tmp;   /* 関数定義の命令列の先頭の命令に設定 */
                        codehd = codetl = tmp; /* 生成中の命令列の末尾の命令として記憶 */
                } else { /* 解析中の関数の命令列に1つ以上命令が存在する場合 */
                        codetl->next = tmp; /* 命令列の末尾に追加 */
                        codetl = tmp;       /* 命令列の末尾の命令として記憶 */
                }
                factorpush( retval ); /* 比較演算の結果をスタックにプッシュ */
        }
    break;

  case 73:
#line 937 "parser.y"
    {
                LLVMcode *tmp;             /* 生成した命令へのポインタ */
                Factor arg1, arg2, retval; /* 加算の引数・結果 */
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL;          /* 次の命令へのポインタを初期化 */
                tmp->command = Add;        /* 命令の種類を加算に設定 */
                arg2 = factorpop();        /* スタックから第2引数をポップ */
                arg1 = factorpop();        /* スタックから第1引数をポップ */
                retval.type = LOCAL_VAR;   /* 結果を格納するレジスタは局所 */
                retval.val = cntr;         /* 新規のレジスタ番号を取得 */
                cntr++;                   /* カウンタをインクリメント */
                (tmp->args).add.arg1 = arg1; /* 命令の第1引数を指定 */
                (tmp->args).add.arg2 = arg2; /* 命令の第2引数を指定 */
                (tmp->args).add.retval = retval; /* 結果のレジスタを指定 */
                if( codetl == NULL ){ /* 解析中の関数の最初の命令の場合 */
                        
                        decltl->codes = tmp;   /* 関数定義の命令列の先頭の命令に設定 */
                        codehd = codetl = tmp; /* 生成中の命令列の末尾の命令として記憶 */
                } else { /* 解析中の関数の命令列に1つ以上命令が存在する場合 */
                        codetl->next = tmp; /* 命令列の末尾に追加 */
                        codetl = tmp;       /* 命令列の末尾の命令として記憶 */
                }
                factorpush( retval ); /* 加算の結果をスタックにプッシュ */
        }
    break;

  case 74:
#line 962 "parser.y"
    {
                LLVMcode *tmp;             /* 生成した命令へのポインタ */
                Factor arg1, arg2, retval; /* 減算の引数・結果 */
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL;          /* 次の命令へのポインタを初期化 */
                tmp->command = Sub;        /* 命令の種類を減算に設定 */
                arg2 = factorpop();        /* スタックから第2引数をポップ */
                arg1 = factorpop();        /* スタックから第1引数をポップ */
                retval.type = LOCAL_VAR;   /* 結果を格納するレジスタは局所 */
                retval.val = cntr;         /* 新規のレジスタ番号を取得 */
                cntr++;                   /* カウンタをインクリメント */
                (tmp->args).sub.arg1 = arg1; /* 命令の第1引数を指定 */
                (tmp->args).sub.arg2 = arg2; /* 命令の第2引数を指定 */
                (tmp->args).sub.retval = retval; /* 結果のレジスタを指定 */
                if( codetl == NULL ){ /* 解析中の関数の最初の命令の場合 */
                        
                        /*decltl->codes = tmp;*/   /* 関数定義の命令列の先頭の命令に設定 */
                        codehd = codetl = tmp; /* 生成中の命令列の末尾の命令として記憶 */
                } else { /* 解析中の関数の命令列に1つ以上命令が存在する場合 */
                        codetl->next = tmp; /* 命令列の末尾に追加 */
                        codetl = tmp;       /* 命令列の末尾の命令として記憶 */
                }
                factorpush( retval ); /* 減算の結果をスタックにプッシュ */
        }
    break;

  case 76:
#line 990 "parser.y"
    {
                LLVMcode *tmp;             /* 生成した命令へのポインタ */
                Factor arg1, arg2, retval; /* 乗算の引数・結果 */
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL;          /* 次の命令へのポインタを初期化 */
                tmp->command = Mul;        /* 命令の種類を乗算に設定 */
                arg2 = factorpop();        /* スタックから第2引数をポップ */
                arg1 = factorpop();        /* スタックから第1引数をポップ */
                retval.type = LOCAL_VAR;   /* 結果を格納するレジスタは局所 */
                retval.val = cntr;         /* 新規のレジスタ番号を取得 */
                cntr++;                   /* カウンタをインクリメント */
                (tmp->args).mul.arg1 = arg1; /* 命令の第1引数を指定 */
                (tmp->args).mul.arg2 = arg2; /* 命令の第2引数を指定 */
                (tmp->args).mul.retval = retval; /* 結果のレジスタを指定 */
                if( codetl == NULL ){ /* 解析中の関数の最初の命令の場合 */
                        
                        decltl->codes = tmp;   /* 関数定義の命令列の先頭の命令に設定 */
                        codehd = codetl = tmp; /* 生成中の命令列の末尾の命令として記憶 */
                } else { /* 解析中の関数の命令列に1つ以上命令が存在する場合 */
                        codetl->next = tmp; /* 命令列の末尾に追加 */
                        codetl = tmp;       /* 命令列の末尾の命令として記憶 */
                }
                factorpush( retval ); /* 乗算の結果をスタックにプッシュ */
        }
    break;

  case 77:
#line 1015 "parser.y"
    {
                LLVMcode *tmp;             /* 生成した命令へのポインタ */
                Factor arg1, arg2, retval; /* 除算の引数・結果 */
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL;          /* 次の命令へのポインタを初期化 */
                tmp->command = Div;        /* 命令の種類を除算に設定 */
                arg2 = factorpop();        /* スタックから第2引数をポップ */
                arg1 = factorpop();        /* スタックから第1引数をポップ */
                retval.type = LOCAL_VAR;   /* 結果を格納するレジスタは局所 */
                retval.val = cntr;         /* 新規のレジスタ番号を取得 */
                cntr++;                   /* カウンタをインクリメント */
                (tmp->args).div.arg1 = arg1; /* 命令の第1引数を指定 */
                (tmp->args).div.arg2 = arg2; /* 命令の第2引数を指定 */
                (tmp->args).div.retval = retval; /* 結果のレジスタを指定 */
                if( codetl == NULL ){ /* 解析中の関数の最初の命令の場合 */
                        
                        decltl->codes = tmp;   /* 関数定義の命令列の先頭の命令に設定 */
                        codehd = codetl = tmp; /* 生成中の命令列の末尾の命令として記憶 */
                } else { /* 解析中の関数の命令列に1つ以上命令が存在する場合 */
                        codetl->next = tmp; /* 命令列の末尾に追加 */
                        codetl = tmp;       /* 命令列の末尾の命令として記憶 */
                }
                factorpush( retval ); /* 除算の結果をスタックにプッシュ */
        }
    break;

  case 79:
#line 1043 "parser.y"
    { 
                Factor tmp;
                tmp.type = CONSTANT;
                tmp.vname[0] = EOF;
                tmp.val = (yyvsp[(1) - (1)].num);
                factorpush(tmp);
        }
    break;

  case 81:
#line 1054 "parser.y"
    {
                LLVMcode *tmp;             /* 生成した命令へのポインタ */
                Factor arg1, retval; /* ロードの引数・結果 */
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL;          /* 次の命令へのポインタを初期化 */
                tmp->command = Load;        /* 命令の種類をロードに設定 */
                arg1 = lookup_data((yyvsp[(1) - (1)].ident));        /* スタックから第1引数をポップ */
                retval.type = LOCAL_VAR;   /* 結果を格納するレジスタは局所 */
                retval.val = cntr;         /* 新規のレジスタ番号を取得 */
                cntr++;                   /* カウンタをインクリメント */
                (tmp->args).load.arg1 = arg1; /* 命令の第1引数を指定 */
                (tmp->args).load.retval = retval; /* 結果のレジスタを指定 */
                if( codetl == NULL ){ /* 解析中の関数の最初の命令の場合 */
                        
                        decltl->codes = tmp;   /* 関数定義の命令列の先頭の命令に設定 */
                        codehd = codetl = tmp; /* 生成中の命令列の末尾の命令として記憶 */
                } else { /* 解析中の関数の命令列に1つ以上命令が存在する場合 */
                        codetl->next = tmp; /* 命令列の末尾に追加 */
                        codetl = tmp;       /* 命令列の末尾の命令として記憶 */
                }
                factorpush( retval ); /* ロードの結果をスタックにプッシュ */
        }
    break;

  case 82:
#line 1085 "parser.y"
    {
                if(flag==GLOBAL_VAR){
                fprintf(yyout,"@%s = common global i32 0, align 4\n",(yyvsp[(1) - (1)].ident));
                }else if(flag==LOCAL_VAR){
                        LLVMcode *tmp;             /* 生成した命令へのポインタ */
                        Factor retval; /* allocaの結果 */
                        tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /* メモリ確保 */
                        tmp->next = NULL;          /* 次の命令へのポインタを初期化 */
                        tmp->command = Alloca;        /* 命令の種類をAllocaに設定 */
                        retval.type = LOCAL_VAR;   /* 結果を格納するレジスタは局所 */
                        strcpy(retval.vname,(yyvsp[(1) - (1)].ident));
                        retval.val = cntr;         /* 新規のレジスタ番号を取得 */
                        cntr++;                   /* カウンタをインクリメント */
                        (tmp->args).alloca.retval = retval; /* 結果のレジスタを指定 */
                        if( codetl == NULL ){ /* 解析中の関数の最初の命令の場合 */
                                decltl->codes = tmp;   /* 関数定義の命令列の先頭の命令に設定 */
                                codehd = codetl = tmp; /* 生成中の命令列の末尾の命令として記憶 */
                        } else { /* 解析中の関数の命令列に1つ以上命令が存在する場合 */
                                codetl->next = tmp; /* 命令列の末尾に追加 */
                                codetl = tmp;       /* 命令列の末尾の命令として記憶 */
                        }
                }
                insert_data((yyvsp[(1) - (1)].ident),flag,cntr-1);        
        }
    break;

  case 83:
#line 1110 "parser.y"
    {
                if(flag==GLOBAL_VAR){
                fprintf(yyout,"@%s = common global i32 0, align 4\n",(yyvsp[(3) - (3)].ident));
                }else if(flag==LOCAL_VAR){
                        LLVMcode *tmp;             /* 生成した命令へのポインタ */
                        Factor retval; /* allocaの結果 */
                        tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /* メモリ確保 */
                        tmp->next = NULL;          /* 次の命令へのポインタを初期化 */
                        tmp->command = Alloca;        /* 命令の種類をAllocaに設定 */
                        retval.type = LOCAL_VAR;   /* 結果を格納するレジスタは局所 */
                        retval.val = cntr;         /* 新規のレジスタ番号を取得 */
                        cntr++;                   /* カウンタをインクリメント */
                        (tmp->args).alloca.retval = retval; /* 結果のレジスタを指定 */
                        if( codetl == NULL ){ /* 解析中の関数の最初の命令の場合 */
                                decltl->codes = tmp;   /* 関数定義の命令列の先頭の命令に設定 */
                                codehd = codetl = tmp; /* 生成中の命令列の末尾の命令として記憶 */
                        } else { /* 解析中の関数の命令列に1つ以上命令が存在する場合 */
                                codetl->next = tmp; /* 命令列の末尾に追加 */
                                codetl = tmp;       /* 命令列の末尾の命令として記憶 */
                        }
                }
                
                insert_data((yyvsp[(3) - (3)].ident),flag,cntr-1);
        }
    break;


/* Line 1267 of yacc.c.  */
#line 2687 "y.tab.c"
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


#line 1135 "parser.y"
 
yyerror(char *s)
{
  fprintf(stderr, "%s line%d:%s\n", s,yylineno,yytext);
}

