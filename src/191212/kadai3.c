#include <stdio.h>
#include <string.h>

typedef enum{
	GLOBAL_VAR, /* 大域変数 */
	LOCAL_VAR,  /* 局所変数 */
	PROC_NAME,  /* 手続き  */
  CONSTANT    /* 定数   */
	     
} Scope;

/* 構造体で記号表の線形リストを実現する */
typedef struct SymbolTable{
	char  *name;         /* 変数名を格納する */
	int   rNum;         /*レジスタ番号を格納する*/
	Scope type;         /* 大域変数,局所変数,手続き,定数の種別を格納する*/
	struct SymbolTable *next;  /*構造体の次のポインタを表す */
	struct SymbolTable *previous; /*構造体の前のポインタを表す */
}SymbolTable ;


/* insert function */

void insert(SymbolTable *before,char *NewName,Scope NewType,SymbolTable *new){

	/* スタックへプッシュする */

	new->name = NewName; //文字列ポインタの更新
	new->rNum = before->rNum+1; //レジスタ番号の更新なので、ここは分岐があるかと。
	new->type = NewType;
	new->previous = new;
	new->next = NULL;
	before->next = new;

	printf("%s,%d,%d\n",new->name,new->rNum,new->type);

	//return(void);
}

void lookup(SymbolTable *root,char *SearchName){

	SymbolTable *ref;
	char *SymbolName;
	//int num = 0;

	ref = root; // refの初期化

	while(1){
		SymbolName = ref->name;
		//printf("%d:%s,%s\n",num,SymbolName,SearchName);

		if(strcmp(SymbolName,SearchName)==0){
			printf("VarName:%s,VarType:%d\n",ref->name,ref->type);
			break;
		}else{
			ref = ref->previous;
			if(ref == NULL){
				break;
			}
		}

		num++;
	}

	//return();
}

void delete(SymbolTable *root){
	SymbolTable *ref;

	ref = root;

	while(1){
		if(ref->type == (Scope)(PROC_NAME)){
			ref->next = NULL;
			
			break;																 
		}else{
			ref = ref->next;
		}
}


// ./kadai3 "text_name" {0,1,2} || {0:GLOBAL_VAR,1:LOCAL_VAR,2:PROC_NAME}
int main(int argc,char *argv[]){
  SymbolTable root; /* 線形リストの根になる */

	SymbolTable rec;
	char *aryT[5] = {"text0","text1","text2","text3","text4"};
	int  aryN[5] = {0,0,1,2,1};
	int i;
	
	root.name = "root";
	root.rNum = 0;
	root.type = CONSTANT;
	root.next = NULL;
	root.previous = NULL;

  char *newName = argv[1];
	Scope newType;


	/*
	if(strcmp(argv[2],"0")==0){
		newType = GLOBAL_VAR;
	}else if(strcmp(argv[2],"1")==0){
		newType = LOCAL_VAR;
	}else if(strcmp(argv[2],"2")==0){
		newType = PROC_NAME;
	}else{
		printf("error\n");
		exit(1);
	 }
	*/

	rec = root;
	
	for(i=0;i<5;i++){
		SymbolTable new;
		insert(&rec,aryT[i],aryN[i],&new);
		rec = new;
	}
	root = rec;

	lookup(&root,"text4");
	//insert(&root,newName,newType,&new);

	return(0);

}
