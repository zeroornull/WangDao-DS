#include "function.h"

// 非有序

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
    int k = 0;
    for (int i = 0; i < l.length; ++i) {
        if (l.data[i] >= s && l.data[i] <= t) {
            k += 1;
        } else {
            l.data[i - k] = l.data[i];
        }
    }
    l.length = l.length - k;
    return true;
}
