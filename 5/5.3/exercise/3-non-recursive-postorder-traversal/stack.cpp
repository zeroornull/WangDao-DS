//
// Created by xxp on 2023/2/19.
//
#include "function.h"
bool Pop(SqStack &S, ElemType &e) {
    if (StackEmpty(S)) {
        return false;
    }
    //  等价 e = S.data[S.top];S.top--;
    e = S.data[S.top--];
    return true;
}
bool GetTop(SqStack &S, ElemType &e) {
    if (StackEmpty(S)) {
        return false;
    }
    e = S.data[S.top];
    return true;
}
/**
 * 入栈
 * @param S
 * @param e
 * @return
 */
bool Push(SqStack &S, ElemType e) {
    // 判断
    if (S.top == MaxSize - 1) {
        return false;
    }
    // 等价S.top++; S.data[S.top] = e;
    S.data[++S.top] = e;
    return true;
}
bool StackEmpty(SqStack S) {
    if (S.top == -1) {
        return true;
    } else {
        return false;
    }
}
/**
 * 初始化栈
 * @param S
 */
void InitStack(SqStack &S) { S.top = -1; }