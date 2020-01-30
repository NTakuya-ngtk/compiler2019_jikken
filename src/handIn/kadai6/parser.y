%{
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
	//init_fstack();  // スタックの初期化を行う
       int cnrt = 0;     // レジスタ番号
extern int readflag;
extern int writeflag;
       int procArgCount = 0;
       int procArgFlag = 0;
       int callCount;
	
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
                            // 大域変数を格納するfundeclを作るコード
                            Fundecl *new;
				new = (Fundecl *)malloc(sizeof(Fundecl)); //メモリを動的に確保
				new->next = NULL;

                             /* 線形リストのポインタを更新 */
                            declhd = new;
                            decltl = new;
                            
                            insert_data($3,PROC_NAME,0);
                     }
        SEMICOLON outblock
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
       : /* empty */ 
       { // ここがメイン関数の入るところ
         
                                   Fundecl *mainfunc;
					mainfunc = (Fundecl *)malloc(sizeof(Fundecl)); //メモリを動的に確保
					mainfunc->next = NULL;
                                   

                                   // main関数のため，"main"を格納
					strcpy(mainfunc->fname,"main");
                                   mainfunc->ret = 1;

                                   /* 線形リストのポインタを更新 */
                                    if(decltl == NULL) {   /* 関数定義の線形リストの最初であるとき*/
                                          declhd = decltl = mainfunc;
                                   } else {             /* 関数定義の線形リストに1つ以上存在する時*/
                                          decltl->next = mainfunc;  // 関数定義列の末尾に*newを追加
                                          decltl = mainfunc;        // 関数定義列の末尾として*newを保存する
                                   }

                                   // decltl->next = mainfunc;  // 関数定義列の末尾に*newを追加
                                   // decltl = mainfunc;        // 関数定義列の末尾として*newを保存する

                                   /* codehdおよびcodetlのリセット */
                                   codehd = codetl = NULL;

                                   /* main関数をAllocaするコード*/
                                   LLVMcode* tmp;
                                   Factor retval;

                                   tmp = memoryGet(tmp); 

                                   tmp->command=Alloca;
                                   cnrt = 1; // cnrtの初期化を行う

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
                                   arg1.val = 0; // 記号表の番地を代入する

                                   // factorpush(arg2);

                                   (tmp1->args).store.arg1 = arg1;
                                   (tmp1->args).store.arg2 = arg2;

                                   addList(tmp1);

       }
       | subprog_decl_list SEMICOLON  { // ここがメイン関数の入るところ
         
					// printf("debug");
                                   Fundecl *mainfunc;
					mainfunc = (Fundecl *)malloc(sizeof(Fundecl)); //メモリを動的に確保
					mainfunc->next = NULL;
                                   
                                   mainfunc->ret = 1; // 返り値の数

                                   // main関数のため，"main"を格納
					strcpy(mainfunc->fname,"main");

                                   /* 線形リストのポインタを更新 */
                                    if(decltl == NULL) {   /* 関数定義の線形リストの最初であるとき*/
                                          declhd = decltl = mainfunc;
                                   } else {             /* 関数定義の線形リストに1つ以上存在する時*/
                                          decltl->next = mainfunc;  // 関数定義列の末尾に*newを追加
                                          decltl = mainfunc;        // 関数定義列の末尾として*newを保存する
                                   }

                                   // decltl->next = mainfunc;  // 関数定義列の末尾に*newを追加
                                   // decltl = mainfunc;        // 関数定義列の末尾として*newを保存する

                                   /* codehdおよびcodetlのリセット */
                                   codehd = codetl = NULL;

                                   /* main関数をAllocaするコード*/
                                   LLVMcode* tmp;
                                   Factor retval;

                                   tmp = memoryGet(tmp); 

                                   tmp->command=Alloca;
                                   cnrt = 1; // cnrtの初期化を行う

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
                                   arg1.val = 0; // 記号表の番地を代入する

                                   // factorpush(arg2);

                                   (tmp1->args).store.arg1 = arg1;
                                   (tmp1->args).store.arg2 = arg2;

                                   addList(tmp1);

       }
	;

subprog_decl_list
       : subprog_decl_list SEMICOLON subprog_decl
	| subprog_decl
	;

subprog_decl
       : proc_decl
       ;

proc_decl
       : PROCEDURE proc_name SEMICOLON inblock {delete_data();}
       | PROCEDURE proc_name LPAREN proc_id_list RPAREN SEMICOLON inblock {delete_data();}
       ;

proc_name
       : IDENT {flag = PROC_NAME; insert_data($1,flag,0);}  
                            {

		                     /*-----------------------------------------------------*/

                                   /* 以下プログラム名から関数のLLVMコードを生成するCプログラム*/

					
                                   Fundecl *new;
                                   
					new = (Fundecl *)malloc(sizeof(Fundecl)); //メモリを動的に確保
					new->next = NULL;
                                   // 関数名等を保存
                                   strcpy(new->fname,$1);
                                   new->ret = 0;
					                            
                                    /* 線形リストのポインタを更新 */
                                    if(decltl == NULL) {   /* 関数定義の線形リストの最初であるとき*/
                                          declhd = decltl = new;
                                   } else {             /* 関数定義の線形リストに1つ以上存在する時*/
                                          decltl->next = new;  // 関数定義列の末尾に*newを追加
                                          decltl = new;        // 関数定義列の末尾として*newを保存する
                                   
                                   }

                                   // 新しい関数列ができたので，codehdとcodetlをnullにする
                                   codehd = codetl = NULL;
                                   // decltl->next = new;  // 関数定義列の末尾に*newを追加
                                   // decltl = new;        // 関数定義列の末尾として*newを保存する

                                   cnrt = 1; // cnrtの初期化

                                   /* -------------------------------------- */
                                   /* procedureをAllocaするコード*/
                                   // LLVMcode* tmp;
                                   // Factor retval;

                                   // tmp = memoryGet(tmp); 

                                   // tmp->command=Alloca;

                                   // cnrt = 1; // cnrtの初期化を行う

                                   // etval.type = LOCAL_VAR;
                                   // retval.val = cnrt;
                                   // cnrt++;

                                   // (tmp->args).alloca.retval = retval;
                                   
                                   // factorpush(retval);

                                   // addList(tmp);

                                   /* ----------------- */

                                   /* prodecureのコード番地をstoreするコード*/

                                   // LLVMcode* tmp1;
                                   // Factor arg1,arg2;

                                   // tmp1 = memoryGet(tmp1); 

                                   // tmp1->command=Store;

                                   // arg2 = factorpop();  /* 局所変数%1を取り出す*/
                                   
                                   // strcpy(arg1.vname,$1);
                                   // arg1.type = CONSTANT;
                                   // arg1.val = 0;        /* 記号表の番地を代入する */       

                                   // factorpush(arg2);

                                   // (tmp1->args).store.arg1 = arg1;
                                   // (tmp1->args).store.arg2 = arg2;

                                   // addList(tmp1);
					/*-----------------------------------------------------*/		
                                  
					
                            }
       ;

inblock
       : { flag = LOCAL_VAR; } 
       var_decl_part statement /* flagを変更する */ 
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
       : IDENT ASSIGN expression
                             {
                                  /*変数引数をスタックからpopしてレジスタへ格納する ｜Store*/

                                   LLVMcode* tmp;
                                   Factor arg1,arg2;

                                   tmp = memoryGet(tmp); 

                                   tmp->command=Store;

                                   arg1 = factorpop(); 
                                    
                                   strcpy(arg2.vname,$1);
                                   
                                   arg2 = lookup_data($1);

                                   factorpush(arg2);

                                   (tmp->args).store.arg1 = arg1;
                                   (tmp->args).store.arg2 = arg2;

                                   addList(tmp);
                                   
                                   /*----------------------------*/
                            }

       ;

if_statement
       : IF  condition
                      {

                                   /* 制御文を記述する */ // | Brcond

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
       THEN  
                     {

                                   /* 制御文を記述する */  // | Label

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
       
       
       statement    
       else_statement 
       ;

else_statement
       : ELSE        {

                                   
                                   /* 制御文を記述する */ // | BrUncond 

                                   LLVMcode* tmp1;
                                   int arg1;

                                   tmp1 = memoryGet(tmp1); 

                                   tmp1->command=BrUncond;

                                   addList(tmp1);


                                    /* 制御文を記述する */  // | Label

                                   LLVMcode* tmp2;
                                   int l;

                                   tmp2 = memoryGet(tmp2); 

                                   tmp2->command=Label;

                                   l = cnrt;
                                   cnrt++;

                                   (tmp2->args).label.l = l;

                                   addList(tmp2);

                                   // brスタックの管理 of label

                                   LLVMcode* backpatch1;

                                   backpatch1 = brpop();
                                   if(backpatch1->command == BrCond){
                                          (backpatch1->args).brcond.arg3 = l;
                                   }

                                   // brスタックの管理 of BrUncond
                                   brpush(tmp1);
                                   
                                   
                                   /*----------------------------*/
                     }
        statement 
                     {             /* 制御文を記述する */ // | BrUncond 

                                   LLVMcode* tmp1;
                                   int arg1;

                                   tmp1 = memoryGet(tmp1); 
                                   arg1 = cnrt;
                                   tmp1->command=BrUncond;

                                   (tmp1->args).bruncond.arg1 = arg1;

                                   addList(tmp1);

                                   /* 制御文を記述する */  // | Label

                                   LLVMcode* tmp;
                                   int l;

                                   tmp = memoryGet(tmp); 

                                   tmp->command=Label;

                                   l = cnrt;
                                   cnrt++;

                                   (tmp->args).label.l = l;

                                   addList(tmp);

                                   // brスタックの管理

                                   LLVMcode* backpatch;

                                   backpatch = brpop();
                                   if(backpatch->command == BrCond){
                                          (backpatch->args).brcond.arg3 = l;
                                   }else{
                                          (backpatch->args).bruncond.arg1 = l;
                                   }
                                   
                                   /*----------------------------*/
                     }
        
       | /* empty */ {            
                                    /* 制御文を記述する */ // | BrUncond 

                                   LLVMcode* tmp1;
                                   int arg1;

                                   tmp1 = memoryGet(tmp1); 
                                   arg1 = cnrt;
                                   tmp1->command=BrUncond;

                                   (tmp1->args).bruncond.arg1 = arg1;

                                   addList(tmp1);

                                   /* 制御文を記述する */  // | Label

                                   LLVMcode* tmp;
                                   int l;

                                   tmp = memoryGet(tmp); 

                                   tmp->command=Label;

                                   l = cnrt;
                                   cnrt++;

                                   (tmp->args).label.l = l;

                                   addList(tmp);

                                   // brスタックの管理

                                   LLVMcode* backpatch;

                                   backpatch = brpop();
                                   if(backpatch->command == BrCond){
                                          (backpatch->args).brcond.arg3 = l;
                                   }else{
                                          (backpatch->args).bruncond.arg1 = l;
                                   }
                                   
                                   /*----------------------------*/
                     }
       
       ;

while_statement
       : WHILE 
              {                    
                                   /* 制御文を記述する */ // | BrUncond 

                                   LLVMcode* tmp1;
                                   int arg1;

                                   tmp1 = memoryGet(tmp1); 

                                   tmp1->command=BrUncond;
                                   (tmp1->args).bruncond.arg1 = cnrt; // cnrt++; は不要

                                   addList(tmp1);

                                   
                                   
                                   
                                   /* 制御文を記述する */  // | Label

                                   LLVMcode* tmp;
                                   int l;

                                   tmp = memoryGet(tmp); 

                                   tmp->command=Label;

                                   l = jumpid= cnrt;
                                   cnrt++;

                                   (tmp->args).label.l = l;

                                   addList(tmp);
                            
                     }
       condition 
                     {
                                   /* 制御文を記述する */ // | Brcond

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

                                   /* 制御文を記述する */  // | Label

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
       DO statement  
                     {
                            /* 制御文を記述する */ // | BrUncond 

                                   LLVMcode* tmp1;
                                   int arg1;

                                   tmp1 = memoryGet(tmp1); 

                                   tmp1->command=BrUncond;

                                   (tmp1->args).bruncond.arg1 = jumpid;

                                   addList(tmp1);


                            /* 制御文を記述する */  // | Label

                                   LLVMcode* tmp2;
                                   int l;

                                   tmp2 = memoryGet(tmp2); 

                                   tmp2->command=Label;

                                   l = cnrt;
                                   cnrt++;

                                   (tmp2->args).label.l = l;

                                   addList(tmp2);

                            // brスタックの管理 

                                   LLVMcode* backpatch;

                                   backpatch = brpop();
                                   if(backpatch->command == BrCond){
                                          (backpatch->args).brcond.arg3 = l;
                                   }

                     }
       ;

for_statement
       : FOR IDENT ASSIGN expression 
                            {

                                  /* IDENTの番地に、expressionの値をstoreするコード*/

                                   LLVMcode* tmp1;
                                   Factor arg1,arg2;

                                   tmp1 = memoryGet(tmp1); 

                                   tmp1->command=Store;

                                   arg2 = lookup_data($2);
                                   arg1 = factorpop(); // IDENTの初期値
                                       
                                   (tmp1->args).store.arg1 = arg1;
                                   (tmp1->args).store.arg2 = arg2;

                                   addList(tmp1);

                   
                                   /* 制御文を記述する */ // | BrUncond 

                                   LLVMcode* tmp2;

                                   tmp2 = memoryGet(tmp2); 

                                   tmp2->command=BrUncond;

                                   (tmp2->args).bruncond.arg1 = cnrt; // cnrt++;は不要

                                   addList(tmp2);


                            /* 制御文を記述する */  // | Label

                                   LLVMcode* tmp3;
                                   int l;

                                   tmp3 = memoryGet(tmp3); 

                                   tmp3->command=Label;

                                   l = jumpid = cnrt;
                                   cnrt++;

                                   (tmp3->args).label.l = l;

                                   addList(tmp3);

                            }
       TO expression
                            {

                                   /* 与えられた引数を新引数をレジスタへ格納後スタック へプッシュする | Load*/
                                   LLVMcode* tmp0;

                                   Factor arg1L,retvalL;
                                   tmp0 = memoryGet(tmp0); 

                                   tmp0->command=Load;


                                   /* 記号表から引数のデータを取得 */
                                   arg1L = lookup_data($2);
                                   
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


                                   /* 制御文を記述する */ // | Brcond

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

                                   /* 制御文を記述する */  // | Label

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
       DO statement
                            {

                                   /* 加算命令でIDENTを1インクリメントする */
                                   LLVMcode *tmp;                //生成した命令へのポインタ
                                   Factor arg1, arg2,retval;      //加算の引数、結果
                                   tmp = memoryGet(tmp);          //mallocによるメモリ確保

                                   tmp->command = Add;
                                   
                                   arg2.type = CONSTANT;
                                   arg2.val = 1;

                                   arg1 = lookup_data($2);
                                   
                                   retval.type = LOCAL_VAR;  //結果を格納するレジスタは局所変数
                                   retval.val = cnrt;        // 新規のレジスタ番号を取得
                                   cnrt++;

                                   (tmp->args).add.arg1 = arg1;   /* 命令の第1引数を指定 */
                                   (tmp->args).add.arg2 = arg2;   /* 命令の第2引数を指定 */
                                   (tmp->args).add.retval = retval; /* 結果のレジスタを指定*/

                                   addList(tmp);                /* 新規命令として、命令列へ追加する*/
                                   
                                   factorpush( retval );       // 加算の結果をスタックへプッシュ

                                   /*-----------------------------------------*/


                                  /* インクリメントしたIDENTをstoreする */

                                   LLVMcode* tmp0;
                                   Factor arg1_1,arg2_1;

                                   tmp0 = memoryGet(tmp0); 

                                   tmp0->command=Store;

                                   arg2_1 = lookup_data($2);
                                   

                                   arg1_1 = factorpop(); 
                                       
                                   (tmp0->args).store.arg1 = arg1_1;
                                   (tmp0->args).store.arg2 = arg2_1;

                                   addList(tmp0);
                                   


                                    /* 制御文を記述する */ // | BrUncond 

                                   LLVMcode* tmp1;

                                   tmp1 = memoryGet(tmp1); 

                                   tmp1->command=BrUncond;

                                   (tmp1->args).bruncond.arg1 = jumpid;

                                   addList(tmp1);


                                    /* 制御文を記述する */  // | Label

                                   LLVMcode* tmp2;
                                   int l;

                                   tmp2 = memoryGet(tmp2); 

                                   tmp2->command=Label;

                                   l = cnrt;
                                   cnrt++;

                                   (tmp2->args).label.l = l;

                                   addList(tmp2);

                                   // brスタックの管理 

                                          LLVMcode* backpatch;

                                          backpatch = brpop();
                                          if(backpatch->command == BrCond){
                                                 (backpatch->args).brcond.arg3 = l;
                                          }


                            }
       ;

proc_call_statement
       : proc_call_name
       | proc_call_name LPAREN {procArgFlag =1; callCount = 0;}
        arg_list RPAREN  {procArgFlag = 0; LLVMcode*tmp; tmp = procCallpop(); addList(tmp);}
       ;

proc_call_name
       : IDENT 
       {             /* ----------- */
                     /* Call statement */
                     LLVMcode *tmp;
                     char name[10];

                     tmp = memoryGet(tmp);
                     tmp->command = Call;

                     strcpy(name,$1);

                     strcpy(tmp->args.call.name,name);
                     procCallpush(tmp);
       } 
       ;

block_statement
       : SBEGIN statement_list SEND
       ;

read_statement
       : READ LPAREN IDENT RPAREN
       {
                     LLVMcode *tmp;
                     Factor arg1,retval;

                     tmp = memoryGet(tmp);
                     tmp->command = Read;

                     arg1 = lookup_data($3);
                     retval.type = LOCAL_VAR;
                     retval.val = cnrt;
                     cnrt++;

                     (tmp->args).read.arg1 = arg1;
                     (tmp->args).read.retval = retval;

                     addList(tmp);

                     readflag=2;

       }
       ;

write_statement
       : WRITE LPAREN expression RPAREN
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

                             if(procArgFlag == 1 ){       //手続き呼び出しの引数の場合
                                   LLVMcode* call;
                                   call = procCallpop();
                                   (call->args).call.arg_list[callCount] = number.val;
                                   callCount++;
                                   procCallpush(call);
                             }
                             /*----------------------------*/
         }
       | LPAREN expression RPAREN
       ;

var_name
       : IDENT 

                            { 
                            
                            
                           

                                          /*与えられた引数を新引数をレジスタへ格納後スタック へプッシュする | Load*/
                                          LLVMcode* tmp;

                                          Factor arg1,retval;
                                          tmp = memoryGet(tmp); 

                                          tmp->command=Load;


                                          /* 記号表から引数のデータを取得 */
                                          arg1 = lookup_data($1);
                                          

                                          retval.type = LOCAL_VAR; /* 新規に変数を格納するのは局所変数 */
                                          retval.val = cnrt;
                                          cnrt++;

                                          (tmp->args).load.arg1 = arg1;
                                          (tmp->args).load.retval = retval;

                                          addList(tmp);
                                          
                                          factorpush(retval);

                                                                          
                                          /*----------------------------*/
                                          printf("\nprocArgFlag:%d\n",procArgFlag);

                                          if(procArgFlag == 1 ){       //手続き呼び出しの引数の場合
                                                 LLVMcode* call;


                                                 call = procCallpop();
                                                 ((call->args).call.arg_list)[callCount] = retval.val;
                                                 callCount++;
                                                 printf("\narglist[%d]:%d\n",callCount-1,((call->args).call.arg_list)[callCount-1]);
                                                 procCallpush(call);


                                          }
                            }
                                                        
				 
       ;

arg_list
       : expression  
       | arg_list COMMA expression 
       ;

id_list
       : IDENT { insert_data($1,flag,cnrt);} 
                            { 
                                   LLVMcode* tmp;
                                   tmp = memoryGet(tmp); 
                                   Factor retval;

                                   switch(flag){
                                          case GLOBAL_VAR:
                                                 /* 大域変数を出力する*/
                                                 displayGlobalVar($1);
                                                 break;
                                          
                                          case LOCAL_VAR:
                                         
                                                 /* 局所変数の領域をAllocaするコード*/
                                                 tmp = memoryGet(tmp); 

                                                 tmp->command=Alloca;

                                                 // cnrt = 1; // cnrtの初期化を行う

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

       
       | id_list COMMA IDENT {insert_data($3,flag,cnrt);}
                            {
                                   LLVMcode* tmp;
                                   tmp = memoryGet(tmp); 
                                   Factor arg1,retval;
                                   switch(flag){
                                          case GLOBAL_VAR:
                                                 /* 大域変数を出力する*/
                                                 displayGlobalVar($3);
                                                 break;
                                          case LOCAL_VAR:
                                                 /* 局所変数の領域をAllocaするコード*/

                                                 tmp = memoryGet(tmp); 

                                                 tmp->command=Alloca;

                                                 // cnrt = 1; // cnrtの初期化を行う

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
       ;

proc_id_list
       : IDENT 
       {      LLVMcode* tmp;
              tmp = memoryGet(tmp); 
              Factor retval;

              tmp = memoryGet(tmp); 

              tmp->command=Alloca;

               insert_data($1,LOCAL_VAR,cnrt); 
               cnrt++;

              // cnrt = 1; // cnrtの初期化を行う

              retval.type = LOCAL_VAR;
              retval.val = cnrt;
              cnrt++;
              procArgCount++;

              (tmp->args).alloca.retval = retval;
              
              factorpush(retval);

              addList(tmp);   

               /* allocaした番地を番地をstoreするコード*/

              LLVMcode* tmp1;
              Factor arg1,arg2;

              tmp1 = memoryGet(tmp1); 

              tmp1->command=Store;

              arg2 = factorpop();  /* 局所変数を取り出す*/
              
              // strcpy(arg1.vname,$1);
              arg1.type = CONSTANT;
              arg1.val = 0; // 記号表の番地を代入する

              // factorpush(arg2);

              (tmp1->args).store.arg1 = arg1;
              (tmp1->args).store.arg2 = arg2;

              addList(tmp1);        
             
       } 
       | proc_id_list COMMA IDENT 
       {      LLVMcode* tmp;
              tmp = memoryGet(tmp); 
              Factor retval;

              tmp = memoryGet(tmp); 

              tmp->command=Alloca;

               insert_data($3,LOCAL_VAR,cnrt); 
               cnrt++;

              // cnrt = 1; // cnrtの初期化を行う

              retval.type = LOCAL_VAR;
              retval.val = cnrt;
              cnrt++;
              procArgCount++;

              (tmp->args).alloca.retval = retval;
              
              factorpush(retval);

              addList(tmp);

              /* allocaした番地を番地をstoreするコード*/

              LLVMcode* tmp1;
              Factor arg1,arg2;

              tmp1 = memoryGet(tmp1); 

              tmp1->command=Store;

              arg2 = factorpop();  /* 局所変数を取り出す*/
              
              // strcpy(arg1.vname,$1);
              arg1.type = CONSTANT;
              arg1.val = 0; // 記号表の番地を代入する

              // factorpush(arg2);

              (tmp1->args).store.arg1 = arg1;
              (tmp1->args).store.arg2 = arg2;

              addList(tmp1);
       } 
       ;

%%
yyerror(char *s)
{
  fprintf(stderr, "%s line:%d token:%s\n", s ,yylineno,yytext);
}
