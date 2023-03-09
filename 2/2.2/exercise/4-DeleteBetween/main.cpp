#include "function.h"
// 有序
bool DeleteBetween(SqList &l, int s, int t);
int main() {
    SqList L = InitSqList();
    PrintList(L);
    ElemType s = 1;
    ElemType t = 3;
    bool ret = DeleteBetween(L, s, t);
    if (ret) {
        printf("delete success!\n");
    } else {
        printf("delete fail!\n");
    }
    PrintList(L);
    return 0;
}
bool DeleteBetween(SqList &l, ElemType s, ElemType t) {
    if (l.length == 0 || s >= t) {
        return false;
    }
    int i;
    int j;
    for (i = 0; i < l.length && l.data[i] < s; ++i)
        ;
    if (i >= l.length) {
        return false;
    }
    for (j = i; j < l.length && l.data[j] <= t; j++)
        ;
    for (; j < l.length; i++, j++) {
        l.data[i] = l.data[j];
    }
    l.length = i;
    return true;
}
