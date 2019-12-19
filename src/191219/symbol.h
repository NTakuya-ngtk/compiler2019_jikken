#ifndef _SYMBOL_H
#define _SYMBOL_H

typedef enum{
	GLOBAL_VAR, /* 大域変数 */
	LOCAL_VAR,  /* 局所変数 */
	PROC_NAME,  /* 手続き  */
  CONSTANT    /* 定数   */
	     
} Scope;

/* LLVM 命令の種類 */
typedef enum{
	Alloca,   /* alloca */
	Store,    /* Store */
	Load,     /* Load  */
	BrUncond, /*  br   */
	BrCond,    /*  brc  */
	Label,     /* label  */
	Add,       /* add    */
	Sub,       /* sub    */
	Icmp,      /* icmp   */
	Ret       /* ret    */     
} LLVMcommand;

/* 比較演算子の種類 */
typedef enum {
	EQUAL, /* eq （==）*/
	NE, /* ne （!=）*/
	SGT, /* sgt （>，符号付き） */
	SGE, /* sge （>=，符号付き）*/
	SLT, /* slt （<，符号付き） */
	SLE /* sle （<=，符号付き）*/
} Cmptype;

/*LLVM-IRの命令を表現する構造体*/
// Factorって構造体？的なのだろうけど、どこで定義してる？
typedef struct llvmcode {
	LLVMcommand command; //命令名
	union {         // 命令の引数
		struct {   //alloca
			Factor retval;
		}alloca;

		struct {   //store
			Factor arg1; Factor arg2;
		}store;

		struct {   //load
			Factor arg1; Factor retval;
		}load;

		struct {   //br
			int arg1;
		}bruncond;

		struct {   //brc
			Factor arg1;  int arg2;  int arg3;
		}brcond;

		struct {   //label
			int l;
		}label;

		struct {   //add
			Factor arg1;  Factor arg2; Factor retval;
		}add;

		struct {   //sub
			Factor arg1; Factor arg2; Factor retval;
		}sub;

		struct {   //icmp
			Cmptype type; Factor arg1; Factor arg2; Factor retval;
		}icmp;

		struct {  //ret
			Factor arg1;
		}ret;
	}args;

	struct llvmcode *next;  // 次の命令へのポインタ
}LLVMcode;

LLVMcode *codehd = NULL;  // 命令列の先頭のアドレスを保持するポインタ
LLVMcode *codetl = NULL;  // 命令列の末尾のアドレスを保持するポインタ
			


/* 構造体で記号表の線形リストを実現する */
typedef struct{
	char  name[10];         /* 変数名を格納する */
	int   rNum;         /*レジスタ番号を格納する*/
	Scope type;         /* 大域変数,局所変数,手続き,定数の種別を格納する*/
	struct SymbolTable *next;  /*構造体の次のポインタを表す */
}SymbolTable ;

void insert(char *NewName,Scope NewType);
void lookup(char *SearchName);
SymbolTable *root=NULL;

#endif
