#ifndef _CONTROL_H_
#define _CONTROL_H_

#include "decl.h"

void add_add(LLVMcode*);
void patch_if(int);
void patch_if_else_1(int);
void patch_if_else_2(int);
void add_label(int);
void patch_label(LLVMcode*);

#endif