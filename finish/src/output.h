#ifndef _OUTPUT_H_
#define _OUTPUT_H_

#include"./decl.h"

void init_fstack();
Factor factorpop();
void factorpush(Factor); 
void displayFactor( Factor);
void displayLlvmcodes( LLVMcode*);
void displayLlvmfundecl( Fundecl*);
#endif