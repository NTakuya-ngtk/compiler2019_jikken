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
#include "table.h"
#include "table.c"
#include "createllvm.h"
#include "createllvm.c"

  extern int yylineno;
  extern char *yytext;

	Scope flag = GLOBAL_VAR;
	/*init_fstack();  // スタックの初期化を行う*/
       int cnrt = 0;     /* レジスタ番号*/
extern int readflag;
extern int writeflag;
       int procArgCount = 0;
       int procArgFlag = 0;
       int callCount;
	
#line 29 "parser.y"
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
#line 57 "y.tab.c"

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
    6,    6,   11,   11,   12,   13,   17,   13,   18,   14,
   19,   15,   20,   20,    7,    7,    7,    7,    7,    7,
    7,    7,    7,   21,   32,   33,   22,   35,   34,   34,
   36,   37,   23,   38,   39,   24,   25,   42,   25,   40,
   27,   28,   29,   26,   31,   31,   31,   31,   31,   31,
   30,   30,   30,   30,   30,   43,   43,   43,   44,   44,
   44,   45,   41,   41,   46,   10,   47,   10,   16,   16,
};
static const short yylen[] = {                            2,
    0,    0,    0,    8,    3,    0,    2,    3,    1,    2,
    0,    2,    3,    1,    1,    4,    0,    8,    0,    2,
    0,    3,    3,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    3,    0,    0,    7,    0,    3,    0,
    0,    0,    6,    0,    0,   10,    1,    0,    5,    1,
    3,    4,    4,    0,    3,    3,    3,    3,    3,    3,
    1,    2,    2,    3,    3,    1,    3,    3,    1,    1,
    3,    1,    1,    3,    0,    2,    0,    4,    1,    3,
};
static const short yydefred[] = {                         1,
    0,    0,    0,    2,    0,    0,    0,    3,    0,    0,
    9,   75,    0,    0,    0,    0,    0,   14,   15,    0,
   76,    0,    4,   19,    0,    0,    0,    0,    0,   41,
    0,    0,    5,   25,   26,   27,   28,   29,   30,   31,
   32,   33,    0,    0,    8,   77,   20,    0,   21,   24,
    0,    0,    0,    0,    0,   70,   72,    0,   35,    0,
   66,   69,    0,    0,    0,    0,   48,   13,   78,   79,
    0,   16,    0,   51,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   42,    0,    0,    0,    0,    0,    0,   23,    0,
   71,    0,    0,    0,    0,    0,    0,    0,    0,   36,
   67,   68,   52,    0,   53,    0,    0,   17,   80,   22,
    0,    0,    0,   49,    0,   21,    0,    0,   43,    0,
   18,    0,   38,   37,    0,    0,    0,   39,   46,
};
static const short yydgoto[] = {                          1,
    2,    5,    8,   14,    9,   16,   33,   10,   11,   13,
   17,   18,   19,   25,   72,   71,  126,   47,   73,   51,
   34,   35,   36,   37,   38,   39,   40,   41,   42,   58,
   59,   88,  122,  134,  136,   64,  114,  121,  135,   43,
  117,   95,   60,   61,   62,   21,   69,
};
static const short yysindex[] = {                         0,
    0, -261, -276,    0, -265, -228, -247,    0, -208, -214,
    0,    0, -194, -191, -193, -144, -170,    0,    0, -228,
    0, -172,    0,    0, -281, -144, -157, -134, -159,    0,
 -139, -147,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -137, -208,    0,    0,    0, -123,    0,    0,
 -252, -135, -268, -268, -134,    0,    0,   26,    0, -272,
    0,    0, -121, -134, -134, -134,    0,    0,    0,    0,
 -260,    0, -228,    0, -144, -134, -272, -272, -148, -268,
 -268, -134, -134, -134, -134, -134, -134,  -90, -268, -268,
 -101,    0, -110, -205, -134, -104,  -97, -144,    0, -205,
    0, -272, -272, -205, -205, -205, -205, -205, -205,    0,
    0,    0,    0,  -65,    0, -205, -168,    0,    0,    0,
  -71, -144, -144,    0, -134,    0, -134,  -56,    0, -205,
    0, -205,    0,    0,  -53, -144, -144,    0,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0, -213,    0,    0, -211,    0,
    0,    0,  -84,    0,    0,  -85,    0,    0,    0, -251,
    0,    0,    0,    0,    0, -243,    0,    0,    0,    0,
    0, -221,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -225, -182,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -126,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -173,    0, -243,    0,  -92,  -58,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -183,    0,    0,    0,  -81,    0,  -61,
    0,  -24,   10, -249, -203, -154, -127,  -89,  -88,    0,
    0,    0,    0,    0,    0, -112,    0,    0,    0,    0,
    0, -153, -153,    0,    0,    0,    0, -196,    0,  -93,
    0,  -49,    0,    0,    0, -153, -153,    0,    0,
};
static const short yygindex[] = {                         0,
    0,    0,    0,    0,  139,    0,  -26,    0,  193,    0,
    0,  170,    0,    0,   91,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  -54,
  154,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   49,   -3,    0,    0,    0,
};
#define YYTABLESIZE 308
static const short yytable[] = {                         50,
   79,   48,   89,   90,    3,    7,   49,   74,   55,    7,
   93,   94,    7,    7,   55,    7,   54,    4,   55,    7,
    7,  100,    6,   96,   56,   57,   97,  104,  105,  106,
  107,  108,  109,   47,   47,   75,    7,   50,   50,    7,
  116,    7,    7,    6,   54,   11,   12,    6,   99,   11,
    6,    6,   11,    6,   56,   11,   15,    6,    6,   11,
   11,   50,   47,   40,   56,   47,   50,   80,   81,   50,
  130,  120,  132,   20,   12,   34,   34,    6,   12,   11,
    6,   12,   11,    6,   12,  111,  112,    6,   12,   12,
    6,   40,   22,    6,   40,  128,  129,    6,    6,   23,
   24,   77,   78,   58,   34,   54,   54,   34,   12,  138,
  139,   12,   26,   58,    6,  124,   27,   44,  125,   28,
    6,   46,   29,   63,   80,   81,   30,   31,  102,  103,
   57,   61,   61,   61,   54,  101,   52,   54,   53,   54,
   57,   61,   61,   65,   66,   67,   61,   61,   55,   32,
   61,   61,   61,   61,   61,   61,   76,   61,   56,   57,
   61,   61,   80,   81,   61,   62,   62,   62,   60,   59,
   70,   73,   91,  115,   73,   62,   62,  110,   60,   59,
   62,   62,  113,  118,   62,   62,   62,   62,   62,   62,
   74,   62,  123,   74,   62,   62,  119,  127,   62,   63,
   63,   63,  133,   10,  137,   54,   54,   44,   45,   63,
   63,   98,   45,   68,   63,   63,  131,   92,   63,   63,
   63,   63,   63,   63,    0,   63,    0,    0,   63,   63,
    0,    0,   63,   64,   64,   64,    0,    0,    0,    0,
    0,    0,    0,   64,   64,    0,    0,    0,   64,   64,
    0,    0,   64,   64,   64,   64,   64,   64,    0,   64,
    0,    0,   64,   64,    0,    0,   64,   65,   65,   65,
    0,    0,    0,    0,    0,    0,    0,   65,   65,    0,
    0,    0,   65,   65,    0,    0,   65,   65,   65,   65,
   65,   65,    0,   65,    0,    0,   65,   65,   80,   81,
   65,    0,   82,   83,   84,   85,   86,   87,
};
static const short yycheck[] = {                         26,
   55,  283,  275,  276,  266,  257,  288,  260,  258,  261,
   65,   66,  264,  265,  283,  267,  260,  294,  268,  271,
  272,   76,  288,  284,  293,  294,  287,   82,   83,   84,
   85,   86,   87,  259,  260,  288,  288,  259,  260,  291,
   95,  270,  294,  257,  288,  257,  294,  261,   75,  261,
  264,  265,  264,  267,  258,  267,  265,  271,  272,  271,
  272,  283,  288,  260,  268,  291,  288,  273,  274,  291,
  125,   98,  127,  288,  257,  259,  260,  291,  261,  291,
  294,  264,  294,  257,  267,   89,   90,  261,  271,  272,
  264,  288,  287,  267,  291,  122,  123,  271,  272,  291,
  294,   53,   54,  258,  288,  259,  260,  291,  291,  136,
  137,  294,  257,  268,  288,  284,  261,  288,  287,  264,
  294,  294,  267,  283,  273,  274,  271,  272,   80,   81,
  258,  258,  259,  260,  288,  284,  294,  291,  273,  274,
  268,  268,  269,  283,  292,  283,  273,  274,  283,  294,
  277,  278,  279,  280,  281,  282,  292,  284,  293,  294,
  287,  288,  273,  274,  291,  258,  259,  260,  258,  258,
  294,  284,  294,  284,  287,  268,  269,  268,  268,  268,
  273,  274,  284,  288,  277,  278,  279,  280,  281,  282,
  284,  284,  258,  287,  287,  288,  294,  269,  291,  258,
  259,  260,  259,  288,  258,  291,  288,  269,  258,  268,
  269,   73,   20,   44,  273,  274,  126,   64,  277,  278,
  279,  280,  281,  282,   -1,  284,   -1,   -1,  287,  288,
   -1,   -1,  291,  258,  259,  260,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  268,  269,   -1,   -1,   -1,  273,  274,
   -1,   -1,  277,  278,  279,  280,  281,  282,   -1,  284,
   -1,   -1,  287,  288,   -1,   -1,  291,  258,  259,  260,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  268,  269,   -1,
   -1,   -1,  273,  274,   -1,   -1,  277,  278,  279,  280,
  281,  282,   -1,  284,   -1,   -1,  287,  288,  273,  274,
  291,   -1,  277,  278,  279,  280,  281,  282,
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
"proc_decl : PROCEDURE proc_name LPAREN proc_id_list RPAREN SEMICOLON $$4 inblock",
"$$5 :",
"proc_name : IDENT $$5",
"$$6 :",
"inblock : $$6 var_decl_part statement",
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
"for_statement : FOR IDENT ASSIGN expression $$12 TO expression $$13 DO statement",
"proc_call_statement : proc_call_name",
"$$14 :",
"proc_call_statement : proc_call_name LPAREN $$14 arg_list RPAREN",
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
"arg_list : expression",
"arg_list : arg_list COMMA expression",
"$$15 :",
"id_list : IDENT $$15",
"$$16 :",
"id_list : id_list COMMA IDENT $$16",
"proc_id_list : IDENT",
"proc_id_list : proc_id_list COMMA IDENT",

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
#line 1612 "parser.y"
yyerror(char *s)
{
  fprintf(stderr, "%s line:%d token:%s\n", s ,yylineno,yytext);
}
#line 422 "y.tab.c"

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
#line 52 "parser.y"
	{
                     /* 出力ファイルを書き込む部分 */
                     if((fp = fopen("result.ll","w")) == NULL){
                            fprintf(stderr, "result.llのオープンに失敗しました\n");
                            exit(1);
                     }
              }
break;
case 2:
#line 59 "parser.y"
	{      
                            /* 大域変数を格納するfundeclを作るコード*/
                            Fundecl *new;
				new = (Fundecl *)malloc(sizeof(Fundecl)); /*メモリを動的に確保*/
				new->next = NULL;

                             /* 線形リストのポインタを更新 */
                            declhd = new;
                            decltl = new;
                            
                            insert_data(yystack.l_mark[0].ident,PROC_NAME,0);
                     }
break;
case 3:
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
case 4:
#line 91 "parser.y"
	{      
	       	displayLLVMfundecl(declhd);
                     fclose(fp);
              }
break;
case 10:
#line 112 "parser.y"
	{
       }
break;
case 11:
#line 118 "parser.y"
	{ /* ここがメイン関数の入るところ*/
         
                                   Fundecl *mainfunc;
					mainfunc = (Fundecl *)malloc(sizeof(Fundecl)); /*メモリを動的に確保*/
					mainfunc->next = NULL;
                                   

                                   /* main関数のため，"main"を格納*/
					strcpy(mainfunc->fname,"main");
                                   mainfunc->ret = 1;

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
#line 187 "parser.y"
	{ /* ここがメイン関数の入るところ*/
         
					/* printf("debug");*/
                                   Fundecl *mainfunc;
					mainfunc = (Fundecl *)malloc(sizeof(Fundecl)); /*メモリを動的に確保*/
					mainfunc->next = NULL;
                                   
                                   mainfunc->ret = 1; /* 返り値の数*/

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
#line 269 "parser.y"
	{delete_data();}
break;
case 17:
#line 270 "parser.y"
	{
              
              cnrt++; /* 局所変数のスキップ*/

              int roopCount = 0;

              for(roopCount = 0;roopCount < procArgCount;roopCount++){

                     LLVMcode* tmp;
                     tmp = memoryGet(tmp); 
                     Factor retval;

                     tmp = memoryGet(tmp); 

                     tmp->command=Alloca;

                     retval.type = LOCAL_VAR;
                     retval.val = cnrt;
                     cnrt++;

                     (tmp->args).alloca.retval = retval;
                     
                     factorpush(retval);

                     addList(tmp);   

                     
              }

              for(roopCount = 0;roopCount < procArgCount;roopCount++){
                     /* allocaした番地を番地をstoreするコード*/

                     LLVMcode* tmp1;
                     Factor arg1,arg2;

                     tmp1 = memoryGet(tmp1); 

                     tmp1->command=Store;

                     arg2 = factorpop();  /* 局所変数を取り出す*/
                     
                     /* strcpy(arg1.vname,$1);*/
                     arg1=lookup_data((decltl->args)[procArgCount-roopCount-1].vname);
                     /* printf("test:%s\n",(decltl->args)[roopCount].vname);*/

                     /* factorpush(arg2);*/

                     (tmp1->args).store.arg1 = arg1;
                     (tmp1->args).store.arg2 = arg2;

                     addList(tmp1);     
              }
             
             

       }
break;
case 18:
#line 326 "parser.y"
	{delete_data();}
break;
case 19:
#line 330 "parser.y"
	{flag = PROC_NAME; insert_data(yystack.l_mark[0].ident,flag,0);}
break;
case 20:
#line 331 "parser.y"
	{

		                     /*-----------------------------------------------------*/

                                   /* 以下プログラム名から関数のLLVMコードを生成するCプログラム*/

					
                                   Fundecl *new;
                                   
					new = (Fundecl *)malloc(sizeof(Fundecl)); /*メモリを動的に確保*/
					new->next = NULL;
                                   /* 関数名等を保存*/
                                   strcpy(new->fname,yystack.l_mark[-1].ident);
                                   new->ret = 0;
					                            
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

                                   cnrt = 0; /* cnrtの初期化*/

                                   /* -------------------------------------- */
                                   /* procedureをAllocaするコード*/
                                   /* LLVMcode* tmp;*/
                                   /* Factor retval;*/

                                   /* tmp = memoryGet(tmp); */

                                   /* tmp->command=Alloca;*/

                                   /* cnrt = 1; // cnrtの初期化を行う*/

                                   /* etval.type = LOCAL_VAR;*/
                                   /* retval.val = cnrt;*/
                                   /* cnrt++;*/

                                   /* (tmp->args).alloca.retval = retval;*/
                                   
                                   /* factorpush(retval);*/

                                   /* addList(tmp);*/

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
case 21:
#line 413 "parser.y"
	{ flag = LOCAL_VAR; }
break;
case 22:
#line 415 "parser.y"
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
#line 450 "parser.y"
	{
                                  /*変数引数をスタックからpopしてレジスタへ格納する ｜Store*/

                                   LLVMcode* tmp;
                                   Factor arg1,arg2;

                                   tmp = memoryGet(tmp); 

                                   tmp->command=Store;

                                   arg1 = factorpop(); 
                                    
                                   strcpy(arg2.vname,yystack.l_mark[-2].ident);
                                   
                                   arg2 = lookup_data(yystack.l_mark[-2].ident);

                                   factorpush(arg2);

                                   (tmp->args).store.arg1 = arg1;
                                   (tmp->args).store.arg2 = arg2;

                                   addList(tmp);
                                   
                                   /*----------------------------*/
                            }
break;
case 35:
#line 480 "parser.y"
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
case 36:
#line 504 "parser.y"
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
case 38:
#line 530 "parser.y"
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
case 39:
#line 577 "parser.y"
	{             /* 制御文を記述する */ /* | BrUncond */

                                   LLVMcode* tmp1;
                                   int arg1;

                                   tmp1 = memoryGet(tmp1); 
                                   arg1 = cnrt;
                                   tmp1->command=BrUncond;

                                   (tmp1->args).bruncond.arg1 = arg1;

                                   addList(tmp1);

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
#line 620 "parser.y"
	{            
                                    /* 制御文を記述する */ /* | BrUncond */

                                   LLVMcode* tmp1;
                                   int arg1;

                                   tmp1 = memoryGet(tmp1); 
                                   arg1 = cnrt;
                                   tmp1->command=BrUncond;

                                   (tmp1->args).bruncond.arg1 = arg1;

                                   addList(tmp1);

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
case 41:
#line 668 "parser.y"
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
case 42:
#line 702 "parser.y"
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
case 43:
#line 743 "parser.y"
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
case 44:
#line 788 "parser.y"
	{

                                  /* IDENTの番地に、expressionの値をstoreするコード*/

                                   LLVMcode* tmp1;
                                   Factor arg1,arg2;

                                   tmp1 = memoryGet(tmp1); 

                                   tmp1->command=Store;

                                   arg2 = lookup_data(yystack.l_mark[-2].ident);
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
#line 839 "parser.y"
	{

                                   /* 与えられた引数を新引数をレジスタへ格納後スタック へプッシュする | Load*/
                                   LLVMcode* tmp0;

                                   Factor arg1L,retvalL;
                                   tmp0 = memoryGet(tmp0); 

                                   tmp0->command=Load;


                                   /* 記号表から引数のデータを取得 */
                                   arg1L = lookup_data(yystack.l_mark[-5].ident);
                                   
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
                                   
                                   /* ----------------------------*/

                                   /* ----------------------------*/

                                   /* 制御文を記述する */  /* | Label*/

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
#line 940 "parser.y"
	{

                                   /* 加算命令でIDENTを1インクリメントする */
                                   LLVMcode *tmp;                /*生成した命令へのポインタ*/
                                   Factor arg1, arg2,retval;      /*加算の引数、結果*/
                                   tmp = memoryGet(tmp);          /*mallocによるメモリ確保*/

                                   tmp->command = Add;
                                   
                                   arg2.type = CONSTANT;
                                   arg2.val = 1;

                                   arg1 = lookup_data(yystack.l_mark[-8].ident);
                                   
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

                                   arg2_1 = lookup_data(yystack.l_mark[-8].ident);
                                   

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
#line 1034 "parser.y"
	{procArgFlag =1; callCount = 0;}
break;
case 49:
#line 1035 "parser.y"
	{procArgFlag = 0; LLVMcode*tmp; tmp = procCallpop(); addList(tmp);}
break;
case 50:
#line 1040 "parser.y"
	{             /* ----------- */
                     /* Call statement */
                     LLVMcode *tmp;
                     char name[10];

                     tmp = memoryGet(tmp);
                     tmp->command = Call;

                     strcpy(name,yystack.l_mark[0].ident);

                     strcpy(tmp->args.call.name,name);
                     procCallpush(tmp);
       }
break;
case 52:
#line 1061 "parser.y"
	{
                     LLVMcode *tmp;
                     Factor arg1,retval;

                     tmp = memoryGet(tmp);
                     tmp->command = Read;

                     arg1 = lookup_data(yystack.l_mark[-1].ident);
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
#line 1085 "parser.y"
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
#line 1146 "parser.y"
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
#line 1178 "parser.y"
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
#line 1210 "parser.y"
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
#line 1242 "parser.y"
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
#line 1274 "parser.y"
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
#line 1313 "parser.y"
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
case 65:
#line 1337 "parser.y"
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
case 67:
#line 1367 "parser.y"
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
case 68:
#line 1391 "parser.y"
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
case 70:
#line 1418 "parser.y"
	{
				 /*定数引数をスタックへプッシュする*/

				 Factor number;
				 number.val = (yystack.l_mark[0].num);
				 number.type = CONSTANT;
				 factorpush(number);

                             if(procArgFlag == 1 ){       /*手続き呼び出しの引数の場合*/
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
#line 1441 "parser.y"
	{ 
                            
                            
                           

                                          /*与えられた引数を新引数をレジスタへ格納後スタック へプッシュする | Load*/
                                          LLVMcode* tmp;

                                          Factor arg1,retval;
                                          tmp = memoryGet(tmp); 

                                          tmp->command=Load;


                                          /* 記号表から引数のデータを取得 */
                                          arg1 = lookup_data(yystack.l_mark[0].ident);
                                          

                                          retval.type = LOCAL_VAR; /* 新規に変数を格納するのは局所変数 */
                                          retval.val = cnrt;
                                          cnrt++;

                                          (tmp->args).load.arg1 = arg1;
                                          (tmp->args).load.retval = retval;

                                          addList(tmp);
                                          
                                          factorpush(retval);

                                                                          
                                          /*----------------------------*/
                                          /* printf("\nprocArgFlag:%d\n",procArgFlag);*/

                                          if(procArgFlag == 1 ){       /*手続き呼び出しの引数の場合*/
                                                 LLVMcode* call;


                                                 call = procCallpop();
                                                 ((call->args).call.arg_list)[callCount] = retval.val;
                                                 callCount++;
                                                 /* printf("\narglist[%d]:%d\n",callCount-1,((call->args).call.arg_list)[callCount-1]);*/
                                                 procCallpush(call);


                                          }
                            }
break;
case 75:
#line 1497 "parser.y"
	{ insert_data(yystack.l_mark[0].ident,flag,cnrt);}
break;
case 76:
#line 1498 "parser.y"
	{ 
                                   LLVMcode* tmp;
                                   tmp = memoryGet(tmp); 
                                   Factor retval;

                                   switch(flag){
                                          case GLOBAL_VAR:
                                                 /* 大域変数を出力する*/
                                                 displayGlobalVar(yystack.l_mark[-1].ident);
                                                 break;
                                          
                                          case LOCAL_VAR:
                                         
                                                 /* 局所変数の領域をAllocaするコード*/
                                                 tmp = memoryGet(tmp); 

                                                 tmp->command=Alloca;

                                                 /* cnrt = 1; // cnrtの初期化を行う*/

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
#line 1539 "parser.y"
	{insert_data(yystack.l_mark[0].ident,flag,cnrt);}
break;
case 78:
#line 1540 "parser.y"
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
                                                 /* 局所変数の領域をAllocaするコード*/

                                                 tmp = memoryGet(tmp); 

                                                 tmp->command=Alloca;

                                                 /* cnrt = 1; // cnrtの初期化を行う*/

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
#line 1580 "parser.y"
	{      
              insert_data(yystack.l_mark[0].ident,LOCAL_VAR,cnrt);
              cnrt++;
              
              Factor arg;

              arg = lookup_data(yystack.l_mark[0].ident);
              /* factorpush(arg);*/
              (decltl->args)[procArgCount] = arg;

              procArgCount++;

              
       }
break;
case 80:
#line 1595 "parser.y"
	{      
              insert_data(yystack.l_mark[0].ident,LOCAL_VAR,cnrt);
              cnrt++;

              Factor arg;

              arg = lookup_data(yystack.l_mark[0].ident);
              /* factorpush(arg);*/
              (decltl->args)[procArgCount] = arg;
              
              procArgCount++;

              
       }
break;
#line 2165 "y.tab.c"
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
