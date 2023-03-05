//
// Created by xxp on 2023/2/18.
//

#ifndef INC_1_TREE_FUNCTION_H
#define INC_1_TREE_FUNCTION_H

#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50
typedef int ElemType;
typedef struct {
    ElemType data[MaxSize];//数组
    int top;
} SqStack;

void InitStack(SqStack &S);
bool StackEmpty(SqStack S);
bool Push(SqStack &S, ElemType e);
bool GetTop(SqStack &S, ElemType &e);
bool Pop(SqStack &S, ElemType &e);


#endif//INC_1_TREE_FUNCTION_H
