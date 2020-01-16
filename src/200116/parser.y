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
       int cnrt = 1;     // レジスタ番号
	
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
       :      {
                     /* 出力ファイルを書き込む部分 */
                     if((fp = fopen("result.ll","w")) == NULL){
                            fprintf(stderr, "result.llのオープンに失敗しました\n");
                            exit(1);
                     }
              }
       PROGRAM IDENT {
                            //大域変数を格納するfundeclを作るコード
                             Fundecl *new;
				 new = (Fundecl *)malloc(sizeof(Fundecl)); //メモリを動的に確保
				 new->next = NULL;

                             /* 線形リストのポインタを更新 */
                             declhd = decltl = new;
                             new->codes = NULL;       //命令セットは持たないため．
                            
                                   
                            }
        SEMICOLON outblock {
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
       PERIOD
              {      
	       	displayLLVMfundecl(declhd);
                     fclose(fp);
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
       : /* empty */ { // ここがメイン関数の入るところ
         
					// printf("debug");
                                   Fundecl *new;
					new = (Fundecl *)malloc(sizeof(Fundecl)); //メモリを動的に確保
					new->next = NULL;
                                   

                                   // main関数のため，"main"を格納
					strcpy(new->fname,"main");

                                    /* 線形リストのポインタを更新 */
                                   decltl->next = new;  // 関数定義列の末尾に*newを追加
                                   decltl = new;        // 関数定義列の末尾として*newを保存する

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
                                   
                                   // strcpy(arg1.vname,$1);
                                   arg1.type = CONSTANT;
                                   arg1.val = 0;

                                   // factorpush(arg2);

                                   (tmp1->args).store.arg1 = arg1;
                                   (tmp1->args).store.arg2 = arg2;

                                   addList(tmp1);

       }
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
                                   /* このプログラムはProcedureがある場合のみ機能するので，main関数を含めることができない． */
                                   /* また，llvmcodesポインタの管理をまだ行っていない */
					
                                   Fundecl *new;
                                   
					new = (Fundecl *)malloc(sizeof(Fundecl)); //メモリを動的に確保
					new->next = NULL;
                                   // 関数名等を保存
                                   strcpy(new->fname,$1);
					                            
                                    /* 線形リストのポインタを更新 */
                                    decltl->next = new;  // 関数定義列の末尾に*newを追加
                                    decltl = new;        // 関数定義列の末尾として*newを保存する					

					/*-----------------------------------------------------*/		
                                  
					
                            }
       ;

inblock
       : { flag = LOCAL_VAR; } 
       var_decl_part statement /*flagを変更する*/
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
       : IDENT 
       {/* lookup($1); */ } 
       ASSIGN expression
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

                                   factorpush(arg2);

                                   (tmp->args).store.arg1 = arg1;
                                   (tmp->args).store.arg2 = arg2;

                                   addList(tmp);
                                   
                                   /*----------------------------*/
                            }

       ;

if_statement
       : IF          {           /*

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
       condition THEN {

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
       statement else_statement 
       ;

else_statement
       : ELSE statement
       | /* empty */
       ;

while_statement
       : WHILE condition DO statement
       ;

for_statement
       : FOR IDENT {/* lookup($2); */ } ASSIGN expression TO expression DO statement
       ;

proc_call_statement
       : proc_call_name
       ;

proc_call_name
       : IDENT { /* lookup($1); */ }  /* ソースコード中の手続きを呼び出ししている箇所*/
       ;

block_statement
       : SBEGIN { // brcondとbruncondでどちらも記述しているが，それが正しいか確認する必要がある．
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
                                                 (backpatch->args).brcond.arg3 = l; // このパスは何故か通っていない。
                                          }
                                          
                                   }
                                   /*----------------------------*/
       }
       statement_list SEND
       ;

read_statement
       : READ LPAREN IDENT { /* lookup($3);*/ } RPAREN
       ;

write_statement
       : WRITE LPAREN expression RPAREN
       ;

null_statement
       : /* empty */
       ;

condition
       : expression EQ expression
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
       
       | expression NEQ expression
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
       | expression LT expression
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
       | expression LE expression
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
       | expression GT expression
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
       | expression GE expression
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
       ;

expression
       : term
       | PLUS term
       | MINUS term
       | expression PLUS term

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
       | expression MINUS term
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
       ;

term
       : factor
       | term MULT factor
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
       | term DIV factor    
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
       : IDENT { /* lookup($1);*/}

                            { 
                                   
                             /*与えられた引数を新引数をレジスタへ格納後スタック へプッシュする | Load*/
                             LLVMcode* tmp;

                             Factor arg1,retval;
                             tmp = memoryGet(tmp); 

                             tmp->command=Load;


                             /* 記号表から引数のデータを取得 */
                             lookup($1);
                             strcpy(arg1.vname,$1);
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
                                                        
				 
       ;

/*arg_list
       : expression
       | arg_list COMMA expression
       ;
*/
id_list
       : IDENT { insert($1,flag);} 
                            { 
                                   LLVMcode* tmp;
                                   tmp = memoryGet(tmp); 
                                   Factor arg1,retval;

                                   switch(varType){
                                          case GLOBAL_VAR:
                                                 /* 大域変数を出力する*/
                                                 displayGlobalVar($1);
                                                 break;
                                          
                                          case LOCAL_VAR:
                                          /*与えられた引数を新引数をレジスタへ格納後スタック へプッシュする | Load*/
                                                 

                                                 tmp->command=Load;


                                                 /* 記号表から引数のデータを取得 */
                                                 lookup($1);
                                                 strcpy(arg1.vname,$1);
                                                 arg1.type = varType;
                                                 

                                                 retval.type = LOCAL_VAR; /* 新規に変数を格納するのは局所変数 */
                                                 retval.val = cnrt;
                                                 cnrt++;

                                                 (tmp->args).load.arg1 = arg1;
                                                 (tmp->args).load.retval = retval;

                                                 addList(tmp);
                                                 
                                                 factorpush(retval);
                                                 break;
                                   
                                          default:
                                                 break;
                                     
                                     }

                                   /*----------------------------*/
                            }

       
       | id_list COMMA IDENT {insert($3,flag);}
                            {
                                   LLVMcode* tmp;
                                   tmp = memoryGet(tmp); 
                                   Factor arg1,retval;
                                   switch(varType){
                                          case GLOBAL_VAR:
                                                 /* 大域変数を出力する*/
                                                 displayGlobalVar($3);
                                                 break;
                                          case LOCAL_VAR:
                                           /* 与えられた引数を新引数をレジスタへ格納後スタック へプッシュする | Load*/
                                                 

                                                 tmp->command=Load;


                                                 /* 記号表から引数のデータを取得 */
                                                 lookup($3);
                                                 strcpy(arg1.vname,$3);
                                                 arg1.type = LOCAL_VAR;
                                                 

                                                 retval.type = LOCAL_VAR; /* 新規に変数を格納するのは局所変数 */
                                                 retval.val = cnrt;
                                                 cnrt++;

                                                 (tmp->args).load.arg1 = arg1;
                                                 (tmp->args).load.retval = retval;

                                                 addList(tmp);
                                                 
                                                 factorpush(retval);
                                                 break;
                                   
                                          default:
                                                 break;
                                  }


                                   /*----------------------------*/
                            }
       ;

%%
yyerror(char *s)
{
  fprintf(stderr, "%s line:%d token:%s\n", s ,yylineno,yytext);
}
