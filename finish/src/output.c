#include"decl.h"
#include"output.h"
#include<stdio.h>
#include<stdlib.h>

int readflag=0;
int writeflag=0;

extern FILE *yyout;
LLVMcode *codehd = NULL; /* 命令列の先頭のアドレスを保持するポインタ */
LLVMcode *codetl = NULL; /* 命令列の末尾のアドレスを保持するポインタ */

Factorstack fstack; /* 整数もしくはレジスタ番号を保持するスタック */

/* 関数定義の線形リストの先頭の要素のアドレスを保持するポインタ */
Fundecl *declhd = NULL;
/* 関数定義の線形リストの末尾の要素のアドレスを保持するポインタ */
Fundecl *decltl = NULL;


void init_fstack(){ /* fstackの初期化 */
  fstack.top = 0;
  return;
}

Factor factorpop() {
  Factor tmp;
  tmp = fstack.element[fstack.top];
  fstack.top --;
  return tmp;
}

void factorpush(Factor x) {
  fstack.top ++;
  fstack.element[fstack.top] = x;
  return;
}

void displayFactor( Factor factor ){
        switch( factor.type ){
        case GLOBAL_VAR:
                fprintf(yyout,"@%s", factor.vname );
                break;
        case LOCAL_VAR:
                fprintf(yyout,"%%%d", factor.val );
                break;
        case CONSTANT:
                fprintf(yyout,"%d", factor.val );
                break;
        default:
                break;
        }
        return;
}

void displayLlvmcodes( LLVMcode *code ){
        if( code == NULL ) return;
        fprintf(yyout,"  ");
        switch( code->command ){
        case Alloca:
                displayFactor( (code->args).alloca.retval );
                fprintf(yyout," = alloca i32, align 4\n");
                
                break;
        case Store:
                fprintf(yyout,"store i32 ");
                displayFactor((code->args).store.arg1);
                fprintf(yyout,", i32* ");
                displayFactor((code->args).store.arg2);
                fprintf(yyout,", align 4\n");
                
                break;
        case Load:
                displayFactor((code->args).load.retval);
                fprintf(yyout," = load i32, i32* ");
                displayFactor((code->args).load.arg1);
                fprintf(yyout,", align 4\n");
                
                break;
        case BrUncond:
                fprintf(yyout,"br label %%%d\n",(code->args).bruncond.arg1);
                
                break;
        case BrCond:
                fprintf(yyout,"br i1 ");
                displayFactor((code->args).brcond.arg1);
                fprintf(yyout,", label %%%d, label %%%d\n",(code->args).brcond.arg2,(code->args).brcond.arg3);
                
                break;
        case Label:
               fprintf(yyout,"\n%d:\n",(code->args).label.l);
                break;
        case Add:
                displayFactor((code->args).add.retval);
                fprintf(yyout," = add nsw i32 ");
                displayFactor((code->args).add.arg1);
                fprintf(yyout,", ");
                displayFactor((code->args).add.arg2);
                fprintf(yyout,"\n");
                
                break;
        case Sub:
                displayFactor((code->args).sub.retval);
                fprintf(yyout," = sub nsw i32 ");
                displayFactor((code->args).sub.arg1);
                fprintf(yyout,", ");
                displayFactor((code->args).sub.arg2);
                fprintf(yyout,"\n");
                
                break;
        case Mul:
                displayFactor((code->args).mul.retval);
                fprintf(yyout," = mul nsw i32 ");
                displayFactor((code->args).mul.arg1);
                fprintf(yyout,", ");
                displayFactor((code->args).mul.arg2);
                fprintf(yyout,"\n");
                
                break;
        case Div:
                displayFactor((code->args).div.retval);
                fprintf(yyout," = sdiv i32 ");
                displayFactor((code->args).div.arg1);
                fprintf(yyout,", ");
                displayFactor((code->args).div.arg2);
                fprintf(yyout,"\n");
                
                break;
        case Icmp:
                displayFactor((code->args).icmp.retval);
                fprintf(yyout," = icmp ");
                switch ((code->args).icmp.type)
                {
                case EQUAL:
                        fprintf(yyout,"eq i32 ");
                        break;
                case NE:
                        fprintf(yyout,"ne i32 ");
                        break;
                case SGT:
                        fprintf(yyout,"sgt i32 ");
                        break;
                case SGE:
                        fprintf(yyout,"sge i32 ");
                        break;
                case SLT:
                        fprintf(yyout,"slt i32 ");
                        break;
                case SLE:
                        fprintf(yyout,"sle i32 ");
                        break;
                default:
                        break;
                }
                displayFactor((code->args).icmp.arg1);
                fprintf(yyout,", ");
                displayFactor((code->args).icmp.arg2);
                fprintf(yyout,"\n");
                
                break;
        case Call:
                fprintf(yyout,"call void @%s()\n",(code->args).call.name);
                break;
        case Read:
                displayFactor((code->args).read.retval);
                fprintf(yyout," = call i32 (i8*, ...) @__isoc99_scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str.1, i64 0, i64 0), i32* ");
                displayFactor((code->args).read.arg1);
                fprintf(yyout,")\n");
                break;
        case Write:
                displayFactor((code->args).write.retval);
                fprintf(yyout," = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str, i64 0, i64 0), i32 ");
                displayFactor((code->args).write.arg1);
                fprintf(yyout,")\n");
                break;
        default:

                break;
        }
        displayLlvmcodes( code->next );
}

void displayLlvmfundecl( Fundecl *decl ){
        if( decl == NULL ) return;
        if(writeflag == 2){
        fprintf(yyout,"@.str = private unnamed_addr constant [4 x i8] c\"%%d\\0A\\00\", align 1\n");
        writeflag--;
        }
        if(readflag== 2){
        fprintf(yyout,"@.str.1 = private unnamed_addr constant [3 x i8] c\"%%d\\00\", align 1\n");
        readflag--;
        }
        if(decl->ret==1){
        fprintf(yyout,"define i32 @%s() {\n", decl->fname );
        }else{
        fprintf(yyout,"define void @%s() {\n", decl->fname );        
        }
        displayLlvmcodes( decl->codes );
        if( decl->ret == 0 ) {
                fprintf(yyout,"  ret void\n");
                
        }else{
                fprintf(yyout,"  ret i32 0\n");
                
        }
        fprintf(yyout,"}\n");
        
        if( decl->next != NULL ) {
                fprintf(yyout,"\n");
                
                displayLlvmfundecl( decl->next );
        }
        if(writeflag == 1){
                fprintf(yyout,"declare dso_local i32 @printf(i8*, ...) #1\n");
                writeflag--;
        }
        if(readflag == 1){
                fprintf(yyout,"declare dso_local i32 @__isoc99_scanf(i8*, ...) #1\n");
                readflag--;
        }

        return;
}