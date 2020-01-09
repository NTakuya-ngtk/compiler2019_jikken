#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "createllvm.h"
#include "symbol.h"

Factorstack fstack;  // 整数もしくはレジスタ番号を保持するスタック

void init_fstack(){
	fstack.top = 0;
	return;
}

Factor factorpop(){
	Factor tmp;
	tmp = fstack.element[fstack.top];
	fstack.top --;
	return tmp;
}

void factorpush(Factor x){
	fstack.top ++;
	fstack.element[fstack.top] = x;
	return;
}

void memoryGet(LLVMcode *tmp){
	tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保*/
	tmp->next = NULL;
}


void addList(LLVMcode *tmp){
	if(codetl == NULL){  /*解析中の関数の最初の命令の場合 */

		if( declhd == NULL){ /* 解析中の関数が無い場合 */
			/* 関数宣言を処理する段階でリストが造られるはずなので、有り得ない*/
			fprintf(stderr,"unexpected error\n");
		}

		declhd->codes = tmp; //関数定義の命令列の先頭の命令に設定
		codehd = codetl = tmp; // 生成中の命令列の末尾として記憶
	} else {                /*解析中の関数の命令列に1つ以上命令が存在する場合*/
		codetl->next = tmp;   //命令列の末尾に*tmpを追加
		codetl = tmp;        //生成中の命令列の末尾の命令として記憶
	}
}
		
	 
void dispalyFactor(Factor factor){
	switch(factor.type){
	  case GROBAL_VAR:
			printf("@%s", factor.vname);
			break;
	  case LOCAL_VAR:
			printf("%%%d", factor.val);
			break;
	  case CONSTANT:
			printf("%d",   factor.val);
			break;
	  default:
			break;
	}

	return;
}
		
void dispalyLLVMcodes(LLVMcode *code){
	if( code == NULL ){
		return;
	}

	printf("  ");

	switch( code->command){
		
	  case Alloca:
			displayFactor((code->args).alloca.retval);
			printf(" = alloca i32, align 4\n");
			break;

		
	  case Store:

			//工事中//

			
			break;


	  case Load:

			//工事中//
			
			break;

	  case BrUncond:


			//工事中//

			
			break;

	  case BrCond:

			//工事中//
			
			break;

	  case Label:

			//工事中//
			
			break;
			
		case Add:
			displayFactor((code->args).add.retval);
			printf(" = add nsw i32 %d %d\n",(code->args).add.arg1,(code->args).add.arg2);
			break;
			
		case Sub:

			//工事中//
			
			break;
			
		case Icmp:

			//工事中//
			
			break;

	  case ret:

			//工事中//
			
			break;

	  default:
			break;
	}

	displayLLVMcodes(code->next); // 再帰的に呼び出して、リストを全て出力する

}



void displayLLVMfundecl(Fundecl *decl){
	if(decl == NULL){
		return;
	}

	printf("define i32 @%s() {\n", decl->fname);
	displayLLVMcodes(decl->codes);
	printf("}\n");

	if(decl->next) != NULL){
	  printf("\n");
		displayLLVMfundecl(decl->next);// 再帰的に呼び出して、リストを全て出力する
   }
  return;
}

