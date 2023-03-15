#include "function.h"

int FindMinPositive(SqList l);
int main() {
    //    SqList L = {-5, 3, 2, 3};
    SqList L = {1, 2, 3};
    L.length = 3;
    int minPositive = FindMinPositive(L);
    printf("minPositive=%d", minPositive);
    return 0;
}
int FindMinPositive(SqList l) {
    SqList L2;
    L2.length = l.length;
    for (int i = 0; i < L2.length; ++i) {
        L2.data[i] = 0;
    }
    for (int i = 0; i < l.length; ++i) {
        if (l.data[i] > 0 && l.data[i] < l.length) {
            L2.data[l.data[i] - 1] = 1;
        }
    }
    int j;
    for (j = 0; j < L2.length; ++j) {
        if (L2.data[j] == 0) {
            break;
        }
    }
    return j + 1;
}
