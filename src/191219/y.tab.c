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
#include "symbol.h"
#include "symbol.c"
#include "createllvm.h"
#include "createllvm.c"

  extern int yylineno;
  extern char *yytext;

	Scope flag = GLOBAL_VAR;
	init_fstack();  /* スタックの初期化を行う*/

	
#line 23 "parser.y"
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
#line 51 "y.tab.c"

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
    9,    9,   10,   11,   12,   14,   13,   15,   15,    5,
    5,    5,    5,    5,    5,    5,    5,    5,   25,   16,
   17,   28,   28,   18,   29,   19,   20,   30,   22,   31,
   23,   24,   21,   27,   27,   27,   27,   27,   27,   26,
   26,   26,   26,   26,   32,   32,   32,   33,   33,   33,
   35,   34,    8,    8,
};
static const short yylen[] = {                            2,
    0,    6,    3,    0,    2,    3,    1,    2,    0,    2,
    3,    1,    1,    4,    1,    0,    3,    3,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    0,    4,
    5,    2,    0,    4,    0,    9,    1,    1,    3,    0,
    5,    4,    0,    3,    3,    3,    3,    3,    3,    1,
    2,    2,    3,    3,    1,    3,    3,    1,    1,    3,
    0,    2,    1,    3,
};
static const short yydefred[] = {                         0,
    0,    0,    1,    0,    0,    0,    0,    0,    0,    7,
   63,    0,    2,    0,    0,    0,   12,   13,    0,    0,
   15,    0,    0,    0,    0,    0,    0,    0,    0,    3,
   20,   21,   22,   23,   24,   25,   26,   27,   28,   37,
    0,    6,   64,   16,   19,    0,   35,    0,    0,    0,
   59,   61,    0,    0,    0,   55,   58,    0,    0,    0,
    0,   11,   14,    0,   39,    0,    0,    0,    0,    0,
   62,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   40,    0,    0,    0,    0,   18,    0,   60,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   56,
   57,    0,   34,   42,    0,   17,    0,    0,   31,   41,
    0,   32,    0,    0,   36,
};
static const short yydgoto[] = {                          2,
    4,    7,    8,   15,   30,    9,   10,   12,   16,   17,
   18,   22,   63,   64,   46,   31,   32,   33,   34,   35,
   36,   37,   38,   39,   61,   53,   54,  109,   67,   40,
  102,   55,   56,   57,   71,
};
static const short yysindex[] = {                      -246,
 -263,    0,    0, -234, -214, -224, -233, -205, -199,    0,
    0, -188,    0, -187, -167, -178,    0,    0, -214, -176,
    0, -162, -167, -164,  -45, -138,  -45, -134,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -205,    0,    0,    0,    0, -180,    0, -216, -216,  -45,
    0,    0,  -21, -130, -268,    0,    0, -137,  -86,  -45,
 -116,    0,    0, -214,    0, -167, -113, -268, -268, -153,
    0, -216, -216,  -45,  -45,  -45,  -45,  -45,  -45, -167,
 -216, -216,    0, -167, -126,  -45, -167,    0,  -45,    0,
 -268, -268, -260, -260, -260, -260, -260, -260,  -85,    0,
    0,  -92,    0,    0, -260,    0,  -89, -167,    0,    0,
  -45,    0, -157, -167,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0, -223,    0,    0, -198,    0,    0,
    0,  -90,    0,    0,  -88,    0,    0,    0, -255,    0,
    0,    0, -177,    0,    0,    0,    0,    0, -241,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -185,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -145,    0,    0,    0,    0,    0,
    0,    0,    0, -169,    0, -177,    0, -118,  -91,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -256,
    0,    0,    0, -256,    0,    0,  -82,    0,    0,    0,
  -64,  -37, -253, -193, -146, -114,  -93,  -87, -207,    0,
    0,    0,    0,    0, -236,    0,    0, -256,    0,    0,
    0,    0,    0, -256,    0,
};
static const short yygindex[] = {                         0,
    0,    0,  135,    0,  -23,    0,  182,    0,    0,  161,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  -49,  180,    0,    0,    0,
    0,  -27,   71,    0,    0,
};
#define YYTABLESIZE 261
static const short yytable[] = {                         45,
   70,    5,   43,   43,   44,    5,   81,   82,    5,    5,
   85,    5,   72,   73,   44,    5,    5,   38,   38,    1,
   68,   69,   30,   30,   93,   94,   95,   96,   97,   98,
    3,   43,    5,    4,   43,    5,  105,    4,    5,  107,
    4,    4,   88,    4,   91,   92,   38,    4,    4,   38,
   29,   30,   33,    5,   30,    6,   99,   13,    9,   14,
  103,  113,    9,  106,   45,    9,   50,    4,    9,   11,
    4,   10,    9,    9,   45,   10,   51,   52,   10,   65,
   33,   10,   43,   33,  112,   10,   10,    4,   19,   23,
  115,    4,    9,   24,    4,    9,   25,    4,   20,   26,
  114,    4,    4,   27,   28,   10,   21,   66,   10,   41,
   43,   47,   50,   50,   50,   72,   73,   43,    4,   72,
   73,   47,   50,   50,    4,   44,   29,   50,   50,   47,
   90,   50,   50,   50,   50,   50,   50,   80,   50,   51,
   51,   51,   50,   46,   58,   50,   72,   73,   60,   51,
   51,  100,  101,   46,   51,   51,   83,  104,   51,   51,
   51,   51,   51,   51,   49,   51,   52,   52,   52,   51,
   48,   84,   51,  108,   49,   86,   52,   52,   89,  111,
   48,   52,   52,   72,   73,   52,   52,   52,   52,   52,
   52,  110,   52,   53,   53,   53,   52,    8,   87,   52,
   42,   62,   43,   53,   53,   43,   59,    0,   53,   53,
    0,    0,   53,   53,   53,   53,   53,   53,    0,   53,
   54,   54,   54,   53,    0,    0,   53,   48,   49,    0,
   54,   54,    0,    0,    0,   54,   54,   50,    0,   54,
   54,   54,   54,   54,   54,    0,   54,   51,   52,    0,
   54,   72,   73,   54,    0,   74,   75,   76,   77,   78,
   79,
};
static const short yycheck[] = {                         23,
   50,  257,  259,  260,  258,  261,  275,  276,  264,  265,
   60,  267,  273,  274,  268,  271,  272,  259,  260,  266,
   48,   49,  259,  260,   74,   75,   76,   77,   78,   79,
  294,  288,  288,  257,  291,  291,   86,  261,  294,   89,
  264,  265,   66,  267,   72,   73,  288,  271,  272,  291,
  292,  288,  260,  288,  291,  270,   80,  291,  257,  265,
   84,  111,  261,   87,  258,  264,  283,  291,  267,  294,
  294,  257,  271,  272,  268,  261,  293,  294,  264,  260,
  288,  267,  260,  291,  108,  271,  272,  257,  288,  257,
  114,  261,  291,  261,  264,  294,  264,  267,  287,  267,
  258,  271,  272,  271,  272,  291,  294,  288,  294,  288,
  288,  258,  258,  259,  260,  273,  274,  294,  288,  273,
  274,  268,  268,  269,  294,  288,  294,  273,  274,  294,
  284,  277,  278,  279,  280,  281,  282,  268,  284,  258,
  259,  260,  288,  258,  283,  291,  273,  274,  283,  268,
  269,   81,   82,  268,  273,  274,  294,  284,  277,  278,
  279,  280,  281,  282,  258,  284,  258,  259,  260,  288,
  258,  258,  291,  259,  268,  292,  268,  269,  292,  269,
  268,  273,  274,  273,  274,  277,  278,  279,  280,  281,
  282,  284,  284,  258,  259,  260,  288,  288,   64,  291,
   19,   41,  291,  268,  269,  288,   27,   -1,  273,  274,
   -1,   -1,  277,  278,  279,  280,  281,  282,   -1,  284,
  258,  259,  260,  288,   -1,   -1,  291,  273,  274,   -1,
  268,  269,   -1,   -1,   -1,  273,  274,  283,   -1,  277,
  278,  279,  280,  281,  282,   -1,  284,  293,  294,   -1,
  288,  273,  274,  291,   -1,  277,  278,  279,  280,  281,
  282,
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
"proc_name : IDENT",
"$$2 :",
"inblock : $$2 var_decl_part statement",
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
"$$3 :",
"assignment_statement : IDENT $$3 ASSIGN expression",
"if_statement : IF condition THEN statement else_statement",
"else_statement : ELSE statement",
"else_statement :",
"while_statement : WHILE condition DO statement",
"$$4 :",
"for_statement : FOR IDENT $$4 ASSIGN expression TO expression DO statement",
"proc_call_statement : proc_call_name",
"proc_call_name : IDENT",
"block_statement : SBEGIN statement_list SEND",
"$$5 :",
"read_statement : READ LPAREN IDENT $$5 RPAREN",
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
"$$6 :",
"var_name : IDENT $$6",
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
#line 254 "parser.y"
yyerror(char *s)
{
  fprintf(stderr, "%s line:%d token:%s\n", s ,yylineno,yytext);
}
#line 382 "y.tab.c"

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
#line 46 "parser.y"
	{
					/* 以下プログラム名からmain関数のLLVMコードを生成するCプログラム*/
					Fundecl *new;
					new = (Fundecl *)malloc(sizeof(Fundecl)); /*メモリ確保*/
					/*最初の1つ目のプログラムであるため、hdもtlも初期化*/
					declhd = new;   
					decltl = new; 
					new->next = NULL;
					
					new.fname = "main";
					
					/* あとから決定される*/
					 new->codes = codehd;
					/* あとから決定される */
					new->next = NULL;
					/*-----------------------------------------------------*/
					
          }
break;
case 2:
#line 63 "parser.y"
	{
						displayLLVMfundecl(declhd);
          }
break;
case 14:
#line 101 "parser.y"
	{delete();}
break;
case 15:
#line 105 "parser.y"
	{flag = PROC_NAME; insert(yystack.l_mark[0].ident,flag);}
break;
case 16:
#line 109 "parser.y"
	{flag = LOCAL_VAR;}
break;
case 29:
#line 130 "parser.y"
	{lookup(yystack.l_mark[0].ident);}
break;
case 35:
#line 147 "parser.y"
	{lookup(yystack.l_mark[0].ident);}
break;
case 38:
#line 155 "parser.y"
	{ lookup(yystack.l_mark[0].ident);}
break;
case 40:
#line 163 "parser.y"
	{ lookup(yystack.l_mark[0].ident); }
break;
case 53:
#line 188 "parser.y"
	{
				 /* 加算命令をLLVMコードとして生成するCプログラム */
				 LLVMcode *tmp;            /*生成した命令へのポインタ*/
				 Factor arg1, arg2,retval; /*加算の引数、結果*/
				 memoryGet(*tmp);          /*mallocによるメモリ確保*/
				 /*↑もしかしたら返り値として*tmpにしないといけないかもしれない*/

				 tmp->command = Add;
				 arg2 = factorpop();       /*スタックから第2引数をポップ*/
				 arg1 = factorpop();       /*スタックから第1引数をポップ*/
				 retval.type = LOCAL_VAR;  /*結果を格納するレジスタは局所変数*/
				 retval.val = cnrt;        /* 新規のレジスタ番号を取得*/
				 cnrt++;

				 (tmp->args).add.arg1 = arg1;   /* 命令の第1引数を指定 */
				 (tmp->args).add.arg2 = arg2;   /* 命令の第2引数を指定 */
				 (tmp->args).add.retval = retval; /* 結果のレジスタを指定*/

				 addList(*tmp);                /* 新規命令として、命令列へ追加する*/
				 /* ↑もしかしら戻り値が何かしら必要かもしれない */
				 
				 factorpush( retval );       /* 加算の結果をスタックへプッシュ*/

				 /*-----------------------------------------*/
			 }
break;
case 59:
#line 224 "parser.y"
	{
				 /*定数引数をスタックへプッシュする*/
				 Factor number;
				 number.val = (yystack.l_mark[0].num);
				 number.type = CONSTANT;
				 factorpush(yystack.l_mark[0].num);
         }
break;
case 61:
#line 235 "parser.y"
	{ lookup(yystack.l_mark[0].ident);}
break;
case 62:
#line 235 "parser.y"
	{
				 /*変数引数をスタックへプッシュする*/
				 /**/
				 /*工事中*/
				 /**/
         }
break;
case 63:
#line 249 "parser.y"
	{ insert(yystack.l_mark[0].ident,flag);}
break;
case 64:
#line 250 "parser.y"
	{insert(yystack.l_mark[0].ident,flag);}
break;
#line 702 "y.tab.c"
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
