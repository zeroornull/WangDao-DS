#include "function.h"
bool MergeOrdered(SqList l1, SqList l2, SqList &l3);
int main() {
    SqList L1 = InitSqList();
    SqList L2;
    L2.data[0] = 4;
    L2.data[1] = 5;
    L2.data[2] = 6;
    L2.data[3] = 7;
    L2.length = 4;
    PrintList(L1);
    PrintList(L2);
    SqList L3;
    MergeOrdered(L1, L2, L3);
    PrintList(L3);
    return 0;
}
bool MergeOrdered(SqList l1, SqList l2, SqList &l3) {
    int i = 0, j = 0, k = 0;
    if (l1.length + l2.length > MaxSize) {
        return false;
    }
    while (i < l1.length && j < l2.length) {
        if (l1.data[i] < l2.data[j]) {
            l3.data[k] = l1.data[i];
            i++;
        } else {
            l3.data[k] = l2.data[j];
            j++;
        }
        k++;
    }
    while (i < l1.length) {
        l3.data[k++] = l1.data[i++];
    }
    while (j < l2.length) {
        l3.data[k++] = l2.data[j++];
    }
    l3.length = k;
    return true;
}
