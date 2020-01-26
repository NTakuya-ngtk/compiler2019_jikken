#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "createllvm.h"
#include "table.h"
#define FP fp

int readflag = 0;
int writeflag = 0;


Factorstack fstack;  // 整数もしくはレジスタ番号を保持するスタック
brstack bstack;       // 関数の戻り位置を保持するスタック

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


void init_brstak(){
	bstack.top = 0;
	return;
}

LLVMcode* brpop(){
	LLVMcode* tmp;
	tmp = bstack.element[bstack.top];
	bstack.top --;
	return tmp;
}

void brpush(LLVMcode* x){
	bstack.top ++;
	bstack.element[bstack.top] = x;
	return;
}

LLVMcode* memoryGet(LLVMcode *tmp){
	tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保*/
	tmp->next = NULL;
	return tmp;
}


void addList(LLVMcode *tmp){
	if(codetl == NULL){  /*解析中の関数の最初の命令の場合 */

		if( declhd == NULL){ /* 解析中の関数が無い場合 */
			/* 関数宣言を処理する段階でリストが造られるはずなので、有り得ない*/
			fprintf(stderr,"unexpected error\n");
		}

		decltl->codes = tmp; //関数定義の命令列の先頭の命令に設定
		codehd = codetl = tmp; // 生成中の命令列の末尾として記憶
	} else {                /*解析中の関数の命令列に1つ以上命令が存在する場合*/
		codetl->next = tmp;   //命令列の末尾に*tmpを追加
		codetl = tmp;        //生成中の命令列の末尾の命令として記憶
	}
}

void displayGlobalVar(char *varname){
	fprintf(FP,"@%s",varname);
	fprintf(FP," = ");
	fprintf(FP,"common global i32 0, align 4");
	fprintf(FP,"\n");
	return;

}
	 
void displayFactor(Factor factor){
	switch(factor.type){
	  case GLOBAL_VAR:
			fprintf(FP,"@%s", factor.vname);
			break;
	  case LOCAL_VAR:
			fprintf(FP,"%%%d", factor.val);
			break;
	  case CONSTANT:
			fprintf(FP,"%d",   factor.val);
			break;
	  default:
			break;
	}

	return;
}
		
void displayLLVMcodes(LLVMcode *code){
	if( code == NULL ){
		return;
	}

	fprintf(FP,"  ");

	switch( code->command){
		
		case Alloca:
			displayFactor((code->args).alloca.retval);
			fprintf(FP," = ");
			fprintf(FP,"alloca i32, align 4");
			fprintf(FP,"\n");
			break;

		// LLVMcodesの中で，Globalが出てくることはない．	
		/*case Global:
			displayFactor((code->args).global.retval);
			fprintf(FP," = ");
			fprintf(FP,"common global i32 0, align 4");
			fprintf(FP,"\n");
			break;
		*/

		case Store:
			fprintf(FP,"store i32 ");
			displayFactor((code->args).store.arg1);
			fprintf(FP,", i32* ");
			displayFactor((code->args).store.arg2);
			fprintf(FP,", align 4"); 
			fprintf(FP,"\n");
			
			break;

		case Load:
			displayFactor((code->args).load.retval);
			fprintf(FP," = ");
			fprintf(FP,"load i32, i32* ");
			displayFactor(((code->args).load.arg1));
			fprintf(FP, ", align 4"); 
			fprintf(FP,"\n");
			
			break;

		case BrUncond:
			fprintf(FP,"br label %d",((code->args).bruncond.arg1));
			fprintf(FP,"\n");

			break;

	  	case BrCond:
			fprintf(FP,"br i1 ");
			displayFactor((code->args).brcond.arg1);
			fprintf(FP,", label %%%d, label %%%d",(code->args).brcond.arg2,(code->args).brcond.arg3);
			fprintf(FP,"\n");
			break;

		case Label:
			fprintf(FP,"\n");
			fprintf(FP,"; <label>:%d:",(code->args).label.l);
			fprintf(FP,"\n");

			break;
			
		case Add: 
			displayFactor((code->args).add.retval);
			fprintf(FP," = ");
			fprintf(FP,"add nsw i32 ");
			displayFactor((code->args).add.arg1);
			fprintf(FP,", ");
			displayFactor((code->args).add.arg2);
			//fprintf(FP,"add nsw i32 %d, %d",(code->args).add.arg1.val,(code->args).add.arg2.val);
			fprintf(FP,"\n");
			break;
			
		case Sub:
			displayFactor((code->args).sub.retval);
			fprintf(FP," = ");
			fprintf(FP,"sub nsw i32 ");
			displayFactor((code->args).sub.arg1);
			fprintf(FP,", ");
			displayFactor((code->args).sub.arg2);
			//fprintf(FP,"sub nsw i32 %d, %d",(code->args).sub.arg1.val,(code->args).sub.arg2.val);
			fprintf(FP,"\n");
			break;


		case Mul:
			displayFactor((code->args).mul.retval);
			fprintf(FP," = ");
			fprintf(FP,"mul nsw i32 ");
			displayFactor((code->args).mul.arg1);
			fprintf(FP,", ");
			displayFactor((code->args).mul.arg2);
			//fprintf(FP,"mul nsw i32 %d, %d",(code->args).mul.arg1.val,(code->args).mul.arg2.val);
			fprintf(FP,"\n");
			break;

		case Div:
			displayFactor((code->args).sdiv.retval);
			fprintf(FP," = ");
			fprintf(FP,"sdiv i32 ");
			displayFactor((code->args).sdiv.arg1);
			fprintf(FP,", ");
			displayFactor((code->args).sdiv.arg2);
			//fprintf(FP,"sdiv i32 %d, %d",(code->args).sdiv.arg1.val,(code->args).sdiv.arg2.val);
			fprintf(FP,"\n");
			break;
			
		case Icmp:
			displayFactor((code->args).icmp.retval);
			fprintf(FP," = icmp ");
			switch((code->args).icmp.type){
				case EQUAL:
					fprintf(FP,"eq ");
					break;
				case NE:
					fprintf(FP,"ne ");
					break;
				case SGT:
					fprintf(FP,"sgt ");
					break;
				case SGE:
					fprintf(FP,"sge ");
					break;
				case SLT:
					fprintf(FP,"slt ");
					break;
				case SLE:
					fprintf(FP,"sle ");
					break;
			}
			fprintf(FP,"i32 ");
			displayFactor((code->args).icmp.arg1);
			fprintf(FP,", ");
			displayFactor((code->args).icmp.arg2);
			fprintf(FP,"\n");
			
			break;

	  	case Ret:
			fprintf(FP,"ret ");
			if(((code->args).ret.arg1.type) == CONSTANT){
				fprintf(FP,"i32 ");
				displayFactor((code->args).ret.arg1);
				fprintf(FP,"\n");
			}else{  /*args.retが1でないに返り値のないvoidとして出力する*/
				fprintf(FP,"void ");
				fprintf(FP,"\n");
			}
			break;
		
		case Call:
			fprintf(FP,"call void @%s()\n",(code->args).call.name);
			break;

		case Read:
			displayFactor((code->args).read.retval);
			fprintf(FP," = call i32 (i8*, ...) @__isoc99_scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str.1, i64 0, i64 0), i32* ");
			displayFactor((code->args).read.arg1);
			fprintf(FP,")\n");
			break;

		case Write:
			displayFactor((code->args).write.retval);
			fprintf(FP," = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str, i64 0, i64 0), i32 ");
			displayFactor((code->args).write.arg1);
			fprintf(FP,")\n");
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

	if(writeflag == 2){
	fprintf(FP,"@.str = private unnamed_addr constant [4 x i8] c\"%%d\\0A\\00\", align 1\n");
	writeflag--;
	}
	if(readflag== 2){
	fprintf(FP,"@.str.1 = private unnamed_addr constant [3 x i8] c\"%%d\\00\", align 1\n");
	readflag--;
	}



	if(decl->codes != NULL){

		if(decl->ret ==1){
			fprintf(FP,"define i32 @%s() {\n", decl->fname);
		} else {
			fprintf(FP,"define void @%s() {\n", decl->fname);
		}

		displayLLVMcodes(decl->codes);
		fprintf(FP,"}\n");
	}
	

	if(decl->next != NULL){
	  fprintf(FP,"\n");
		displayLLVMfundecl(decl->next);// 再帰的に呼び出して、リストを全て出力する
   }


	if(writeflag == 1){
		fprintf(FP,"declare dso_local i32 @printf(i8*, ...) #1\n");
		writeflag--;
	}

	if(readflag == 1){
		fprintf(FP,"declare dso_local i32 @_isoc99_scanf(i8*, ...) #1\n");
		readflag--;
	}



  return;
}

