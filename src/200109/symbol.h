#ifndef _SYMBOL_H
#define _SYMBOL_H

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
	struct SymbolTable *next;  /*構造体の次のポインタを表す */
}SymbolTable ;


void insert(char *NewName,Scope NewType);
void lookup(char *SearchName);
SymbolTable *root=NULL;



#endif
