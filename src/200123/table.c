#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include"table.h"


typedef struct{
    char *name[NAME_MAX];
    int locate;
    Scope scope;
    struct line *parent;
}line;


line *cur;



void insert_data(char *name,Scope scope,int cnt){
    line *tmp;
    tmp = (line *)malloc(sizeof(line));
    strcpy(tmp->name,name);
    tmp->scope = scope;
    tmp->parent = cur;
    tmp->locate = cnt;
    
    cur = tmp;


    /*テスト用出力*/
    printf("--insert--\n");
    line *i;
    for(i=cur;i->parent!=NULL;i=i->parent){
        printf("%s\t%d\t%d\n",i->name,i->locate,i->scope);
    }
    printf("%s\t%d\t%d\n",i->name,i->locate,i->scope);
    /**/
    return;
}

Factor lookup_data(char *name){
    line *i;
    Factor tmp;
    for(i=cur;i->parent!=NULL;i=i->parent){
        if(!(strcmp(i->name,name))){
            /* テスト用出力 */
            printf("--lookup--\n");
            printf("%s\t%d\t%d\n",i->name,i->locate,i->scope);
            /**/
            tmp.type = i->scope;
            tmp.val = i->locate;
            strcpy(tmp.vname,i->name);
            return tmp;
        }
    }

    /* テスト用出力 */
    printf("--lookup--\n");
    printf("can't find %s\n",name);
    /**/
    return tmp;
}

void delete_data(){
    line *tmp;
        while(cur->scope==LOCAL_VAR){
            tmp=cur->parent;
            free(cur);
            cur = tmp;
        }


    /* テスト用出力 */
    printf("--delete--\n");
    line *i;
    for(i=cur;i->parent!=NULL;i=i->parent){
        printf("%s\t%d\t%d\n",i->name,i->locate,i->scope);
    }
    printf("%s\t%d\t%d\n",i->name,i->locate,i->scope);
    /**/
    return;
}