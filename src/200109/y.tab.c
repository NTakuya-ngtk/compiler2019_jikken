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
#include <string.h>
#include "symbol.h"
#include "symbol.c"
#include "createllvm.h"
#include "createllvm.c"

  extern int yylineno;
  extern char *yytext;

	Scope flag = GLOBAL_VAR;
	/*init_fstack();  // スタックの初期化を行う*/
       int cnrt = 0;     /* レジスタ番号*/
	
#line 24 "parser.y"
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
#line 52 "y.tab.c"

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
    1,    0,    2,    3,    3,    6,    6,    7,    4,    4,
    9,    9,   10,   11,   14,   12,   15,   13,   16,   16,
    5,    5,    5,    5,    5,    5,    5,    5,    5,   26,
   17,   18,   29,   29,   19,   30,   20,   21,   31,   32,
   23,   33,   24,   25,   22,   28,   28,   28,   28,   28,
   28,   27,   27,   27,   27,   27,   34,   34,   34,   35,
   35,   35,   37,   36,   38,    8,   39,    8,
};
static const short yylen[] = {                            2,
    0,    6,    3,    0,    2,    3,    1,    2,    0,    2,
    3,    1,    1,    4,    0,    2,    0,    3,    3,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    0,
    4,    5,    2,    0,    4,    0,    9,    1,    1,    0,
    4,    0,    5,    4,    0,    3,    3,    3,    3,    3,
    3,    1,    2,    2,    3,    3,    1,    3,    3,    1,
    1,    3,    0,    2,    0,    2,    0,    4,
};
static const short yydefred[] = {                         0,
    0,    0,    1,    0,    0,    0,    0,    0,    0,    7,
   65,    0,    2,    0,    0,    0,   12,   13,    0,   66,
    0,   15,    0,   40,    0,    0,    0,    0,    0,    0,
    3,   21,   22,   23,   24,   25,   26,   27,   28,   29,
   38,    0,    6,   67,   16,   17,    0,   36,    0,    0,
    0,   61,   63,    0,    0,    0,   57,   60,    0,    0,
    0,    0,   11,   68,   14,    0,   20,    0,    0,    0,
    0,    0,   64,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   42,    0,    0,    0,    0,   41,
    0,    0,   62,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   58,   59,    0,   35,   44,    0,   18,   19,
    0,    0,   32,   43,    0,   33,    0,    0,   37,
};
static const short yydgoto[] = {                          2,
    4,    7,    8,   15,   31,    9,   10,   12,   16,   17,
   18,   23,   65,   45,   66,   68,   32,   33,   34,   35,
   36,   37,   38,   39,   40,   62,   54,   55,  113,   69,
   41,   47,  105,   56,   57,   58,   73,   20,   64,
};
static const short yysindex[] = {                      -264,
 -273,    0,    0, -262, -232, -236, -212, -201, -196,    0,
    0, -193,    0, -177, -151, -169,    0,    0, -232,    0,
 -166,    0, -149,    0, -152,  -33, -124,  -33, -123,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, -201,    0,    0,    0,    0, -151,    0, -220, -220,
  -33,    0,    0,   -9, -118, -153,    0,    0, -130,  -97,
  -33, -127,    0,    0,    0, -232,    0, -245, -126, -153,
 -153, -265,    0, -220, -220,  -33,  -33,  -33,  -33,  -33,
  -33, -151, -220, -220,    0, -151, -197,  -33, -151,    0,
 -151,  -33,    0, -153, -153, -162, -162, -162, -162, -162,
 -162,  -90,    0,    0, -114,    0,    0, -162,    0,    0,
 -140, -151,    0,    0,  -33,    0, -246, -151,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0, -205,    0,    0, -189,    0,    0,
    0, -111,    0,    0, -108,    0,    0,    0, -254,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -237,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, -176,    0,    0,    0,    0, -235,    0,    0,    0,
    0,    0,    0,    0,    0, -133,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -164,    0,    0,    0, -106,
  -79,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, -255,    0,    0,    0, -255,    0,    0, -104,    0,
 -235,    0,    0,  -52,  -25, -252, -244, -227, -178, -159,
 -154, -259,    0,    0,    0,    0,    0, -190,    0,    0,
    0, -255,    0,    0,    0,    0,    0, -255,    0,
};
static const short yygindex[] = {                         0,
    0,    0,  120,    0,  -47,    0,  168,    0,    0,  146,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  -31,  163,    0,    0,
    0,    0,    0,   82,   54,    0,    0,    0,    0,
};
#define YYTABLESIZE 273
static const short yytable[] = {                         67,
   34,    1,    5,   45,   45,   46,    5,   74,   75,    5,
    5,  118,    5,   47,   90,   46,    5,    5,   93,   72,
    3,   39,   39,   47,   45,    5,   74,   75,   34,   87,
   49,   34,   45,    5,  102,   45,    5,    6,  106,    5,
   49,  109,   91,  110,   96,   97,   98,   99,  100,  101,
   39,    4,   45,   39,   30,    4,  108,   11,    4,    4,
  111,    4,   51,   14,  116,    4,    4,    9,   31,   31,
  119,    9,   52,   53,    9,   74,   75,    9,   13,   48,
   10,    9,    9,  117,   10,    4,  107,   10,    4,   48,
   10,   19,    4,   21,   10,   10,    4,   31,   51,    4,
   31,    9,    4,   50,    9,   24,    4,    4,   51,   25,
   74,   75,   26,   50,   10,   27,   22,   10,   42,   28,
   29,   83,   84,    4,   52,   52,   52,   44,  115,    4,
   70,   71,   74,   75,   52,   52,  103,  104,   46,   52,
   52,   48,   30,   52,   52,   52,   52,   52,   52,   82,
   52,   53,   53,   53,   52,   94,   95,   52,   59,   61,
   86,   53,   53,   85,   88,   92,   53,   53,  112,  114,
   53,   53,   53,   53,   53,   53,    8,   53,   54,   54,
   54,   53,   45,   45,   53,   89,   43,   63,   54,   54,
   60,    0,    0,   54,   54,    0,    0,   54,   54,   54,
   54,   54,   54,    0,   54,   55,   55,   55,   54,    0,
    0,   54,    0,    0,    0,   55,   55,    0,    0,    0,
   55,   55,    0,    0,   55,   55,   55,   55,   55,   55,
    0,   55,   56,   56,   56,   55,    0,    0,   55,   49,
   50,    0,   56,   56,    0,    0,    0,   56,   56,   51,
    0,   56,   56,   56,   56,   56,   56,    0,   56,   52,
   53,    0,   56,   74,   75,   56,    0,   76,   77,   78,
   79,   80,   81,
};
static const short yycheck[] = {                         47,
  260,  266,  257,  259,  260,  258,  261,  273,  274,  264,
  265,  258,  267,  258,  260,  268,  271,  272,  284,   51,
  294,  259,  260,  268,  260,  288,  273,  274,  288,   61,
  258,  291,  288,  288,   82,  291,  291,  270,   86,  294,
  268,   89,  288,   91,   76,   77,   78,   79,   80,   81,
  288,  257,  288,  291,  292,  261,   88,  294,  264,  265,
   92,  267,  283,  265,  112,  271,  272,  257,  259,  260,
  118,  261,  293,  294,  264,  273,  274,  267,  291,  258,
  257,  271,  272,  115,  261,  291,  284,  264,  294,  268,
  267,  288,  257,  287,  271,  272,  261,  288,  258,  264,
  291,  291,  267,  258,  294,  257,  271,  272,  268,  261,
  273,  274,  264,  268,  291,  267,  294,  294,  288,  271,
  272,  275,  276,  288,  258,  259,  260,  294,  269,  294,
   49,   50,  273,  274,  268,  269,   83,   84,  288,  273,
  274,  294,  294,  277,  278,  279,  280,  281,  282,  268,
  284,  258,  259,  260,  288,   74,   75,  291,  283,  283,
  258,  268,  269,  294,  292,  292,  273,  274,  259,  284,
  277,  278,  279,  280,  281,  282,  288,  284,  258,  259,
  260,  288,  291,  288,  291,   66,   19,   42,  268,  269,
   28,   -1,   -1,  273,  274,   -1,   -1,  277,  278,  279,
  280,  281,  282,   -1,  284,  258,  259,  260,  288,   -1,
   -1,  291,   -1,   -1,   -1,  268,  269,   -1,   -1,   -1,
  273,  274,   -1,   -1,  277,  278,  279,  280,  281,  282,
   -1,  284,  258,  259,  260,  288,   -1,   -1,  291,  273,
  274,   -1,  268,  269,   -1,   -1,   -1,  273,  274,  283,
   -1,  277,  278,  279,  280,  281,  282,   -1,  284,  293,
  294,   -1,  288,  273,  274,  291,   -1,  277,  278,  279,
  280,  281,  282,
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
"outblock : var_decl_part subprog_decl_part statement",
"var_decl_part :",
"var_decl_part : var_decl_list SEMICOLON",
"var_decl_list : var_decl_list SEMICOLON var_decl",
"var_decl_list : var_decl",
"var_decl : VAR id_list",
"subprog_decl_part :",
"subprog_decl_part : subprog_decl_list SEMICOLON",
"subprog_decl_list : subprog_decl_list SEMICOLON subprog_decl",
"subprog_decl_list : subprog_decl",
"subprog_decl : proc_decl",
"proc_decl : PROCEDURE proc_name SEMICOLON inblock",
"$$2 :",
"proc_name : IDENT $$2",
"$$3 :",
"inblock : $$3 var_decl_part statement",
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
"$$4 :",
"assignment_statement : IDENT $$4 ASSIGN expression",
"if_statement : IF condition THEN statement else_statement",
"else_statement : ELSE statement",
"else_statement :",
"while_statement : WHILE condition DO statement",
"$$5 :",
"for_statement : FOR IDENT $$5 ASSIGN expression TO expression DO statement",
"proc_call_statement : proc_call_name",
"proc_call_name : IDENT",
"$$6 :",
"block_statement : SBEGIN $$6 statement_list SEND",
"$$7 :",
"read_statement : READ LPAREN IDENT $$7 RPAREN",
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
"$$8 :",
"var_name : IDENT $$8",
"$$9 :",
"id_list : IDENT $$9",
"$$10 :",
"id_list : id_list COMMA IDENT $$10",

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
#line 435 "parser.y"
yyerror(char *s)
{
  fprintf(stderr, "%s line:%d token:%s\n", s ,yylineno,yytext);
}
#line 389 "y.tab.c"

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
#line 47 "parser.y"
	{

               		       /*-----------------------------------------------------*/


                                   /* 大域変数を格納するfundeclを作るコード*/
					
                                   Fundecl *new;
					new = (Fundecl *)malloc(sizeof(Fundecl)); /*メモリを動的に確保*/
					new->next = NULL;
                                   

                                   /* 初回はmain関数のため，"main"を格納*/
					strcpy(new->fname,"main");

                                    /* 線形リストのポインタを更新 */

                                   if(decltl == NULL) {   /* 関数定義の線形リストの最初であるとき*/
                                          declhd = decltl = new;
                                   } else {             /* 関数定義の線形リストに1つ以上存在する時*/
                                          decltl->next = new;  /* 関数定義列の末尾に*newを追加*/
                                          decltl = new;        /* 関数定義列の末尾として*newを保存する*/
                                   
				       /*-----------------------------------------------------*/
                                   }
                            }
break;
case 2:
#line 73 "parser.y"
	{

		displayLLVMfundecl(declhd);
          }
break;
case 8:
#line 94 "parser.y"
	{
        }
break;
case 14:
#line 113 "parser.y"
	{delete();}
break;
case 15:
#line 117 "parser.y"
	{flag = PROC_NAME; insert(yystack.l_mark[0].ident,flag);}
break;
case 16:
#line 118 "parser.y"
	{

		                     /*-----------------------------------------------------*/


                                   /* 以下プログラム名から関数のLLVMコードを生成するCプログラム*/
                                   /* このプログラムはProcedureがある場合のみ機能するので，main関数を含めることができていない */
					
                                   Fundecl *new;
					new = (Fundecl *)malloc(sizeof(Fundecl)); /*メモリを動的に確保*/
					new->next = NULL;
                                   
                                   /* 関数名等を保存*/
                                   strcpy(new->fname,yystack.l_mark[-1].ident);
					
                            
                                    /* 線形リストのポインタを更新 */

                                   if(decltl == NULL){  /* 関数定義の線形リストの最初であるとき*/
                                         declhd = decltl = new;
                                   } else {             /* 関数定義の線形リストに1つ以上存在する時*/
                                          decltl->next = new;  /* 関数定義列の末尾に*newを追加*/
                                          decltl = new;        /* 関数定義列の末尾として*newを保存する*/

                                   };
					

					/*-----------------------------------------------------*/		
                                  
					
                            }
break;
case 17:
#line 152 "parser.y"
	{ flag = LOCAL_VAR; }
break;
case 30:
#line 173 "parser.y"
	{lookup(yystack.l_mark[0].ident);}
break;
case 31:
#line 174 "parser.y"
	{
                                   /*変数引数をスタックからpopしてレジスタへ格納する ｜Store*/

                                   LLVMcode* tmp;
                                   Factor arg1,arg2;

                                   tmp = memoryGet(tmp); 

                                   tmp->command=Store;

                                   arg1 = factorpop(); 
                                   
                                   strcpy(arg2.vname,yystack.l_mark[-3].ident);
                                   arg2.type = flag;
                                   arg2.val = cnrt;
                                   cnrt++;

                                   factorpush(arg2);

                                   (tmp->args).store.arg1 = arg1;
                                   (tmp->args).store.arg2 = arg2;

                                   addList(tmp);
                                   
                                   /*----------------------------*/
                            }
break;
case 36:
#line 217 "parser.y"
	{lookup(yystack.l_mark[0].ident);}
break;
case 39:
#line 225 "parser.y"
	{ lookup(yystack.l_mark[0].ident);}
break;
case 40:
#line 229 "parser.y"
	{
                     /* ここが，ブロックのはじめであるため，関数の書き出しを行うなら，ここであると考えらえれる*/
       }
break;
case 42:
#line 236 "parser.y"
	{ lookup(yystack.l_mark[0].ident); }
break;
case 55:
#line 262 "parser.y"
	{
				 /* 加算命令をLLVMコードとして生成するCプログラム */
				 LLVMcode *tmp;                /*生成した命令へのポインタ*/
				 Factor arg1, arg2,retval;      /*加算の引数、結果*/
				 tmp = memoryGet(tmp);          /*mallocによるメモリ確保*/

				 tmp->command = Add;
				 arg2 = factorpop();       /*スタックから第2引数をポップ*/
				 arg1 = factorpop();       /*スタックから第1引数をポップ*/
				 retval.type = LOCAL_VAR;  /*結果を格納するレジスタは局所変数*/
				 retval.val = cnrt;        /* 新規のレジスタ番号を取得*/
				 cnrt++;

				 (tmp->args).add.arg1 = arg1;   /* 命令の第1引数を指定 */
				 (tmp->args).add.arg2 = arg2;   /* 命令の第2引数を指定 */
				 (tmp->args).add.retval = retval; /* 結果のレジスタを指定*/

				 addList(tmp);                /* 新規命令として、命令列へ追加する*/
				 
				 factorpush( retval );       /* 加算の結果をスタックへプッシュ*/

				 /*-----------------------------------------*/
			 }
break;
case 56:
#line 286 "parser.y"
	{
                            
                            /* 減算命令をLLVMコードとして生成するCプログラム */
				 LLVMcode *tmp;                /*生成した命令へのポインタ*/
				 Factor arg1, arg2,retval;      /*減算の引数、結果*/
				 tmp = memoryGet(tmp);          /*mallocによるメモリ確保*/

				 tmp->command = Sub;
				 arg2 = factorpop();       /*スタックから第2引数をポップ*/
				 arg1 = factorpop();       /*スタックから第1引数をポップ*/
				 retval.type = LOCAL_VAR;  /*結果を格納するレジスタは局所変数*/
				 retval.val = cnrt;        /* 新規のレジスタ番号を取得*/
				 cnrt++;

				 (tmp->args).add.arg1 = arg1;   /* 命令の第1引数を指定 */
				 (tmp->args).add.arg2 = arg2;   /* 命令の第2引数を指定 */
				 (tmp->args).add.retval = retval; /* 結果のレジスタを指定*/

				 addList(tmp);                /* 新規命令として、命令列へ追加する*/
				 
				 factorpush( retval );       /* 減算の結果をスタックへプッシュ*/

				 /*-----------------------------------------*/

                     }
break;
case 58:
#line 316 "parser.y"
	{
                            /* 乗算命令をLLVMコードとして生成するCプログラム */
				 LLVMcode *tmp;               /*生成した命令へのポインタ*/
				 Factor arg1, arg2,retval;      /*乗算の引数、結果*/
				 tmp = memoryGet(tmp);          /*mallocによるメモリ確保*/

				 tmp->command = Mul;
				 arg2 = factorpop();       /*スタックから第2引数をポップ*/
				 arg1 = factorpop();       /*スタックから第1引数をポップ*/
				 retval.type = LOCAL_VAR;  /*結果を格納するレジスタは局所変数*/
				 retval.val = cnrt;        /* 新規のレジスタ番号を取得*/
				 cnrt++;

				 (tmp->args).add.arg1 = arg1;   /* 命令の第1引数を指定 */
				 (tmp->args).add.arg2 = arg2;   /* 命令の第2引数を指定 */
				 (tmp->args).add.retval = retval; /* 結果のレジスタを指定*/

				 addList(tmp);                /* 新規命令として、命令列へ追加する*/
				 
				 factorpush( retval );       /* 乗算の結果をスタックへプッシュ*/

				 /*-----------------------------------------*/
                     }
break;
case 59:
#line 340 "parser.y"
	{
                            /* 除算命令をLLVMコードとして生成するCプログラム */
				 LLVMcode *tmp;             /*生成した命令へのポインタ*/
				 Factor arg1, arg2,retval;      /*除算の引数、結果*/
				 tmp = memoryGet(tmp);          /*mallocによるメモリ確保*/

				 tmp->command = Div;
				 arg2 = factorpop();       /*スタックから第2引数をポップ*/
				 arg1 = factorpop();       /*スタックから第1引数をポップ*/
				 retval.type = LOCAL_VAR;  /*結果を格納するレジスタは局所変数*/
				 retval.val = cnrt;        /* 新規のレジスタ番号を取得*/
				 cnrt++;

				 (tmp->args).add.arg1 = arg1;   /* 命令の第1引数を指定 */
				 (tmp->args).add.arg2 = arg2;   /* 命令の第2引数を指定 */
				 (tmp->args).add.retval = retval; /* 結果のレジスタを指定*/

				 addList(tmp);                /* 新規命令として、命令列へ追加する*/
				 
				 factorpush( retval );       /* 除算の結果をスタックへプッシュ*/

				 /*-----------------------------------------*/
                     }
break;
case 61:
#line 367 "parser.y"
	{
				 /*定数引数をスタックへプッシュする*/

				 Factor number;
				 number.val = (yystack.l_mark[0].num);
				 number.type = CONSTANT;
				 factorpush(number);
                             /*----------------------------*/
         }
break;
case 63:
#line 380 "parser.y"
	{ lookup(yystack.l_mark[0].ident);}
break;
case 64:
#line 382 "parser.y"
	{ 
                                   
                             /*引数をスタック からポップして，新引数をレジスタへ格納後スタック へプッシュする | Load*/
                             LLVMcode* tmp;
                             Factor arg1,retval;
                             tmp = memoryGet(tmp); 

                             tmp->command=Load;
                             
                             arg1 = factorpop();

                             retval.type = flag;
                             retval.val = cnrt;
                             cnrt++;

                             (tmp->args).load.arg1 = arg1;
                             (tmp->args).load.retval = retval;

                             addList(tmp);
                             
                             factorpush(retval);
				 
                             /*----------------------------*/
                            }
break;
case 65:
#line 416 "parser.y"
	{ insert(yystack.l_mark[0].ident,flag);}
break;
case 66:
#line 417 "parser.y"
	{
                                   /* 大域変数を出力する*/
                                   displayGlobalVar(yystack.l_mark[-1].ident);

                                   /*----------------------------*/
                            }
break;
case 67:
#line 425 "parser.y"
	{insert(yystack.l_mark[0].ident,flag);}
break;
case 68:
#line 426 "parser.y"
	{
                                  /* 大域変数を出力する*/
                                   displayGlobalVar(yystack.l_mark[-1].ident);

                                   /*----------------------------*/
                            }
break;
#line 908 "y.tab.c"
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
