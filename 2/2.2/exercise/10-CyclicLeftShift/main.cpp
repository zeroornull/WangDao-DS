#include "function.h"

void Reverse(SqList &l, int from, int to);
void CyclicLeftShift(SqList &l, int value);
void swap(int &a, int &b) {
    int temp = b;
    b = a;
    a = temp;
}
int main() {
    SqList L = InitSqList();
    PrintList(L);
    int value = 2;
    CyclicLeftShift(L, value);
    PrintList(L);
    return 0;
}
void CyclicLeftShift(SqList &l, int value) {
    Reverse(l, 0, value - 1);
    Reverse(l, value, l.length - 1);
    Reverse(l, 0, l.length - 1);
}
void Reverse(SqList &l, int from, int to) {
    for (int i = 0; i < (to - from + 1) / 2; ++i) {
        swap(l.data[from + i], l.data[to - i]);
    }
}
