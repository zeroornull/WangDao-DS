#include "function.h"

void FindElem(SqList &l, ElemType x);
int main() {
    SqList L = InitSqList();
    PrintList(L);
    ElemType x = 3;
    FindElem(L, x);
    PrintList(L);
    return 0;
}
void FindElem(SqList &l, ElemType x) {
    int left = 0, right = l.length - 1, mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if (x == l.data[mid]) {
            break;
        } else if (x > l.data[mid]) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    if (l.data[mid] == x && mid != l.length - 1) {
        ElemType temp = l.data[mid + 1];
        l.data[mid + 1] = l.data[mid];
        l.data[mid] = temp;
    }
    if (left > right) {
        int i;
        for (i = l.length - 1; i > right; --i) {
            l.data[i + 1] = l.data[i];
        }
        l.data[i + 1] = x;
        l.length++;
    }
}
