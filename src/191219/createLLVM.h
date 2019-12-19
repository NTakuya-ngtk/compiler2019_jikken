#ifndef _CREATELLVM_H
#define _CREATELLVM_H


typedef enum{
	GLOBAL_VAR, /* 大域変数 */
	LOCAL_VAR,  /* 局所変数 */
	PROC_NAME,  /* 手続き  */
  	CONSTANT    /* 定数   */
	     
} Scope;


/* 引数を表す構造体 */
typedef struct{
	char  name[128];         /* 変数名を格納する */
	int   rNum;         /*レジスタ番号を格納する*/
	Scope type;         /* 大域変数,局所変数,手続き,定数の種別を格納する*/
}Factor ;

typedef struct{
	Factor element[100];  /*スタック 最大要素100まで*/
	unsigned int top;          /*スタックのトップ位置*/
}Factorstack;


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

typedef struct fundecl {
	char fname[256];      //関数名
	unsigned arity;       //引数個数
	Factor args[10]; //引数名
	LLVMcode *codes;      //命令列への線形ポインタ
	struct fundecl *next; //次の関数定義へのポインタ
}Fundecl;


LLVMcode *codehd = NULL;  // 命令列の先頭のアドレスを保持するポインタ
LLVMcode *codetl = NULL;  // 命令列の末尾のアドレスを保持するポインタ
Fundecl  *declhd = NULL;  // 関数定義の線形リストの先頭の要素を表すポインタ
Fundecl  *decltl = NULL;  // 関数定義の線形リストの末尾の要素を表すポインタ

void init_fstak(); /*fstackの初期化*/
Factor factorpop();
void factorpush(Factor x);
void memoryGet(LLVMcode *tmp); // memoryを確保する関数
void addList(LLVMcode *tmp);  // 命令列に新しい要素tmpを加える関数

void displayFactor(Factor factor); //要素の一覧を書き出す関数
void displayLLVMcodes(LLVMcode *code); // LLVMの命令列を書き出す関数
void displayLLVMfundecl(Fundecl *decl); // LLVMの関数列を書き出す関数


#endif
