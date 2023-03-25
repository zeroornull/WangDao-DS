#include <stdio.h>
#define MaxSize 50
typedef int ElemType;
typedef struct {
    ElemType data[MaxSize];
    int front, rear, tag;
} SqQueue;
void InitQueue(SqQueue &Q);
bool isEmpty(SqQueue Q);
bool EnQueue(SqQueue &Q, ElemType x);
bool DeQueue(SqQueue &Q, ElemType &x);
int main() {
    return 0;
}
void InitQueue(SqQueue &Q) {
    Q.rear = Q.front = 0;
    Q.tag = 0;
}
bool isEmpty(SqQueue Q) {
    if (Q.rear == Q.front) {
        return true;
    } else {
        return false;
    }
}
bool EnQueue(SqQueue &Q, ElemType x) {
    if ((Q.rear + 1) % MaxSize == Q.front && Q.tag == 1) {
        return false;
    }
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MaxSize;
    if ((Q.rear + 1) % MaxSize == Q.front) {
        Q.tag = 1;
    }
    return true;
}
bool DeQueue(SqQueue &Q, ElemType &x) {
    if (Q.rear == Q.front && Q.tag == 0) {
        return false;
    }
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    return true;
}
