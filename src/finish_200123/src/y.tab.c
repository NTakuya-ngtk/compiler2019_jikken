#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20130304

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "parser.y"
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

#line 36 "parser.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
    int num;
    char ident[MAXLENGTH+1];
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 64 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define SBEGIN 257
#define DO 258
#define ELSE 259
#define SEND 260
#define FOR 261
#define FORWARD 262
#define FUNCTION 263
#define IF 264
#define PROCEDURE 265
#define PROGRAM 266
#define READ 267
#define THEN 268
#define TO 269
#define VAR 270
#define WHILE 271
#define WRITE 272
#define PLUS 273
#define MINUS 274
#define MULT 275
#define DIV 276
#define EQ 277
#define NEQ 278
#define LE 279
#define LT 280
#define GE 281
#define GT 282
#define LPAREN 283
#define RPAREN 284
#define LBRACKET 285
#define RBRACKET 286
#define COMMA 287
#define SEMICOLON 288
#define COLON 289
#define INTERVAL 290
#define PERIOD 291
#define ASSIGN 292
#define NUMBER 293
#define IDENT 294
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    1,    0,    6,    2,    3,    3,    7,    7,    8,    4,
    4,   10,   10,   11,   14,   12,   13,   15,   16,   16,
    5,    5,    5,    5,    5,    5,    5,    5,    5,   17,
   28,   29,   31,   18,   32,   30,   30,   33,   34,   35,
   36,   37,   19,   38,   39,   40,   41,   42,   43,   44,
   45,   46,   47,   48,   20,   50,   21,   49,   23,   24,
   25,   22,   27,   27,   27,   27,   27,   27,   26,   26,
   26,   26,   26,   51,   51,   51,   52,   52,   52,   53,
    9,    9,
};
static const short yylen[] = {                            2,
    0,    6,    0,    4,    2,    0,    3,    1,    2,    2,
    0,    3,    1,    1,    0,    5,    1,    2,    3,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    3,
    0,    0,    0,    8,    0,    3,    0,    0,    0,    0,
    0,    0,    9,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   19,    0,    2,    1,    3,    4,
    4,    0,    3,    3,    3,    3,    3,    3,    1,    2,
    2,    3,    3,    1,    3,    3,    1,    1,    3,    1,
    1,    3,
};
static const short yydefred[] = {                         0,
    0,    0,    1,    0,    0,    0,    0,    0,    0,    8,
   81,    0,    2,   15,    3,    0,   13,   14,    0,    0,
    0,    0,    0,    7,   82,   17,    0,    0,    0,    0,
    0,   38,    0,    0,    4,   21,   22,   23,   24,   25,
   26,   27,   28,   29,   56,   12,    0,   20,    0,    0,
    0,    0,    0,   78,   80,    0,   31,    0,   74,   77,
    0,   39,    0,    0,   57,    0,   16,   59,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   18,   19,
    0,   79,    0,    0,    0,    0,    0,    0,    0,    0,
   32,   75,   76,   60,   40,   61,    0,    0,    0,   45,
   33,   41,   46,    0,    0,    0,   34,    0,   42,    0,
    0,   43,   48,   36,   49,    0,   50,    0,   51,   52,
   53,   54,   55,
};
static const short yydgoto[] = {                          2,
    4,    7,    8,   15,   35,   22,    9,   10,   12,   16,
   17,   18,   27,   21,   67,   49,   36,   37,   38,   39,
   40,   41,   42,   43,   44,   56,   57,   82,  108,  117,
  114,  118,   62,   86,  109,  115,  122,  107,  113,  116,
  123,  125,  126,  128,  130,  131,  132,  133,   45,   65,
   58,   59,   60,
};
static const short yysindex[] = {                      -227,
 -279,    0,    0, -258, -247, -232, -244, -182, -193,    0,
    0, -176,    0,    0,    0, -174,    0,    0, -247, -204,
 -167, -154, -182,    0,    0,    0, -168, -154, -160,  -63,
 -148,    0, -147, -153,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -247,    0, -253, -145,
 -228, -228,  -63,    0,    0,   -5,    0, -207,    0,    0,
 -141,    0,  -63,  -63,    0, -154,    0,    0, -154,  -63,
 -207, -207, -265, -228, -228,  -63,  -63,  -63,  -63,  -63,
  -63, -112, -228, -228, -126,  -63, -199, -165,    0,    0,
 -165,    0, -207, -207, -165, -165, -165, -165, -165, -165,
    0,    0,    0,    0,    0,    0, -108, -154,  -96,    0,
    0,    0,    0,    0, -154,  -63,    0,  -93,    0, -165,
 -154,    0,    0,    0,    0,  -95,    0, -154,    0,    0,
    0,    0,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0, -215,    0,    0, -213,    0,    0,
    0, -121,    0,    0,    0,    0,    0,    0, -251,    0,
    0, -117, -175,    0,    0,    0,    0, -243,    0,    0,
    0,    0,    0, -257,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -173,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -136,    0,    0,
    0,    0,    0,    0,    0, -107,    0,    0, -243,    0,
 -109,  -82,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -255,    0,    0,
  -89,    0,  -55,  -21, -236, -205, -198, -197, -191, -156,
    0,    0,    0,    0,    0,    0,    0, -187,    0,    0,
    0,    0,    0, -134, -187,    0,    0,    0,    0,  -75,
 -187,    0,    0,    0,    0,    0,    0, -187,    0,    0,
    0,    0,    0,
};
static const short yygindex[] = {                         0,
    0,    0,  137,    0,  -28,    0,    0,  166,    0,    0,
  165,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  -52,  103,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   54,   47,    0,
};
#define YYTABLESIZE 277
static const short yytable[] = {                         48,
   73,   58,   58,   30,   30,    5,   68,   74,   75,    5,
   87,   88,    5,    5,    3,    5,   62,   91,   92,    5,
    5,   63,    6,   95,   96,   97,   98,   99,  100,    5,
   58,   63,   30,   58,   69,   30,    5,   89,    1,    5,
   90,    6,    5,   11,   62,    6,   13,   11,    6,    6,
   11,    6,   64,   11,   53,    6,    6,   11,   11,   66,
   65,   11,   64,  120,   54,   55,   68,   83,   84,   66,
   65,   62,   62,   74,   75,    6,   68,   11,    6,  111,
   11,   10,   14,    6,  106,   10,  119,    6,   10,   25,
    6,   10,  124,    6,   19,   10,   10,    6,    6,  129,
   62,   67,   28,   62,   71,   72,   29,   74,   75,   30,
   20,   67,   31,   23,    6,   10,   32,   33,   10,   47,
    6,   69,   69,   69,   35,   37,   26,   93,   94,  102,
  103,   69,   69,   50,   61,   63,   69,   69,   64,   34,
   69,   69,   69,   69,   69,   69,   70,   69,   70,   70,
   70,   69,   85,   37,   69,  101,   37,  104,   70,   70,
  110,  112,  127,   70,   70,  121,    9,   70,   70,   70,
   70,   70,   70,   62,   70,   71,   71,   71,   70,   44,
   62,   70,   47,   66,   24,   71,   71,   46,  105,    0,
   71,   71,    0,    0,   71,   71,   71,   71,   71,   71,
    0,   71,   72,   72,   72,   71,    0,    0,   71,   51,
   52,    0,   72,   72,    0,    0,    0,   72,   72,   53,
    0,   72,   72,   72,   72,   72,   72,    0,   72,   54,
   55,    0,   72,    0,    0,   72,   73,   73,   73,    0,
    0,    0,    0,    0,    0,    0,   73,   73,    0,    0,
    0,   73,   73,    0,    0,   73,   73,   73,   73,   73,
   73,    0,   73,    0,    0,    0,   73,   74,   75,   73,
    0,   76,   77,   78,   79,   80,   81,
};
static const short yycheck[] = {                         28,
   53,  259,  260,  259,  260,  257,  260,  273,  274,  261,
   63,   64,  264,  265,  294,  267,  260,   70,  284,  271,
  272,  258,  270,   76,   77,   78,   79,   80,   81,  288,
  288,  268,  288,  291,  288,  291,  288,   66,  266,  291,
   69,  257,  294,  257,  288,  261,  291,  261,  264,  265,
  264,  267,  258,  267,  283,  271,  272,  271,  272,  258,
  258,  294,  268,  116,  293,  294,  258,  275,  276,  268,
  268,  259,  260,  273,  274,  291,  268,  291,  294,  108,
  294,  257,  265,  257,  284,  261,  115,  261,  264,  294,
  264,  267,  121,  267,  288,  271,  272,  271,  272,  128,
  288,  258,  257,  291,   51,   52,  261,  273,  274,  264,
  287,  268,  267,  288,  288,  291,  271,  272,  294,  288,
  294,  258,  259,  260,  259,  260,  294,   74,   75,   83,
   84,  268,  269,  294,  283,  283,  273,  274,  292,  294,
  277,  278,  279,  280,  281,  282,  292,  284,  258,  259,
  260,  288,  294,  288,  291,  268,  291,  284,  268,  269,
  269,  258,  258,  273,  274,  259,  288,  277,  278,  279,
  280,  281,  282,  291,  284,  258,  259,  260,  288,  269,
  288,  291,  258,   47,   19,  268,  269,   23,   86,   -1,
  273,  274,   -1,   -1,  277,  278,  279,  280,  281,  282,
   -1,  284,  258,  259,  260,  288,   -1,   -1,  291,  273,
  274,   -1,  268,  269,   -1,   -1,   -1,  273,  274,  283,
   -1,  277,  278,  279,  280,  281,  282,   -1,  284,  293,
  294,   -1,  288,   -1,   -1,  291,  258,  259,  260,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  268,  269,   -1,   -1,
   -1,  273,  274,   -1,   -1,  277,  278,  279,  280,  281,
  282,   -1,  284,   -1,   -1,   -1,  288,  273,  274,  291,
   -1,  277,  278,  279,  280,  281,  282,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 294
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"SBEGIN","DO","ELSE","SEND","FOR",
"FORWARD","FUNCTION","IF","PROCEDURE","PROGRAM","READ","THEN","TO","VAR",
"WHILE","WRITE","PLUS","MINUS","MULT","DIV","EQ","NEQ","LE","LT","GE","GT",
"LPAREN","RPAREN","LBRACKET","RBRACKET","COMMA","SEMICOLON","COLON","INTERVAL",
"PERIOD","ASSIGN","NUMBER","IDENT",
};
static const char *yyrule[] = {
"$accept : program",
"$$1 :",
"program : PROGRAM IDENT $$1 SEMICOLON outblock PERIOD",
"$$2 :",
"outblock : var_decl_part subprog_decl_part $$2 statement",
"var_decl_part : var_decl_list SEMICOLON",
"var_decl_part :",
"var_decl_list : var_decl_list SEMICOLON var_decl",
"var_decl_list : var_decl",
"var_decl : VAR id_list",
"subprog_decl_part : subprog_decl_list SEMICOLON",
"subprog_decl_part :",
"subprog_decl_list : subprog_decl_list SEMICOLON subprog_decl",
"subprog_decl_list : subprog_decl",
"subprog_decl : proc_decl",
"$$3 :",
"proc_decl : PROCEDURE $$3 proc_name SEMICOLON inblock",
"proc_name : IDENT",
"inblock : var_decl_part statement",
"statement_list : statement_list SEMICOLON statement",
"statement_list : statement",
"statement : assignment_statement",
"statement : if_statement",
"statement : while_statement",
"statement : for_statement",
"statement : proc_call_statement",
"statement : null_statement",
"statement : block_statement",
"statement : read_statement",
"statement : write_statement",
"assignment_statement : IDENT ASSIGN expression",
"$$4 :",
"$$5 :",
"$$6 :",
"if_statement : IF condition $$4 THEN $$5 statement $$6 else_statement",
"$$7 :",
"else_statement : $$7 ELSE statement",
"else_statement :",
"$$8 :",
"$$9 :",
"$$10 :",
"$$11 :",
"$$12 :",
"while_statement : WHILE $$8 $$9 condition $$10 DO $$11 statement $$12",
"$$13 :",
"$$14 :",
"$$15 :",
"$$16 :",
"$$17 :",
"$$18 :",
"$$19 :",
"$$20 :",
"$$21 :",
"$$22 :",
"$$23 :",
"for_statement : FOR IDENT ASSIGN expression $$13 TO $$14 $$15 expression $$16 $$17 $$18 DO $$19 statement $$20 $$21 $$22 $$23",
"$$24 :",
"proc_call_statement : proc_call_name $$24",
"proc_call_name : IDENT",
"block_statement : SBEGIN statement_list SEND",
"read_statement : READ LPAREN IDENT RPAREN",
"write_statement : WRITE LPAREN expression RPAREN",
"null_statement :",
"condition : expression EQ expression",
"condition : expression NEQ expression",
"condition : expression LT expression",
"condition : expression LE expression",
"condition : expression GT expression",
"condition : expression GE expression",
"expression : term",
"expression : PLUS term",
"expression : MINUS term",
"expression : expression PLUS term",
"expression : expression MINUS term",
"term : factor",
"term : term MULT factor",
"term : term DIV factor",
"factor : var_name",
"factor : NUMBER",
"factor : LPAREN expression RPAREN",
"var_name : IDENT",
"id_list : IDENT",
"id_list : id_list COMMA IDENT",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  500
#endif
#endif

#define YYINITSTACKSIZE 500

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 1135 "parser.y"
 
yyerror(char *s)
{
  fprintf(stderr, "%s line%d:%s\n", s,yylineno,yytext);
}
#line 430 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (short *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack)) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 60 "parser.y"
	{
                 init_fstack();
                 insert_data(yystack.l_mark[0].ident,PROC_NAME,0);
                 
         }
break;
case 2:
#line 66 "parser.y"
	{
                displayLlvmfundecl(declhd);
        }
break;
case 3:
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
case 15:
#line 131 "parser.y"
	{flag = LOCAL_VAR;}
break;
case 16:
#line 133 "parser.y"
	{
                delete_data(); 
                flag = GLOBAL_VAR;
                cntr=1;
        }
break;
case 17:
#line 141 "parser.y"
	{
                Fundecl *func;
                func =(Fundecl *)malloc(sizeof(Fundecl));
                strcpy(func->fname,yystack.l_mark[0].ident);
                func->ret = 0;
                codehd = codetl = func->codes;
                if(declhd == NULL){
                        declhd = decltl = func;
                }else{
                        decltl->next = func;
                        decltl = func;
                }
                insert_data(yystack.l_mark[0].ident,PROC_NAME,0);
                
                

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
case 30:
#line 196 "parser.y"
	{
                
                 
                LLVMcode *tmp;             /* 生成した命令へのポインタ */
                Factor arg1, arg2; /* ストアの引数・結果 */
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL;          /* 次の命令へのポインタを初期化 */
                tmp->command = Store;        /* 命令の種類をストアに設定 */
                arg1 = factorpop();        /* スタックから第2引数をポップ */
                arg2 = lookup_data(yystack.l_mark[-2].ident);        /* スタックから第1引数をポップ */
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
case 31:
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
case 32:
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
case 33:
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
case 35:
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
case 36:
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
case 37:
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
case 38:
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
case 39:
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
case 40:
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
case 41:
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
case 42:
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
case 43:
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
case 44:
#line 443 "parser.y"
	{
                
                LLVMcode *tmp;             /* 生成した命令へのポインタ */
                Factor arg1, arg2; /* ストアの引数・結果 */
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL;          /* 次の命令へのポインタを初期化 */
                tmp->command = Store;        /* 命令の種類をストアに設定 */
                arg1 = factorpop();        /* スタックから第2引数をポップ */
                arg2 = lookup_data(yystack.l_mark[-2].ident);        /* スタックから第1引数をポップ */
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
case 45:
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
case 46:
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
case 47:
#line 497 "parser.y"
	{
                

                LLVMcode *tmp;             /* 生成した命令へのポインタ */
                Factor arg1, retval; /* ロードの引数・結果 */
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL;          /* 次の命令へのポインタを初期化 */
                tmp->command = Load;        /* 命令の種類をロードに設定 */
                arg1 = lookup_data(yystack.l_mark[-7].ident);        /* スタックから第1引数をポップ */
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
case 48:
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
case 49:
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
case 50:
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
case 51:
#line 584 "parser.y"
	{
                LLVMcode *tmp;             /* 生成した命令へのポインタ */
                Factor arg1, retval; /* ロードの引数・結果 */
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL;          /* 次の命令へのポインタを初期化 */
                tmp->command = Load;        /* 命令の種類をロードに設定 */
                arg1 = lookup_data(yystack.l_mark[-13].ident);        /* スタックから第1引数をポップ */
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
case 52:
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
case 53:
#line 630 "parser.y"
	{
                LLVMcode *tmp;             /* 生成した命令へのポインタ */
                Factor arg1, arg2; /* ストアの引数・結果 */
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL;          /* 次の命令へのポインタを初期化 */
                tmp->command = Store;        /* 命令の種類をストアに設定 */
                arg1 = factorpop();        /* スタックから第2引数をポップ */
                arg2 = lookup_data(yystack.l_mark[-15].ident);        /* スタックから第1引数をポップ */
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
case 54:
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
case 55:
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
case 56:
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
case 57:
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
case 58:
#line 716 "parser.y"
	{
                LLVMcode *tmp;             /* 生成した命令へのポインタ */
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL;          /* 次の命令へのポインタを初期化 */
                tmp->command = Call;        /* 命令の種類を加算に設定 */
                strcpy((tmp->args).call.name,yystack.l_mark[0].ident)   ; /* 結果のレジスタを指定 */  
                if( codetl == NULL ){ /* 解析中の関数の最初の命令の場合 */
                        decltl->codes = tmp;   /* 関数定義の命令列の先頭の命令に設定 */
                        codehd = codetl = tmp; /* 生成中の命令列の末尾の命令として記憶 */
                } else { /* 解析中の関数の命令列に1つ以上命令が存在する場合 */
                        codetl->next = tmp; /* 命令列の末尾に追加 */
                        codetl = tmp;       /* 命令列の末尾の命令として記憶 */
                }
        }
break;
case 60:
#line 737 "parser.y"
	{
                LLVMcode *tmp;             /* 生成した命令へのポインタ */
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL;          /* 次の命令へのポインタを初期化 */
                tmp->command = Read;        /* 命令の種類を加算に設定 */
                (tmp->args).read.arg1 = lookup_data(yystack.l_mark[-1].ident); /* 結果のレジスタを指定 */  
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
case 61:
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
case 63:
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
case 64:
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
case 65:
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
case 66:
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
case 67:
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
case 68:
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
case 72:
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
case 73:
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
case 75:
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
case 76:
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
case 78:
#line 1043 "parser.y"
	{ 
                Factor tmp;
                tmp.type = CONSTANT;
                tmp.vname[0] = EOF;
                tmp.val = yystack.l_mark[0].num;
                factorpush(tmp);
        }
break;
case 80:
#line 1054 "parser.y"
	{
                LLVMcode *tmp;             /* 生成した命令へのポインタ */
                Factor arg1, retval; /* ロードの引数・結果 */
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL;          /* 次の命令へのポインタを初期化 */
                tmp->command = Load;        /* 命令の種類をロードに設定 */
                arg1 = lookup_data(yystack.l_mark[0].ident);        /* スタックから第1引数をポップ */
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
case 81:
#line 1085 "parser.y"
	{
                if(flag==GLOBAL_VAR){
                fprintf(yyout,"@%s = common global i32 0, align 4\n",yystack.l_mark[0].ident);
                }else if(flag==LOCAL_VAR){
                        LLVMcode *tmp;             /* 生成した命令へのポインタ */
                        Factor retval; /* allocaの結果 */
                        tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /* メモリ確保 */
                        tmp->next = NULL;          /* 次の命令へのポインタを初期化 */
                        tmp->command = Alloca;        /* 命令の種類をAllocaに設定 */
                        retval.type = LOCAL_VAR;   /* 結果を格納するレジスタは局所 */
                        strcpy(retval.vname,yystack.l_mark[0].ident);
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
                insert_data(yystack.l_mark[0].ident,flag,cntr-1);        
        }
break;
case 82:
#line 1110 "parser.y"
	{
                if(flag==GLOBAL_VAR){
                fprintf(yyout,"@%s = common global i32 0, align 4\n",yystack.l_mark[0].ident);
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
                
                insert_data(yystack.l_mark[0].ident,flag,cntr-1);
        }
break;
#line 1720 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (short) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
