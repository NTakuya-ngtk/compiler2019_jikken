#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "symbol.h"
#include "createllvm.h"


/* insert function */

void insert(char *NewName,Scope NewType){
	
	SymbolTable *new;


	if((new=(struct SymbolTable *)malloc(sizeof(SymbolTable)))==NULL){
		return;
	}
	if(root == NULL){
		new->next = NULL;
	}else{
		new->next = root;
	}
	strcpy(new->name,NewName); //文字列の代入
	// printf("nt:%d\n",NewType);
	new->type = NewType;
	root = new;
	//printf("nt:%d\n",new->type);
	
//	printf("InsertData:%s,%d,%d\n",new->name,new->rNum,new->type);

	//return(void);
}

/* lookup関数 */

void lookup(char *SearchName){

	SymbolTable *temp;
	
	temp = root;
	// printf("serchName:%s",SearchName);
	
	while(1){
		
		if(strcmp(temp->name,SearchName)==0){
			varType = temp->type;
			//sprintf(tempstr,"%s,%d",temp->name,temp->type);
			//printf("%s,%d",temp->name,temp->type);
			return;
		}
		if(temp->next == NULL){
			break;
		}
		temp = temp->next;
	}
}


/* delete関数 */
void delete(){

	SymbolTable *rec;
	
	while(1){
		rec = root->next;
		if(rec->type == (Scope)(PROC_NAME)){
			root->next = rec;
//			printf("Deleted until %s\n",rec->name);
			break;														 
		}else{
			root->next = rec->next;
		}
	}
}
