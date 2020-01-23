#ifndef _TABLE_H_
#define _TABLE_H_

#define NAME_MAX 16

#include "createllvm.h"


void insert_data(char*,Scope,int);
Factor lookup_data(char*);
void delete_data();

#endif //_TABLE_H