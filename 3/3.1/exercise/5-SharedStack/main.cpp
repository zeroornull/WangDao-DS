#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100
typedef int ElemType;
typedef struct {
    ElemType data[MaxSize];
    int top[2];
} SqStack;
SqStack s;

void InitStack(SqStack &S);
int Push(int i, ElemType e);
int Pop(int i);
int main() {
    InitStack(s);
    return 0;
}
void InitStack(SqStack &S) {
    S.top[0] = -1;
    S.top[1] = MaxSize;
}
int Push(int i, ElemType e) {
    if (i < 0 || i > 1) {
        printf("illegal input");
        exit(0);
    }
    if (s.top[0] == s.top[1]) {
        printf("stack full");
        return 0;
    }
    switch (i) {
        case 0:
            s.data[++s.top[0]] = e;
            return 1;
            break;
        case 1:
            s.data[--s.top[1]] = e;
            return 1;
            break;
    }
}
int Pop(int i) {
    if (i < 0 || i > 1) {
        printf("illegal input");
        exit(0);
    }
    switch (i) {
        case 0:
            if (s.top[0] == -1) {
                printf("stack empty");
                return -1;
            } else {
                return s.data[s.top[0]--];
            }
            break;
        case 1:
            if (s.top[1] == MaxSize) {
                printf("stack empty");
                return -1;
            } else {
                return s.data[s.top[1]++];
            }
            break;
    }
    return 0;
}
