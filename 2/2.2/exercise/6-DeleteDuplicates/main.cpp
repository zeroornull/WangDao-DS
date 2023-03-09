#include "function.h"

bool DeleteDuplicates(SqList &L);
int main() {
    SqList L;
    L.data[0] = 1;
    L.data[1] = 1;
    L.data[2] = 2;
    L.data[3] = 2;
    L.data[4] = 3;
    L.length = 5;
    PrintList(L);
    bool ret = DeleteDuplicates(L);
    PrintList(L);
    return 0;
}
//去重
bool DeleteDuplicates(SqList &L) {
    if (L.length == 0) {
        return false;
    }
    int i, j;
    for (i = 0, j = 1; j < L.length; ++j) {
        if (L.data[i] != L.data[j]) {
            L.data[++i] = L.data[j];
        }
    }
    L.length = i + 1;
    return true;
}
