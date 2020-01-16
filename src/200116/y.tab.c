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
    1,    2,    4,    0,    3,    5,    5,    8,    8,    9,
    6,    6,   11,   11,   12,   13,   16,   14,   17,   15,
   18,   18,    7,    7,    7,    7,    7,    7,    7,    7,
    7,   28,   19,   31,   32,   20,   34,   33,   33,   35,
   36,   21,   37,   38,   39,   22,   23,   40,   25,   41,
   26,   27,   24,   30,   30,   30,   30,   30,   30,   29,
   29,   29,   29,   29,   42,   42,   42,   43,   43,   43,
   45,   44,   46,   10,   47,   10,
};
static const short yylen[] = {                            2,
    0,    0,    0,    8,    3,    0,    2,    3,    1,    2,
    0,    2,    3,    1,    1,    4,    0,    2,    0,    3,
    3,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    0,    4,    0,    0,    7,    0,    3,    0,    0,
    0,    6,    0,    0,    0,   11,    1,    1,    3,    0,
    5,    4,    0,    3,    3,    3,    3,    3,    3,    1,
    2,    2,    3,    3,    1,    3,    3,    1,    1,    3,
    0,    2,    0,    2,    0,    4,
};
static const short yydefred[] = {                         1,
    0,    0,    0,    2,    0,    0,    0,    3,    0,    0,
    9,   73,    0,    0,    0,    0,    0,   14,   15,    0,
   74,    0,    4,   17,    0,    0,    0,    0,    0,   40,
    0,    0,    5,   23,   24,   25,   26,   27,   28,   29,
   30,   31,   47,    0,    8,   75,   18,   19,   22,    0,
   43,    0,    0,    0,   69,   71,    0,   34,    0,   65,
   68,    0,    0,    0,    0,   13,   76,   16,    0,   49,
    0,    0,    0,    0,    0,   72,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   50,   41,    0,
    0,    0,   21,    0,   70,    0,    0,    0,    0,    0,
    0,    0,    0,   35,   66,   67,    0,    0,   52,    0,
   20,    0,    0,   51,    0,    0,    0,   42,    0,   37,
   36,    0,    0,    0,   38,    0,   46,
};
static const short yydgoto[] = {                          1,
    2,    5,    8,   14,    9,   16,   33,   10,   11,   13,
   17,   18,   19,   25,   68,   47,   69,   50,   34,   35,
   36,   37,   38,   39,   40,   41,   42,   65,   57,   58,
   85,  113,  121,  123,   63,  108,   72,  116,  124,   43,
  107,   59,   60,   61,   76,   21,   67,
};
static const short yysindex[] = {                         0,
    0, -260, -293,    0, -274, -235, -256,    0, -186, -242,
    0,    0, -206, -208, -192, -140, -178,    0,    0, -235,
    0, -174,    0,    0, -166, -140, -165, -148, -193,    0,
 -167,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -186,    0,    0,    0,    0,    0, -244,
    0, -268, -268, -148,    0,    0,    3,    0, -171,    0,
    0, -160, -148, -148, -164,    0,    0,    0, -235,    0,
 -140, -152, -171, -171, -265,    0, -268, -268, -148, -148,
 -148, -148, -148, -148, -127, -268, -268,    0,    0, -200,
 -148, -140,    0, -148,    0, -171, -171, -252, -252, -252,
 -252, -252, -252,    0,    0,    0, -142, -109,    0, -252,
    0, -252, -140,    0, -140, -119, -108,    0, -148,    0,
    0, -252, -140, -103,    0, -140,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0, -214,    0,    0, -196,    0,
    0,    0, -126,    0,    0, -123,    0,    0,    0, -254,
    0,    0,    0,    0,    0, -240,    0,    0,    0,    0,
    0, -236,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -179,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -121,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -158,    0,
 -240,    0,  -94,  -67,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, -117,    0,    0,    0,  -40,  -13, -209, -204, -198,
 -172, -157, -135,    0,    0,    0,    0,    0,    0, -255,
    0, -100, -197,    0, -197,    0, -219,    0,    0,    0,
    0,  -86, -197,    0,    0, -197,    0,
};
static const short yygindex[] = {                         0,
    0,    0,    0,    0,  104,    0,  -26,    0,  156,    0,
    0,  133,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  -52,  115,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   66,   21,    0,    0,    0,    0,
};
#define YYTABLESIZE 285
static const short yytable[] = {                         49,
    4,   75,    7,   33,   33,    3,    7,   77,   78,    7,
    7,   90,    7,    6,   54,   70,    7,    7,   95,   53,
   77,   78,   48,   48,   55,   56,   98,   99,  100,  101,
  102,  103,   33,    7,    7,   33,    7,   12,  110,    7,
   39,  112,    6,   71,   93,   20,    6,   53,   54,    6,
    6,   48,    6,   55,   48,   32,    6,    6,   54,   57,
   11,   53,   53,   55,   11,  111,  122,   11,   39,   57,
   11,   39,   77,   78,   11,   11,    6,   12,   15,    6,
   22,   12,   23,  109,   12,   56,  117,   12,  118,   62,
   53,   12,   12,   53,   11,   56,  125,   11,    6,  127,
   59,   24,    6,   86,   87,    6,  105,  106,    6,   44,
   59,   12,    6,    6,   12,   64,   26,   73,   74,   46,
   27,   48,   58,   28,   52,   53,   29,   91,   51,    6,
   30,   31,   58,   88,   54,    6,   60,   60,   60,   94,
  104,  114,   96,   97,   55,   56,   60,   60,  115,  119,
  120,   60,   60,   32,  126,   60,   60,   60,   60,   60,
   60,   10,   60,   61,   61,   61,   60,   53,   44,   60,
   53,   45,   92,   61,   61,   45,   66,   89,   61,   61,
    0,    0,   61,   61,   61,   61,   61,   61,    0,   61,
   62,   62,   62,   61,    0,    0,   61,    0,    0,    0,
   62,   62,    0,    0,    0,   62,   62,    0,    0,   62,
   62,   62,   62,   62,   62,    0,   62,   63,   63,   63,
   62,    0,    0,   62,    0,    0,    0,   63,   63,    0,
    0,    0,   63,   63,    0,    0,   63,   63,   63,   63,
   63,   63,    0,   63,   64,   64,   64,   63,    0,    0,
   63,    0,    0,    0,   64,   64,    0,    0,    0,   64,
   64,    0,    0,   64,   64,   64,   64,   64,   64,    0,
   64,    0,    0,    0,   64,   77,   78,   64,    0,   79,
   80,   81,   82,   83,   84,
};
static const short yycheck[] = {                         26,
  294,   54,  257,  259,  260,  266,  261,  273,  274,  264,
  265,   64,  267,  288,  283,  260,  271,  272,  284,  260,
  273,  274,  259,  260,  293,  294,   79,   80,   81,   82,
   83,   84,  288,  288,  270,  291,  291,  294,   91,  294,
  260,   94,  257,  288,   71,  288,  261,  288,  258,  264,
  265,  288,  267,  258,  291,  292,  271,  272,  268,  258,
  257,  259,  260,  268,  261,   92,  119,  264,  288,  268,
  267,  291,  273,  274,  271,  272,  291,  257,  265,  294,
  287,  261,  291,  284,  264,  258,  113,  267,  115,  283,
  288,  271,  272,  291,  291,  268,  123,  294,  257,  126,
  258,  294,  261,  275,  276,  264,   86,   87,  267,  288,
  268,  291,  271,  272,  294,  283,  257,   52,   53,  294,
  261,  288,  258,  264,  273,  274,  267,  292,  294,  288,
  271,  272,  268,  294,  283,  294,  258,  259,  260,  292,
  268,  284,   77,   78,  293,  294,  268,  269,  258,  269,
  259,  273,  274,  294,  258,  277,  278,  279,  280,  281,
  282,  288,  284,  258,  259,  260,  288,  291,  269,  291,
  288,  258,   69,  268,  269,   20,   44,   63,  273,  274,
   -1,   -1,  277,  278,  279,  280,  281,  282,   -1,  284,
  258,  259,  260,  288,   -1,   -1,  291,   -1,   -1,   -1,
  268,  269,   -1,   -1,   -1,  273,  274,   -1,   -1,  277,
  278,  279,  280,  281,  282,   -1,  284,  258,  259,  260,
  288,   -1,   -1,  291,   -1,   -1,   -1,  268,  269,   -1,
   -1,   -1,  273,  274,   -1,   -1,  277,  278,  279,  280,
  281,  282,   -1,  284,  258,  259,  260,  288,   -1,   -1,
  291,   -1,   -1,   -1,  268,  269,   -1,   -1,   -1,  273,
  274,   -1,   -1,  277,  278,  279,  280,  281,  282,   -1,
  284,   -1,   -1,   -1,  288,  273,  274,  291,   -1,  277,
  278,  279,  280,  281,  282,
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
"$$3 :",
"program : $$1 PROGRAM IDENT $$2 SEMICOLON outblock $$3 PERIOD",
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
"$$4 :",
"proc_name : IDENT $$4",
"$$5 :",
"inblock : $$5 var_decl_part statement",
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
"$$6 :",
"assignment_statement : IDENT $$6 ASSIGN expression",
"$$7 :",
"$$8 :",
"if_statement : IF condition $$7 THEN $$8 statement else_statement",
"$$9 :",
"else_statement : ELSE $$9 statement",
"else_statement :",
"$$10 :",
"$$11 :",
"while_statement : WHILE $$10 condition $$11 DO statement",
"$$12 :",
"$$13 :",
"$$14 :",
"for_statement : FOR IDENT $$12 ASSIGN expression $$13 TO expression $$14 DO statement",
"proc_call_statement : proc_call_name",
"proc_call_name : IDENT",
"block_statement : SBEGIN statement_list SEND",
"$$15 :",
"read_statement : READ LPAREN IDENT $$15 RPAREN",
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
"$$16 :",
"var_name : IDENT $$16",
"$$17 :",
"id_list : IDENT $$17",
"$$18 :",
"id_list : id_list COMMA IDENT $$18",

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
#line 1435 "parser.y"
yyerror(char *s)
{
  fprintf(stderr, "%s line:%d token:%s\n", s ,yylineno,yytext);
}
#line 406 "y.tab.c"

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
case 4:
#line 86 "parser.y"
	{      
	       	displayLLVMfundecl(declhd);
                     fclose(fp);
              }
break;
case 10:
#line 107 "parser.y"
	{
       }
break;
case 11:
#line 113 "parser.y"
	{ /* ここがメイン関数の入るところ*/
         
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
                                   cnrt = 1; /* cnrtの初期化を行う*/

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
                                   arg1.val = 0; /* 記号表の番地を代入する*/

                                   /* factorpush(arg2);*/

                                   (tmp1->args).store.arg1 = arg1;
                                   (tmp1->args).store.arg2 = arg2;

                                   addList(tmp1);

       }
break;
case 12:
#line 181 "parser.y"
	{ /* ここがメイン関数の入るところ*/
         
					/* printf("debug");*/
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
                                   cnrt = 1; /* cnrtの初期化を行う*/

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
                                   arg1.val = 0; /* 記号表の番地を代入する*/

                                   /* factorpush(arg2);*/

                                   (tmp1->args).store.arg1 = arg1;
                                   (tmp1->args).store.arg2 = arg2;

                                   addList(tmp1);

       }
break;
case 16:
#line 262 "parser.y"
	{delete();}
break;
case 17:
#line 266 "parser.y"
	{flag = PROC_NAME; insert(yystack.l_mark[0].ident,flag);}
break;
case 18:
#line 267 "parser.y"
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

                                   /* LLVMcode* tmp1;*/
                                   /* Factor arg1,arg2;*/

                                   /* tmp1 = memoryGet(tmp1); */

                                   /* tmp1->command=Store;*/

                                   /* arg2 = factorpop();  /* 局所変数%1を取り出す* /*/
                                   
                                   /* strcpy(arg1.vname,$1);*/
                                   /* arg1.type = CONSTANT;*/
                                   /* arg1.val = 0;        /* 記号表の番地を代入する * /       */

                                   /* factorpush(arg2);*/

                                   /* (tmp1->args).store.arg1 = arg1;*/
                                   /* (tmp1->args).store.arg2 = arg2;*/

                                   /* addList(tmp1);*/
					/*-----------------------------------------------------*/		
                                  
					
                            }
break;
case 19:
#line 346 "parser.y"
	{ flag = LOCAL_VAR; }
break;
case 20:
#line 348 "parser.y"
	{  
                                   /* procedureからRetするコード*/
                                   LLVMcode* tmp;
                                   Factor arg1;

                                   tmp = memoryGet(tmp); 

                                   tmp->command=Ret;

                                   arg1.type = CONSTANT;
                                   arg1.val = 0; /* 記号表から持って来る*/

                                   (tmp->args).ret.arg1 = arg1;
                                   addList(tmp);
                                   }
break;
case 32:
#line 384 "parser.y"
	{/* lookup($1); */ }
break;
case 33:
#line 386 "parser.y"
	{
                                  /*変数引数をスタックからpopしてレジスタへ格納する ｜Store*/

                                   LLVMcode* tmp;
                                   Factor arg1,arg2;

                                   tmp = memoryGet(tmp); 

                                   tmp->command=Store;

                                   arg1 = factorpop(); 
                                    
                                   strcpy(arg2.vname,yystack.l_mark[-3].ident);
                                   
                                   lookup(yystack.l_mark[-3].ident);
                                   arg2.type = varType;
                                   arg2.val = cnrt;

                                   factorpush(arg2);

                                   (tmp->args).store.arg1 = arg1;
                                   (tmp->args).store.arg2 = arg2;

                                   addList(tmp);
                                   
                                   /*----------------------------*/
                            }
break;
case 34:
#line 418 "parser.y"
	{

                                   /* 制御文を記述する */ /* | Brcond*/

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
case 35:
#line 442 "parser.y"
	{

                                   /* 制御文を記述する */  /* | Label*/

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
case 37:
#line 468 "parser.y"
	{

                                   
                                   /* 制御文を記述する */ /* | BrUncond */

                                   LLVMcode* tmp1;
                                   int arg1;

                                   tmp1 = memoryGet(tmp1); 

                                   tmp1->command=BrUncond;

                                   addList(tmp1);


                                    /* 制御文を記述する */  /* | Label*/

                                   LLVMcode* tmp2;
                                   int l;

                                   tmp2 = memoryGet(tmp2); 

                                   tmp2->command=Label;

                                   l = cnrt;
                                   cnrt++;

                                   (tmp2->args).label.l = l;

                                   addList(tmp2);

                                   /* brスタックの管理 of label*/

                                   LLVMcode* backpatch1;

                                   backpatch1 = brpop();
                                   if(backpatch1->command == BrCond){
                                          (backpatch1->args).brcond.arg3 = l;
                                   }

                                   /* brスタックの管理 of BrUncond*/
                                   brpush(tmp1);
                                   
                                   
                                   /*----------------------------*/
                     }
break;
case 38:
#line 515 "parser.y"
	{

                                   /* 制御文を記述する */  /* | Label*/

                                   LLVMcode* tmp;
                                   int l;

                                   tmp = memoryGet(tmp); 

                                   tmp->command=Label;

                                   l = cnrt;
                                   cnrt++;

                                   (tmp->args).label.l = l;

                                   addList(tmp);

                                   /* brスタックの管理*/

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
case 39:
#line 547 "parser.y"
	{

                                   /* 制御文を記述する */  /* | Label*/

                                   LLVMcode* tmp;
                                   int l;

                                   tmp = memoryGet(tmp); 

                                   tmp->command=Label;

                                   l = cnrt;
                                   cnrt++;

                                   (tmp->args).label.l = l;

                                   addList(tmp);

                                   /* brスタックの管理*/

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
#line 583 "parser.y"
	{                    
                                   /* 制御文を記述する */ /* | BrUncond */

                                   LLVMcode* tmp1;
                                   int arg1;

                                   tmp1 = memoryGet(tmp1); 

                                   tmp1->command=BrUncond;
                                   (tmp1->args).bruncond.arg1 = cnrt; /* cnrt++; は不要*/

                                   addList(tmp1);

                                   
                                   
                                   
                                   /* 制御文を記述する */  /* | Label*/

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
case 41:
#line 617 "parser.y"
	{
                                   /* 制御文を記述する */ /* | Brcond*/

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

                                   /* 制御文を記述する */  /* | Label*/

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
case 42:
#line 658 "parser.y"
	{
                            /* 制御文を記述する */ /* | BrUncond */

                                   LLVMcode* tmp1;
                                   int arg1;

                                   tmp1 = memoryGet(tmp1); 

                                   tmp1->command=BrUncond;

                                   (tmp1->args).bruncond.arg1 = jumpid;

                                   addList(tmp1);


                            /* 制御文を記述する */  /* | Label*/

                                   LLVMcode* tmp2;
                                   int l;

                                   tmp2 = memoryGet(tmp2); 

                                   tmp2->command=Label;

                                   l = cnrt;
                                   cnrt++;

                                   (tmp2->args).label.l = l;

                                   addList(tmp2);

                            /* brスタックの管理 */

                                   LLVMcode* backpatch;

                                   backpatch = brpop();
                                   if(backpatch->command == BrCond){
                                          (backpatch->args).brcond.arg3 = l;
                                   }

                     }
break;
case 43:
#line 702 "parser.y"
	{/* lookup($2); */ }
break;
case 44:
#line 703 "parser.y"
	{

                                  /* IDENTの番地に、expressionの値をstoreするコード*/

                                   LLVMcode* tmp1;
                                   Factor arg1,arg2;

                                   tmp1 = memoryGet(tmp1); 

                                   tmp1->command=Store;

                                   lookup(yystack.l_mark[-3].ident);
                                   strcpy(arg2.vname,yystack.l_mark[-3].ident);
                                   arg2.type = varType;


                                   arg1 = factorpop(); /* IDENTの初期値*/
                                       
                                   (tmp1->args).store.arg1 = arg1;
                                   (tmp1->args).store.arg2 = arg2;

                                   addList(tmp1);

                   
                                   /* 制御文を記述する */ /* | BrUncond */

                                   LLVMcode* tmp2;

                                   tmp2 = memoryGet(tmp2); 

                                   tmp2->command=BrUncond;

                                   (tmp2->args).bruncond.arg1 = cnrt; /* cnrt++;は不要*/

                                   addList(tmp2);


                            /* 制御文を記述する */  /* | Label*/

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
#line 758 "parser.y"
	{

                                   /* 与えられた引数を新引数をレジスタへ格納後スタック へプッシュする | Load*/
                                   LLVMcode* tmp0;

                                   Factor arg1L,retvalL;
                                   tmp0 = memoryGet(tmp0); 

                                   tmp0->command=Load;


                                   /* 記号表から引数のデータを取得 */
                                   lookup(yystack.l_mark[-6].ident);
                                   strcpy(arg1L.vname,yystack.l_mark[-6].ident);
                                   arg1L.type = varType;
                                   

                                   retvalL.type = LOCAL_VAR; /* 新規に変数を格納するのは局所変数 */
                                   retvalL.val = cnrt;
                                   cnrt++;

                                   (tmp0->args).load.arg1 = arg1L;
                                   (tmp0->args).load.retval = retvalL;

                                   addList(tmp0);
                                   
                                   factorpush(retvalL);




                                   /*整数比較命令（SLE）でIDENTとTO後の値を比較する*/

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


                                   /* 制御文を記述する */ /* | Brcond*/

                                   LLVMcode* tmp2;
                                   Factor arg1_1;

                                   tmp2 = memoryGet(tmp2); 

                                   tmp2->command=BrCond;

                                   arg1_1 = factorpop();

                                   (tmp2->args).brcond.arg1 = arg1_1;
                                   (tmp2->args).brcond.arg2 = cnrt;

                                   addList(tmp2);
                                   brpush(tmp2);
                                   
                                   /*----------------------------*/

                                   /*----------------------------*/

                                   /* 制御文を記述する */  /* | Label*/

                                   LLVMcode* tmp3;
                                   int l;

                                   tmp3 = memoryGet(tmp3); 

                                   tmp3->command=Label;

                                   l = cnrt;
                                   cnrt++;

                                   (tmp3->args).label.l = l;

                                   addList(tmp3);
                                   /*----------------------------*/


                            }
break;
case 46:
#line 862 "parser.y"
	{

                                   /* 加算命令でIDENTを1インクリメントする */
                                   LLVMcode *tmp;                /*生成した命令へのポインタ*/
                                   Factor arg1, arg2,retval;      /*加算の引数、結果*/
                                   tmp = memoryGet(tmp);          /*mallocによるメモリ確保*/

                                   tmp->command = Add;
                                   
                                   arg2.type = CONSTANT;
                                   arg2.val = 1;

                                   lookup(yystack.l_mark[-9].ident);
                                   strcpy(arg1.vname,yystack.l_mark[-9].ident);
                                   arg1.type = varType;
                                   
                                   retval.type = LOCAL_VAR;  /*結果を格納するレジスタは局所変数*/
                                   retval.val = cnrt;        /* 新規のレジスタ番号を取得*/
                                   cnrt++;

                                   (tmp->args).add.arg1 = arg1;   /* 命令の第1引数を指定 */
                                   (tmp->args).add.arg2 = arg2;   /* 命令の第2引数を指定 */
                                   (tmp->args).add.retval = retval; /* 結果のレジスタを指定*/

                                   addList(tmp);                /* 新規命令として、命令列へ追加する*/
                                   
                                   factorpush( retval );       /* 加算の結果をスタックへプッシュ*/

                                   /*-----------------------------------------*/


                                  /* インクリメントしたIDENTをstoreする */

                                   LLVMcode* tmp0;
                                   Factor arg1_1,arg2_1;

                                   tmp0 = memoryGet(tmp0); 

                                   tmp0->command=Store;

                                   lookup(yystack.l_mark[-9].ident);
                                   strcpy(arg2_1.vname,yystack.l_mark[-9].ident);
                                   arg2_1.type = varType;


                                   arg1_1 = factorpop(); 
                                       
                                   (tmp0->args).store.arg1 = arg1_1;
                                   (tmp0->args).store.arg2 = arg2_1;

                                   addList(tmp0);
                                   


                                    /* 制御文を記述する */ /* | BrUncond */

                                   LLVMcode* tmp1;

                                   tmp1 = memoryGet(tmp1); 

                                   tmp1->command=BrUncond;

                                   (tmp1->args).bruncond.arg1 = jumpid;

                                   addList(tmp1);


                                    /* 制御文を記述する */  /* | Label*/

                                   LLVMcode* tmp2;
                                   int l;

                                   tmp2 = memoryGet(tmp2); 

                                   tmp2->command=Label;

                                   l = cnrt;
                                   cnrt++;

                                   (tmp2->args).label.l = l;

                                   addList(tmp2);

                                   /* brスタックの管理 */

                                          LLVMcode* backpatch;

                                          backpatch = brpop();
                                          if(backpatch->command == BrCond){
                                                 (backpatch->args).brcond.arg3 = l;
                                          }


                            }
break;
case 48:
#line 963 "parser.y"
	{ /* lookup($1); */ }
break;
case 50:
#line 971 "parser.y"
	{ /* lookup($3);*/ }
break;
case 54:
#line 984 "parser.y"
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
case 55:
#line 1017 "parser.y"
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
case 56:
#line 1049 "parser.y"
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
case 57:
#line 1081 "parser.y"
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
#line 1113 "parser.y"
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
case 59:
#line 1145 "parser.y"
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
case 63:
#line 1184 "parser.y"
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
case 64:
#line 1208 "parser.y"
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
case 66:
#line 1238 "parser.y"
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
case 67:
#line 1262 "parser.y"
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
case 69:
#line 1289 "parser.y"
	{
				 /*定数引数をスタックへプッシュする*/

				 Factor number;
				 number.val = (yystack.l_mark[0].num);
				 number.type = CONSTANT;
				 factorpush(number);
                             /*----------------------------*/
         }
break;
case 71:
#line 1302 "parser.y"
	{ /* lookup($1);*/ }
break;
case 72:
#line 1304 "parser.y"
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
case 73:
#line 1344 "parser.y"
	{ insert(yystack.l_mark[0].ident,flag);}
break;
case 74:
#line 1345 "parser.y"
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
case 75:
#line 1390 "parser.y"
	{insert(yystack.l_mark[0].ident,flag);}
break;
case 76:
#line 1391 "parser.y"
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
#line 1973 "y.tab.c"
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
