%{
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

%}

%union {
    int num;
    char ident[MAXLENGTH+1];
}

%token SBEGIN DO ELSE SEND
%token FOR FORWARD FUNCTION IF PROCEDURE
%token PROGRAM READ THEN TO VAR
%token WHILE WRITE

%left PLUS MINUS                       
%left MULT DIV                         

%token EQ NEQ LE LT GE GT
%token LPAREN RPAREN LBRACKET RBRACKET
%token COMMA SEMICOLON COLON INTERVAL
%token PERIOD ASSIGN
%token <num> NUMBER                 
%token <ident> IDENT               

%%

program
        : PROGRAM IDENT 
         {
                 init_fstack();
                 insert_data($2,PROC_NAME,0);
                 
         }
         SEMICOLON outblock PERIOD
        {
                displayLlvmfundecl(declhd);
        }
        ;

outblock
        : var_decl_part subprog_decl_part
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
         statement
        ;
var_decl_part
        : var_decl_list SEMICOLON
        | /* empty */
        ;
var_decl_list
        : var_decl_list SEMICOLON var_decl
        | var_decl
        ;
var_decl
        : VAR id_list
        ;
subprog_decl_part
        : subprog_decl_list SEMICOLON 
        | /* empty */
        ;
subprog_decl_list
        : subprog_decl_list SEMICOLON subprog_decl
        | subprog_decl
        ;
subprog_decl
        : proc_decl
        ;
proc_decl
        : PROCEDURE
          {flag = LOCAL_VAR;} 
          proc_name SEMICOLON inblock 
          {
                delete_data(); 
                flag = GLOBAL_VAR;
                cntr=1;
        }
        ;
proc_name
        : IDENT 
        {
                Fundecl *func;
                func =(Fundecl *)malloc(sizeof(Fundecl));
                strcpy(func->fname,$1);
                func->ret = 0;
                codehd = codetl = func->codes;
                if(declhd == NULL){
                        declhd = decltl = func;
                }else{
                        decltl->next = func;
                        decltl = func;
                }
                insert_data($1,PROC_NAME,0);
                
                

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
        ;
inblock
        : var_decl_part statement 
        ;
statement_list
        : statement_list SEMICOLON statement
        | statement
        ;
statement
        : assignment_statement
        | if_statement
        | while_statement
        | for_statement
        | proc_call_statement
        | null_statement
        | block_statement
        | read_statement
        | write_statement
        ;
assignment_statement
        :IDENT ASSIGN expression
         {
                
                 
                LLVMcode *tmp;             /* 生成した命令へのポインタ */
                Factor arg1, arg2; /* ストアの引数・結果 */
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL;          /* 次の命令へのポインタを初期化 */
                tmp->command = Store;        /* 命令の種類をストアに設定 */
                arg1 = factorpop();        /* スタックから第2引数をポップ */
                arg2 = lookup_data($1);        /* スタックから第1引数をポップ */
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
        ;

if_statement
        : IF condition
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
         THEN
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
          statement
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
         else_statement
        ;
        
else_statement
        :
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
         ELSE statement
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
        | /* empty */
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
        
        ;
while_statement
        : WHILE
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
         condition 
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
        DO
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
        statement
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
        ;
for_statement
        :FOR IDENT ASSIGN expression
        {
                
                LLVMcode *tmp;             /* 生成した命令へのポインタ */
                Factor arg1, arg2; /* ストアの引数・結果 */
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL;          /* 次の命令へのポインタを初期化 */
                tmp->command = Store;        /* 命令の種類をストアに設定 */
                arg1 = factorpop();        /* スタックから第2引数をポップ */
                arg2 = lookup_data($2);        /* スタックから第1引数をポップ */
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
         TO
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
        expression
        {
                

                LLVMcode *tmp;             /* 生成した命令へのポインタ */
                Factor arg1, retval; /* ロードの引数・結果 */
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL;          /* 次の命令へのポインタを初期化 */
                tmp->command = Load;        /* 命令の種類をロードに設定 */
                arg1 = lookup_data($2);        /* スタックから第1引数をポップ */
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
        DO
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
          statement
        {
                LLVMcode *tmp;             /* 生成した命令へのポインタ */
                Factor arg1, retval; /* ロードの引数・結果 */
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL;          /* 次の命令へのポインタを初期化 */
                tmp->command = Load;        /* 命令の種類をロードに設定 */
                arg1 = lookup_data($2);        /* スタックから第1引数をポップ */
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
        {
                LLVMcode *tmp;             /* 生成した命令へのポインタ */
                Factor arg1, arg2; /* ストアの引数・結果 */
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL;          /* 次の命令へのポインタを初期化 */
                tmp->command = Store;        /* 命令の種類をストアに設定 */
                arg1 = factorpop();        /* スタックから第2引数をポップ */
                arg2 = lookup_data($2);        /* スタックから第1引数をポップ */
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
        ;
proc_call_statement
        : proc_call_name
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
        ;
proc_call_name
        : IDENT 
        {
                LLVMcode *tmp;             /* 生成した命令へのポインタ */
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL;          /* 次の命令へのポインタを初期化 */
                tmp->command = Call;        /* 命令の種類を加算に設定 */
                strcpy((tmp->args).call.name,$1)   ; /* 結果のレジスタを指定 */  
                if( codetl == NULL ){ /* 解析中の関数の最初の命令の場合 */
                        decltl->codes = tmp;   /* 関数定義の命令列の先頭の命令に設定 */
                        codehd = codetl = tmp; /* 生成中の命令列の末尾の命令として記憶 */
                } else { /* 解析中の関数の命令列に1つ以上命令が存在する場合 */
                        codetl->next = tmp; /* 命令列の末尾に追加 */
                        codetl = tmp;       /* 命令列の末尾の命令として記憶 */
                }
        }
        ;
block_statement
        : SBEGIN statement_list SEND 

        ;
read_statement
        : READ LPAREN IDENT RPAREN
        {
                LLVMcode *tmp;             /* 生成した命令へのポインタ */
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL;          /* 次の命令へのポインタを初期化 */
                tmp->command = Read;        /* 命令の種類を加算に設定 */
                (tmp->args).read.arg1 = lookup_data($3); /* 結果のレジスタを指定 */  
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
        ;
write_statement
        : WRITE LPAREN expression RPAREN
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
        ;
null_statement
        : /* empty */
        ;
condition
        : expression EQ expression
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
        | expression NEQ expression
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
        | expression LT expression
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
        | expression LE expression
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
        | expression GT expression
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
        | expression GE expression
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
        ;
expression
        : term
        | PLUS term
        | MINUS term
        | expression PLUS term
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
        | expression MINUS term
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
        ;
term
        : factor
        | term MULT factor
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
        | term DIV factor
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
        ;
factor
        : var_name
        | NUMBER 
        { 
                Factor tmp;
                tmp.type = CONSTANT;
                tmp.vname[0] = EOF;
                tmp.val = $1;
                factorpush(tmp);
        }
        | LPAREN expression RPAREN
        ;
var_name
        : IDENT 
        {
                LLVMcode *tmp;             /* 生成した命令へのポインタ */
                Factor arg1, retval; /* ロードの引数・結果 */
                tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
                tmp->next = NULL;          /* 次の命令へのポインタを初期化 */
                tmp->command = Load;        /* 命令の種類をロードに設定 */
                arg1 = lookup_data($1);        /* スタックから第1引数をポップ */
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
        ;

/* arg_list
 *        : expression
 *        | arg_list COMMA expression
 *        ;
 */
id_list 
        : IDENT 
        {
                if(flag==GLOBAL_VAR){
                fprintf(yyout,"@%s = common global i32 0, align 4\n",$1);
                }else if(flag==LOCAL_VAR){
                        LLVMcode *tmp;             /* 生成した命令へのポインタ */
                        Factor retval; /* allocaの結果 */
                        tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /* メモリ確保 */
                        tmp->next = NULL;          /* 次の命令へのポインタを初期化 */
                        tmp->command = Alloca;        /* 命令の種類をAllocaに設定 */
                        retval.type = LOCAL_VAR;   /* 結果を格納するレジスタは局所 */
                        strcpy(retval.vname,$1);
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
                insert_data($1,flag,cntr-1);        
        }
        | id_list COMMA IDENT 
        {
                if(flag==GLOBAL_VAR){
                fprintf(yyout,"@%s = common global i32 0, align 4\n",$3);
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
                
                insert_data($3,flag,cntr-1);
        }
        ;
%% 
yyerror(char *s)
{
  fprintf(stderr, "%s line%d:%s\n", s,yylineno,yytext);
}
