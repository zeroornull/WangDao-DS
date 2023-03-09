#include "function.h"

void SwapSqListPosition(SqList &l, int m, int n);
void swap(int &i, int &j);
void Reverse(SqList &l, int left, int right);
int main() {
    SqList L = InitSqList();
    PrintList(L);
    int m = 2;
    int n = 3;
    SwapSqListPosition(L, m, n);
    PrintList(L);
    return 0;
}
void SwapSqListPosition(SqList &l, int m, int n) {
    Reverse(l, 0, m + n - 1);
    Reverse(l, 0, n - 1);
    Reverse(l, n, n + m - 1);
}
void Reverse(SqList &l, int left, int right) {
    if (left >= right || right >= l.length) {
        return;
    }
    int mid = (left + right) / 2;
    for (int i = 0; i <= mid - left; ++i) {
        swap(l.data[left + i], l.data[right - i]);
    }
}

void swap(int &i, int &j) {
    int tmp;
    tmp = j;
    j = i;
    i = tmp;
}
