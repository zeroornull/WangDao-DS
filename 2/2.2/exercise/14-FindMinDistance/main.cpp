#include "function.h"
#define INT_MAX 0x7fffffff
SqList FindMinDistance(SqList l1, SqList l2, SqList l3);
int FindMinDistance2(SqList l1, SqList l2, SqList l3);
int abs_(int a) {
    if (a < 0) {
        return -a;
    } else {
        return a;
    }
}
bool xls_min(int a, int b, int c) {
    if (a <= b && a <= c) {
        return true;
    } else {
        return false;
    }
}
int main() {
    SqList L1 = {-1, 0, 9};
    L1.length = 3;
    SqList L2 = {-25, -10, 10, 11};
    L2.length = 4;
    SqList L3 = {2, 9, 17, 30, 41};
    L3.length = 5;
    SqList L4 = FindMinDistance(L1, L2, L3);
    PrintList(L4);
    int D_min = FindMinDistance2(L1, L2, L3);
    printf("min_distance=%d", D_min);
    return 0;
}
int FindMinDistance2(SqList l1, SqList l2, SqList l3) {
    SqList L;
    L.length = 3;
    int i = 0, j = 0, k = 0, min = INT_MAX, distance;
    while (i < l1.length && j < l2.length && k < l3.length && min > 0) {
        distance = abs_(l1.data[i] - l2.data[j]) + abs_(l2.data[j] - l3.data[k]) + abs_(l3.data[k] - l1.data[i]);
        if (distance < min) {
            min = distance;
        }
        if (xls_min(l1.data[i], l2.data[j], l3.data[k])) {
            i++;
        } else if (xls_min(l2.data[j], l1.data[i], l3.data[k])) {
            j++;
        } else {
            k++;
        }
    }
    return min;
}
SqList FindMinDistance(SqList l1, SqList l2, SqList l3) {
    SqList L;
    L.length = 3;
    int min = INT_MAX, distance;
    for (int i = 0; i < l1.length; ++i) {
        for (int j = 0; j < l2.length; ++j) {
            for (int k = 0; k < l3.length; ++k) {
                distance = abs_(l1.data[i] - l2.data[j]) + abs_(l2.data[j] - l3.data[k]) + abs_(l3.data[k] - l1.data[i]);
                if (distance < min) {
                    min = distance;
                    L.data[0] = l1.data[i];
                    L.data[1] = l2.data[j];
                    L.data[2] = l3.data[k];
                }
            }
        }
    }
    return L;
}
