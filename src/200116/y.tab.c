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
       int cnrt = 1;     /* レジスタ番号*/
	
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
    1,    2,    0,    3,    4,    4,    7,    7,    8,    5,
    5,   10,   10,   11,   12,   15,   13,   16,   14,   17,
   17,    6,    6,    6,    6,    6,    6,    6,    6,    6,
   27,   18,   30,   31,   19,   32,   32,   20,   33,   21,
   22,   34,   35,   24,   36,   25,   26,   23,   29,   29,
   29,   29,   29,   29,   28,   28,   28,   28,   28,   37,
   37,   37,   38,   38,   38,   40,   39,   41,    9,   42,
    9,
};
static const short yylen[] = {                            2,
    0,    0,    7,    3,    0,    2,    3,    1,    2,    0,
    2,    3,    1,    1,    4,    0,    2,    0,    3,    3,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    0,    4,    0,    0,    7,    2,    0,    4,    0,    9,
    1,    1,    0,    4,    0,    5,    4,    0,    3,    3,
    3,    3,    3,    3,    1,    2,    2,    3,    3,    1,
    3,    3,    1,    1,    3,    0,    2,    0,    2,    0,
    4,
};
static const short yydefred[] = {                         1,
    0,    0,    0,    2,    0,    0,    0,    0,    0,    0,
    8,   68,    0,    3,    0,    0,    0,   13,   14,    0,
   69,    0,   16,    0,   43,    0,   33,    0,    0,    0,
    0,    4,   22,   23,   24,   25,   26,   27,   28,   29,
   30,   41,    0,    7,   70,   17,   18,    0,   39,    0,
    0,    0,    0,    0,   64,   66,    0,    0,    0,   60,
   63,    0,    0,   12,   71,   15,    0,   21,    0,    0,
    0,   45,    0,    0,    0,   67,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   44,    0,    0,   34,    0,   65,    0,    0,    0,    0,
    0,    0,    0,    0,   38,   61,   62,   47,    0,   19,
   20,    0,    0,   46,    0,    0,    0,    0,   35,    0,
   36,   40,
};
static const short yydgoto[] = {                          1,
    2,    5,    8,    9,   16,   32,   10,   11,   13,   17,
   18,   19,   24,   66,   46,   67,   69,   33,   34,   35,
   36,   37,   38,   39,   40,   41,   63,   57,   58,   50,
  113,  119,   70,   42,   48,   95,   59,   60,   61,   76,
   21,   65,
};
static const short yysindex[] = {                         0,
    0, -259, -279,    0, -266, -245, -244, -230, -177, -202,
    0,    0, -174,    0, -175, -155, -173,    0,    0, -245,
    0, -164,    0, -153,    0, -156,    0, -131,  -37, -128,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -177,    0,    0,    0,    0, -155,    0,  -37,
 -132, -273, -273,  -37,    0,    0,  -13, -112, -148,    0,
    0,  -37, -119,    0,    0,    0, -245,    0, -255, -109,
 -111,    0, -148, -148, -271,    0, -273, -273,  -37,  -37,
  -37,  -37,  -37,  -37, -155, -273, -273, -179,  -37, -155,
    0, -155,  -37,    0, -105,    0, -148, -148, -113, -113,
 -113, -113, -113, -113,    0,    0,    0,    0, -113,    0,
    0, -140, -155,    0,  -37,  -79, -207, -155,    0, -155,
    0,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0, -218,    0,    0, -193,    0,
    0,    0, -106,    0,    0, -107,    0,    0,    0, -253,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -236,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -180,    0,    0,    0,    0, -254,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -137,    0,
    0,    0,    0,    0,    0,    0, -168,    0,    0,    0,
    0,    0, -110,  -83,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -243,    0,    0,    0,    0, -101,
    0, -254,    0,    0,    0,    0,  -56,  -29, -199, -183,
 -178, -161, -158, -150,    0,    0,    0,    0, -135,    0,
    0,    0, -243,    0,    0, -228,    0, -243,    0, -243,
    0,    0,
};
static const short yygindex[] = {                         0,
    0,    0,    0,  121,    0,  -48,    0,  169,    0,    0,
  149,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  -53,  143,    0,
    0,    0,    0,    0,    0,    0,    5,   79,    0,    0,
    0,    0,
};
#define YYTABLESIZE 269
static const short yytable[] = {                         68,
   75,   77,   78,    6,   91,   48,    3,    6,   88,   54,
    6,    6,   96,    6,    4,   48,   48,    6,    6,   55,
   56,    6,   42,   42,    7,   99,  100,  101,  102,  103,
  104,   37,   92,   48,    6,  109,  105,    6,    5,  112,
    6,  110,    5,  111,   48,    5,    5,   48,    5,   12,
  120,   42,    5,    5,   42,   31,   73,   74,   49,   37,
   14,  117,   37,   10,  116,   77,   78,   10,   49,  121,
   10,  122,    5,   10,   50,    5,   11,   10,   10,   52,
   11,   97,   98,   11,   50,   20,   11,   15,    5,   52,
   11,   11,    5,   77,   78,    5,   51,   10,    5,   54,
   10,   25,    5,    5,  108,   26,   51,   53,   27,   54,
   11,   28,   22,   11,   43,   29,   30,   53,   23,    5,
   55,   55,   55,   32,   32,    5,   86,   87,  115,   45,
   55,   55,   77,   78,   47,   55,   55,   49,   31,   55,
   55,   55,   55,   55,   55,   85,   55,   56,   56,   56,
   55,   51,   32,   55,   62,   32,   94,   56,   56,   77,
   78,   72,   56,   56,  106,  107,   56,   56,   56,   56,
   56,   56,   89,   56,   57,   57,   57,   56,  114,  118,
   56,    9,   93,   48,   57,   57,   48,   90,   44,   57,
   57,   64,   71,   57,   57,   57,   57,   57,   57,    0,
   57,   58,   58,   58,   57,    0,    0,   57,    0,    0,
    0,   58,   58,    0,    0,    0,   58,   58,    0,    0,
   58,   58,   58,   58,   58,   58,    0,   58,   59,   59,
   59,   58,    0,    0,   58,   52,   53,    0,   59,   59,
    0,    0,    0,   59,   59,   54,    0,   59,   59,   59,
   59,   59,   59,    0,   59,   55,   56,    0,   59,   77,
   78,   59,    0,   79,   80,   81,   82,   83,   84,
};
static const short yycheck[] = {                         48,
   54,  273,  274,  257,  260,  260,  266,  261,   62,  283,
  264,  265,  284,  267,  294,  259,  260,  271,  272,  293,
  294,  288,  259,  260,  270,   79,   80,   81,   82,   83,
   84,  260,  288,  288,  288,   89,   85,  291,  257,   93,
  294,   90,  261,   92,  288,  264,  265,  291,  267,  294,
  258,  288,  271,  272,  291,  292,   52,   53,  258,  288,
  291,  115,  291,  257,  113,  273,  274,  261,  268,  118,
  264,  120,  291,  267,  258,  294,  257,  271,  272,  258,
  261,   77,   78,  264,  268,  288,  267,  265,  257,  268,
  271,  272,  261,  273,  274,  264,  258,  291,  267,  258,
  294,  257,  271,  272,  284,  261,  268,  258,  264,  268,
  291,  267,  287,  294,  288,  271,  272,  268,  294,  288,
  258,  259,  260,  259,  260,  294,  275,  276,  269,  294,
  268,  269,  273,  274,  288,  273,  274,  294,  294,  277,
  278,  279,  280,  281,  282,  258,  284,  258,  259,  260,
  288,  283,  288,  291,  283,  291,  268,  268,  269,  273,
  274,  294,  273,  274,   86,   87,  277,  278,  279,  280,
  281,  282,  292,  284,  258,  259,  260,  288,  284,  259,
  291,  288,  292,  291,  268,  269,  288,   67,   20,  273,
  274,   43,   50,  277,  278,  279,  280,  281,  282,   -1,
  284,  258,  259,  260,  288,   -1,   -1,  291,   -1,   -1,
   -1,  268,  269,   -1,   -1,   -1,  273,  274,   -1,   -1,
  277,  278,  279,  280,  281,  282,   -1,  284,  258,  259,
  260,  288,   -1,   -1,  291,  273,  274,   -1,  268,  269,
   -1,   -1,   -1,  273,  274,  283,   -1,  277,  278,  279,
  280,  281,  282,   -1,  284,  293,  294,   -1,  288,  273,
  274,  291,   -1,  277,  278,  279,  280,  281,  282,
};
#define YYFINAL 1
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
"$$2 :",
"program : $$1 PROGRAM IDENT $$2 SEMICOLON outblock PERIOD",
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
"$$3 :",
"proc_name : IDENT $$3",
"$$4 :",
"inblock : $$4 var_decl_part statement",
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
"$$5 :",
"assignment_statement : IDENT $$5 ASSIGN expression",
"$$6 :",
"$$7 :",
"if_statement : IF $$6 condition THEN $$7 statement else_statement",
"else_statement : ELSE statement",
"else_statement :",
"while_statement : WHILE condition DO statement",
"$$8 :",
"for_statement : FOR IDENT $$8 ASSIGN expression TO expression DO statement",
"proc_call_statement : proc_call_name",
"proc_call_name : IDENT",
"$$9 :",
"block_statement : SBEGIN $$9 statement_list SEND",
"$$10 :",
"read_statement : READ LPAREN IDENT $$10 RPAREN",
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
"$$11 :",
"var_name : IDENT $$11",
"$$12 :",
"id_list : IDENT $$12",
"$$13 :",
"id_list : id_list COMMA IDENT $$13",

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
#line 886 "parser.y"
yyerror(char *s)
{
  fprintf(stderr, "%s line:%d token:%s\n", s ,yylineno,yytext);
}
#line 397 "y.tab.c"

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
                     /* 出力ファイルを書き込む部分 */
                     if((fp = fopen("result.ll","w")) == NULL){
                            fprintf(stderr, "result.llのオープンに失敗しました\n");
                            exit(1);
                     }
              }
break;
case 2:
#line 54 "parser.y"
	{
                            /* 大域変数を格納するfundeclを作るコード*/
                            Fundecl *new;
				new = (Fundecl *)malloc(sizeof(Fundecl)); /*メモリを動的に確保*/
				new->next = NULL;

                             /* 線形リストのポインタを更新 */
                            declhd = new;
                            decltl = new;
                            
                                   
                     }
break;
case 3:
#line 67 "parser.y"
	{      
	       	displayLLVMfundecl(declhd);
                     fclose(fp);
              }
break;
case 9:
#line 88 "parser.y"
	{
       }
break;
case 10:
#line 94 "parser.y"
	{ /* ここがメイン関数の入るところ*/
         
					printf("debug");
                                   Fundecl *mainfunc;
					mainfunc = (Fundecl *)malloc(sizeof(Fundecl)); /*メモリを動的に確保*/
					mainfunc->next = NULL;
                                   

                                   /* main関数のため，"main"を格納*/
					strcpy(mainfunc->fname,"main");

                                   /* 線形リストのポインタを更新 */
                                    if(decltl == NULL) {   /* 関数定義の線形リストの最初であるとき*/
                                          declhd = decltl = mainfunc;
                                   } else {             /* 関数定義の線形リストに1つ以上存在する時*/
                                          decltl->next = mainfunc;  /* 関数定義列の末尾に*newを追加*/
                                          decltl = mainfunc;        /* 関数定義列の末尾として*newを保存する*/
                                   }

                                   /* decltl->next = mainfunc;  // 関数定義列の末尾に*newを追加*/
                                   /* decltl = mainfunc;        // 関数定義列の末尾として*newを保存する*/

                                   /* codehdおよびcodetlのリセット */
                                   codehd = codetl = NULL;

                                   /* main関数をAllocaするコード*/
                                   LLVMcode* tmp;
                                   Factor retval;

                                   tmp = memoryGet(tmp); 

                                   tmp->command=Alloca;

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
                                   
                                   /* strcpy(arg1.vname,$1);*/
                                   arg1.type = CONSTANT;
                                   arg1.val = 0;

                                   /* factorpush(arg2);*/

                                   (tmp1->args).store.arg1 = arg1;
                                   (tmp1->args).store.arg2 = arg2;

                                   addList(tmp1);

       }
break;
case 15:
#line 175 "parser.y"
	{delete();}
break;
case 16:
#line 179 "parser.y"
	{flag = PROC_NAME; insert(yystack.l_mark[0].ident,flag);}
break;
case 17:
#line 180 "parser.y"
	{

		                     /*-----------------------------------------------------*/

                                   /* 以下プログラム名から関数のLLVMコードを生成するCプログラム*/
                                   /* このプログラムはProcedureがある場合のみ機能するので，main関数を含めることができない． */
                                   /* また，llvmcodesポインタの管理をまだ行っていない */
					
                                   Fundecl *new;
                                   
					new = (Fundecl *)malloc(sizeof(Fundecl)); /*メモリを動的に確保*/
					new->next = NULL;
                                   /* 関数名等を保存*/
                                   strcpy(new->fname,yystack.l_mark[-1].ident);
					                            
                                    /* 線形リストのポインタを更新 */
                                    if(decltl == NULL) {   /* 関数定義の線形リストの最初であるとき*/
                                          declhd = decltl = new;
                                   } else {             /* 関数定義の線形リストに1つ以上存在する時*/
                                          decltl->next = new;  /* 関数定義列の末尾に*newを追加*/
                                          decltl = new;        /* 関数定義列の末尾として*newを保存する*/
                                   
                                   }

                                   /* 新しい関数列ができたので，codehdとcodetlをnullにする*/
                                   codehd = codetl = NULL;
                                   /* decltl->next = new;  // 関数定義列の末尾に*newを追加*/
                                   /* decltl = new;        // 関数定義列の末尾として*newを保存する*/

                                   /* procedureをAllocaするコード*/
                                   LLVMcode* tmp;
                                   Factor retval;

                                   tmp = memoryGet(tmp); 

                                   tmp->command=Alloca;

                                   cnrt = 1; /* cnrtの初期化を行う*/

                                   retval.type = LOCAL_VAR;
                                   retval.val = cnrt;
                                   cnrt++;

                                   (tmp->args).alloca.retval = retval;
                                   
                                   factorpush(retval);

                                   addList(tmp);

                                   /* ----------------- */

                                   /* prodecureのコード番地をstoreするコード*/

                                   LLVMcode* tmp1;
                                   Factor arg1,arg2;

                                   tmp1 = memoryGet(tmp1); 

                                   tmp1->command=Store;

                                   arg2 = factorpop();  /* 局所変数%1を取り出す*/
                                   
                                   /* strcpy(arg1.vname,$1);*/
                                   arg1.type = CONSTANT;
                                   arg1.val = 0;

                                   /* factorpush(arg2);*/

                                   (tmp1->args).store.arg1 = arg1;
                                   (tmp1->args).store.arg2 = arg2;

                                   addList(tmp1);
					/*-----------------------------------------------------*/		
                                  
					
                            }
break;
case 18:
#line 259 "parser.y"
	{ flag = LOCAL_VAR; }
break;
case 31:
#line 282 "parser.y"
	{/* lookup($1); */ }
break;
case 32:
#line 284 "parser.y"
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

                                   factorpush(arg2);

                                   (tmp->args).store.arg1 = arg1;
                                   (tmp->args).store.arg2 = arg2;

                                   addList(tmp);
                                   
                                   /*----------------------------*/
                            }
break;
case 33:
#line 313 "parser.y"
	{           /*

                                   LLVMcode* tmp1,tmp2;
                                   int arg1,l;
                                   tmp1 = memoryGet(tmp1);
                                   tmp2 = memoryGet(tmp2);

                                   arg1 = l = cnrt;
                                   cnrt++;

                                   tmp1->command = BrUncond
                                   tmp2->command = Label

                                   (tmp->args).bruncond.arg1 = arg1;
                                   (tmp->args).label.l = l;

                                   addList(tmp1);
                                   addList(tmp2);
                                   ----------------------------*/

                     }
break;
case 34:
#line 334 "parser.y"
	{

                                   /*制御文を記述する*/

                                   LLVMcode* tmp;
                                   Factor arg1;
                                   int arg2;

                                   tmp = memoryGet(tmp); 

                                   tmp->command=BrCond;

                                   arg1 = factorpop();
                                   arg2 = cnrt;
                                   cnrt++;

                                   (tmp->args).brcond.arg1 = arg1;
                                   (tmp->args).brcond.arg2 = arg2;

                                   addList(tmp);
                                   brpush(tmp);
                                   
                                   /*----------------------------*/
       }
break;
case 39:
#line 371 "parser.y"
	{/* lookup($2); */ }
break;
case 42:
#line 379 "parser.y"
	{ /* lookup($1); */ }
break;
case 43:
#line 383 "parser.y"
	{ /* brcondとbruncondでどちらも記述しているが，それが正しいか確認する必要がある．*/
                                   if(bstack.top != 0){
                                          /*制御の始めのためラベルを格納する*/

                                          LLVMcode* tmp;
                                          int l;

                                          tmp = memoryGet(tmp); 

                                          tmp->command=Label;

                                          l = cnrt;
                                          cnrt++;

                                          (tmp->args).label.l = l;
                                          
                                          addList(tmp);
                                          
                                          LLVMcode* backpatch;

                                          if(bstack.top % 2 != 0){
                                                 backpatch = brpop();
                                                 if(backpatch->command == BrCond){
                                                        (backpatch->args).brcond.arg2 = l;
                                                 }else{
                                                        (backpatch->args).bruncond.arg1 = l;
                                                 } 
                                          }else{
                                                 backpatch = brpop();
                                                 (backpatch->args).brcond.arg3 = l; /* このパスは何故か通っていない。*/
                                          }
                                          
                                   }
                                   /*----------------------------*/
       }
break;
case 45:
#line 422 "parser.y"
	{ /* lookup($3);*/ }
break;
case 49:
#line 435 "parser.y"
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
case 50:
#line 468 "parser.y"
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
case 51:
#line 500 "parser.y"
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
case 52:
#line 532 "parser.y"
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
case 53:
#line 564 "parser.y"
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
case 54:
#line 596 "parser.y"
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
case 58:
#line 635 "parser.y"
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
case 59:
#line 659 "parser.y"
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
case 61:
#line 689 "parser.y"
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
case 62:
#line 713 "parser.y"
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
case 64:
#line 740 "parser.y"
	{
				 /*定数引数をスタックへプッシュする*/

				 Factor number;
				 number.val = (yystack.l_mark[0].num);
				 number.type = CONSTANT;
				 factorpush(number);
                             /*----------------------------*/
         }
break;
case 66:
#line 753 "parser.y"
	{ /* lookup($1);*/}
break;
case 67:
#line 755 "parser.y"
	{ 
                                   
                             /*与えられた引数を新引数をレジスタへ格納後スタック へプッシュする | Load*/
                             LLVMcode* tmp;

                             Factor arg1,retval;
                             tmp = memoryGet(tmp); 

                             tmp->command=Load;


                             /* 記号表から引数のデータを取得 */
                             lookup(yystack.l_mark[-1].ident);
                             strcpy(arg1.vname,yystack.l_mark[-1].ident);
                             arg1.type = varType;
                            

                             retval.type = LOCAL_VAR; /* 新規に変数を格納するのは局所変数 */
                             retval.val = cnrt;
                             cnrt++;

                             (tmp->args).load.arg1 = arg1;
                             (tmp->args).load.retval = retval;

                             addList(tmp);
                             
                             factorpush(retval);
				 
                             /*----------------------------*/
                            }
break;
case 68:
#line 795 "parser.y"
	{ insert(yystack.l_mark[0].ident,flag);}
break;
case 69:
#line 796 "parser.y"
	{ 
                                   LLVMcode* tmp;
                                   tmp = memoryGet(tmp); 
                                   Factor arg1,retval;

                                   switch(flag){
                                          case GLOBAL_VAR:
                                                 /* 大域変数を出力する*/
                                                 displayGlobalVar(yystack.l_mark[-1].ident);
                                                 break;
                                          
                                          case LOCAL_VAR:
                                          /*与えられた引数を新引数をレジスタへ格納後スタック へプッシュする | Load*/
                                                 

                                               /*  tmp->command=Load;*/


                                                 /* 記号表から引数のデータを取得 */
                                               /*  lookup($1);*/
                                               /*  strcpy(arg1.vname,$1);*/
                                               /*  arg1.type = varType;*/
                                                 

                                               /*  retval.type = LOCAL_VAR; /* 新規に変数を格納するのは局所変数 * /*/
                                               /*  retval.val = cnrt;*/
                                               /*  cnrt++;*/

                                               /*  (tmp->args).load.arg1 = arg1;*/
                                               /*  (tmp->args).load.retval = retval;*/

                                               /*  addList(tmp);*/
                                                 
                                               /*  factorpush(retval);*/
                                                 break;
                                   
                                          default:
                                                 break;
                                     
                                     }

                                   /*----------------------------*/
                            }
break;
case 70:
#line 841 "parser.y"
	{insert(yystack.l_mark[0].ident,flag);}
break;
case 71:
#line 842 "parser.y"
	{
                                   LLVMcode* tmp;
                                   tmp = memoryGet(tmp); 
                                   Factor arg1,retval;
                                   switch(flag){
                                          case GLOBAL_VAR:
                                                 /* 大域変数を出力する*/
                                                 displayGlobalVar(yystack.l_mark[-1].ident);
                                                 break;
                                          case LOCAL_VAR:
                                           /* 与えられた引数を新引数をレジスタへ格納後スタック へプッシュする | Load*/
                                                 

                                               /*  tmp->command=Load;*/


                                                 /* 記号表から引数のデータを取得 */
                                               /*  lookup($3);*/
                                               /*  strcpy(arg1.vname,$3);*/
                                               /*  arg1.type = LOCAL_VAR;*/
                                                 

                                               /*  retval.type = LOCAL_VAR; /* 新規に変数を格納するのは局所変数 * /*/
                                               /*  retval.val = cnrt;*/
                                               /*  cnrt++;*/

                                               /*  (tmp->args).load.arg1 = arg1;*/
                                               /*  (tmp->args).load.retval = retval;*/

                                               /*  addList(tmp);*/
                                                 
                                               /*  factorpush(retval);*/
                                                 break;
                                   
                                          default:
                                                 break;
                                  }


                                   /*----------------------------*/
                            }
break;
#line 1392 "y.tab.c"
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
