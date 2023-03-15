#include "function.h"

int FindMidElem(SqList l1, SqList l2);
int FindMidElem1(SqList l1, SqList l2);
int main() {
    SqList L1 = InitSqList();
    SqList L2;
    L2.data[0] = 2;
    L2.data[1] = 4;
    L2.data[2] = 6;
    L2.data[3] = 8;
    L2.data[4] = 20;
    L2.length = 5;
    //    int mid = FindMidElem(L1, L2);
    int mid = FindMidElem1(L1, L2);
    printf("mid=%d", mid);
    return 0;
}
int FindMidElem1(SqList l1, SqList l2) {
    int n = l1.length;
    int s1 = 0, d1 = n - 1, m1, s2 = 0, d2 = n - 1, m2;
    while (s1 != d1 || s2 != d2) {
        m1 = (s1 + d1) / 2;
        m2 = (s2 + d2) / 2;
        if (l1.data[m1] == l2.data[m2]) {
            return l1.data[m1];
        }
        if (l1.data[m1] < l2.data[m2]) {
            if ((s1 + d1) % 2 == 0) {
                s1 = m1;
                d2 = m2;
            } else {
                s1 = m1 + 1;
                d2 = m2;
            }
        } else {
            if ((s2 + d2) % 2 == 0) {
                d1 = m1;
                s2 = m2;
            } else {
                d1 = m1;
                s2 = m2 + 1;
            }
        }
    }
    return l1.data[s1] < l2.data[s2] ? l1.data[s1] : l2.data[s2];
}
int FindMidElem(SqList l1, SqList l2) {
    int count = 0;
    int mid;
    for (int i = 0, j = 0; i < l1.length, j < l2.length;) {

        if (count != l1.length) {
            if (l1.data[i] <= l2.data[j]) {
                mid = l1.data[i];
                i++;
            } else {
                mid = l2.data[j];
                j++;
            }
            count++;
        } else {
            break;
        }
    }
    return mid;
}
