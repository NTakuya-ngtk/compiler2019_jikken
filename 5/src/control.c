#include<stdlib.h>
#include "./control.h"


typedef struct list{
    LLVMcode *add;
    struct list *parent;
}List;

List* current = NULL;

typedef struct label_list{
    int num;
    struct label_list *parent;
}Label_List;
Label_List *now = NULL;

void add_add(LLVMcode *code){
    List *tmp;
    tmp = (List *)malloc(sizeof(List));
    tmp->add=code;
    
    tmp->parent = current;
    current = tmp;
}

void patch_if(int label){
    current->add->args.brcond.arg3 = label;
    current = current->parent;
}


void patch_if_else_1(int label){
    current->parent->add->args.brcond.arg3 = label;
    current->parent = current->parent->parent;
}

void patch_if_else_2(int label){
    current->add->args.bruncond.arg1 = label;
    current = current->parent;
}

void add_label(int label){
    Label_List *tmp;
    tmp = (Label_List *)malloc(sizeof(Label_List));
    tmp->num=label;
    
    tmp->parent = now;
    now = tmp;
}

void patch_label(LLVMcode *code){
    code->args.bruncond.arg1 = now->num;
    now = now->parent;
}