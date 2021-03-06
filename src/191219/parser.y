%{
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
	//init_fstack();  // スタックの初期化を行う
       int cnrt = 0;     // レジスタ番号
	
%}

%union {
    int num;
    char ident[MAXLENGTH+1];
}

%token SBEGIN DO ELSE SEND
%token FOR FORWARD FUNCTION IF PROCEDURE
%token PROGRAM READ THEN TO VAR
%token WHILE WRITE

%left PLUS MINUS                       /*← 注意*/
%left MULT DIV                         /*← 注意*/

%token EQ NEQ LE LT GE GT
%token LPAREN RPAREN LBRACKET RBRACKET
%token COMMA SEMICOLON COLON INTERVAL
%token PERIOD ASSIGN
%token <num> NUMBER                    /*← yylval の型を指定*/
%token <ident> IDENT                   /*← yylval の型を指定*/

%%

program
        : PROGRAM IDENT {

               		       /*-----------------------------------------------------*/


                                   /* 大域変数を格納するfundeclを作るコード*/
					
                                   Fundecl *new;
					new = (Fundecl *)malloc(sizeof(Fundecl)); //メモリを動的に確保
					new->next = NULL;
                                   

                                   // 初回は関数名がないため，NULL入力する．strcpyかもしれない．
					strcpy(new->fname,$2);
                                   strcpy(programName,$2);

                                    /* 線形リストのポインタを更新 */

                                   if(decltl == NULL){  /* 関数定義の線形リストの最初であるとき*/
                                          declhd = decltl = new;
                                    } else {             /* 関数定義の線形リストに1つ以上存在する時*/
                                          decltl->next = new;  // 関数定義列の末尾に*newを追加
                                          decltl = new;        // 関数定義列の末尾として*newを保存する

                                   };
					

					/*-----------------------------------------------------*/

        } 
        SEMICOLON outblock PERIOD {

		displayLLVMfundecl(declhd);
          }
        ;

outblock
        : var_decl_part subprog_decl_part statement
        ;

var_decl_part
        : /* empty */
        | var_decl_list SEMICOLON
        ;

var_decl_list
        : var_decl_list SEMICOLON var_decl
	 | var_decl
	 ;

var_decl
        :VAR id_list {
        }
	 ;

subprog_decl_part
        : /* empty */
        | subprog_decl_list SEMICOLON
				;

subprog_decl_list
        : subprog_decl_list SEMICOLON subprog_decl
	| subprog_decl
	;

subprog_decl
        : proc_decl
				;

proc_decl
       : PROCEDURE proc_name SEMICOLON inblock {delete();}
       ;

proc_name
       : IDENT {flag = PROC_NAME; insert($1,flag);}  
                            {

		                     /*-----------------------------------------------------*/


                                   /* 以下プログラム名から関数のLLVMコードを生成するCプログラム*/
                                   /* このプログラムはProcedureがある場合のみ機能するので，main関数を含めることができていない */
					
                                   Fundecl *new;
					new = (Fundecl *)malloc(sizeof(Fundecl)); //メモリを動的に確保
					new->next = NULL;
                                   
                                   // 関数名等を保存
                                   
					strcpy(new->fname,$1);
                                   

                                    /* 線形リストのポインタを更新 */

                                   if(decltl == NULL){  /* 関数定義の線形リストの最初であるとき*/
                                         declhd = decltl = new;
                                   } else {             /* 関数定義の線形リストに1つ以上存在する時*/
                                          decltl->next = new;  // 関数定義列の末尾に*newを追加
                                          decltl = new;        // 関数定義列の末尾として*newを保存する

                                   };
					

					/*-----------------------------------------------------*/		
                                  
					
                            }
       ;

inblock
       : { flag = LOCAL_VAR; } var_decl_part statement /*flagを変更する*/
       ;

statement_list
       : statement_list SEMICOLON  statement
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
       : IDENT {lookup($1);} ASSIGN expression
                             {
                                   /*変数引数をスタックからpopしてレジスタへ格納する ｜Store*/

                                   LLVMcode* tmp;
                                   Factor arg1,arg2;

                                   tmp = memoryGet(tmp); 

                                   tmp->command=Store;

                                   arg1 = factorpop(); 
                                   
                                   strcpy(arg2.vname,$1);
                                   arg2.type = flag;
                                   arg2.val = cnrt;
                                   cnrt++;

                                   factorpush(arg2);

                                   (tmp->args).store.arg1 = arg1;
                                   (tmp->args).store.arg2 = arg2;

                                   addList(tmp);
                                   
                                   /*----------------------------*/
                            }

       ;

if_statement
       : IF condition THEN statement else_statement
       ;

else_statement
       : ELSE statement
       | /* empty */
       ;

while_statement
       : WHILE condition DO statement
       ;

for_statement
       : FOR IDENT {lookup($2);} ASSIGN expression TO expression DO statement
       ;

proc_call_statement
       : proc_call_name
       ;

proc_call_name
       : IDENT { lookup($1);}
       ;

block_statement
       : SBEGIN {
                     /* ここが，ブロックのはじめであるため，関数の書き出しを行うなら，ここであると考えらえれる*/
       }
       statement_list SEND
       ;

read_statement
       : READ LPAREN IDENT { lookup($3); } RPAREN
       ;

write_statement
       : WRITE LPAREN expression RPAREN
       ;

null_statement
       : /* empty */
       ;

condition
       : expression EQ expression
       | expression NEQ expression
       | expression LT expression
       | expression LE expression
       | expression GT expression
       | expression GE expression
       ;

expression
       : term
       | PLUS term
       | MINUS term
       | expression PLUS term
			 {
				 /* 加算命令をLLVMコードとして生成するCプログラム */
				 LLVMcode *tmp;            　　 //生成した命令へのポインタ
				 Factor arg1, arg2,retval; 　　//加算の引数、結果
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
       | expression MINUS term
                     {
                            
                            /* 減算命令をLLVMコードとして生成するCプログラム */
				 LLVMcode *tmp;            　　 //生成した命令へのポインタ
				 Factor arg1, arg2,retval; 　　//減算の引数、結果
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
       ;

term
       : factor
       | term MULT factor
                     {
                            /* 乗算命令をLLVMコードとして生成するCプログラム */
				 LLVMcode *tmp;            　　 //生成した命令へのポインタ
				 Factor arg1, arg2,retval; 　　//乗算の引数、結果
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
       | term DIV factor    
                     {
                            /* 除算命令をLLVMコードとして生成するCプログラム */
				 LLVMcode *tmp;            　　 //生成した命令へのポインタ
				 Factor arg1, arg2,retval; 　　//除算の引数、結果
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
       ;

factor
       : var_name
       | NUMBER {
				 /*定数引数をスタックへプッシュする*/

				 Factor number;
				 number.val = ($1);
				 number.type = CONSTANT;
				 factorpush(number);
                             /*----------------------------*/
         }
       | LPAREN expression RPAREN
       ;

var_name
       : IDENT { lookup($1);}

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
                                   
                            
				 
       ;

/*arg_list
       : expression
       | arg_list COMMA expression
       ;
*/
id_list
       : IDENT { insert($1,flag);} {
                            {
       
                                   /*変数を宣言する｜alloca*/

                                   LLVMcode* tmp;
                                   Factor retval;
                                   
                                   tmp = memoryGet(tmp); 
                                   switch(flag){
                                          case LOCAL_VAR:
                                                 tmp->command=Alloca;
                                                 break;
                                          case GLOBAL_VAR:
                                                 tmp->command=Global;
                                                 break;
                                          default:
                                                 break;
                                   }

                                   strcpy(retval.vname,$1);
                                   retval.type = flag;
                                   retval.val = cnrt;
                                   cnrt++;

                                    switch(flag){
                                          case LOCAL_VAR:
                                                 (tmp->args).alloca.retval = retval;
                                                 break;
                                          case GLOBAL_VAR:
                                                 (tmp->args).global.retval = retval;
                                                 break;
                                          default:
                                                 break;
                                    }
                                   addList(tmp);
                                   
                                   factorpush(retval);

                                   /*----------------------------*/
                            }

       }
       | id_list COMMA IDENT {insert($3,flag);} {

       
                                   /*変数を宣言する｜alloca*/

                                   LLVMcode* tmp;
                                   Factor retval;
                                   
                                   tmp = memoryGet(tmp); 
                                   switch(flag){
                                          case LOCAL_VAR:
                                                 tmp->command=Alloca;
                                                 break;
                                          case GLOBAL_VAR:
                                                 tmp->command=Global;
                                                 break;
                                          default:
                                                 break;
                                   }      
                                   strcpy(retval.vname,$3);
                                   retval.type = flag;
                                   retval.val = cnrt;
                                   cnrt++;

                                    switch(flag){
                                          case LOCAL_VAR:
                                                 (tmp->args).alloca.retval = retval;
                                                 break;
                                          case GLOBAL_VAR:
                                                 (tmp->args).global.retval = retval;
                                                 break;
                                          default:
                                                 break;
                                    }
                                   addList(tmp);
                                   
                                   factorpush(retval);

                                   /*----------------------------*/
                            }
       ;

%%
yyerror(char *s)
{
  fprintf(stderr, "%s line:%d token:%s\n", s ,yylineno,yytext);
}
