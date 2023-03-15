#include "function.h"

int FindMainElem(SqList l);
int main() {
    SqList L = {0, 5, 5, 3, 5, 5, 5, 7};
    L.length = 8;
    int mainElem = FindMainElem(L);
    printf("mainElem = %d", mainElem);
    return 0;
}
int FindMainElem(SqList l) {
    int mainElem = l.data[0], count = 1;
    for (int i = 0; i < l.length; ++i) {
        if (mainElem != l.data[i]) {
            if (count > 0) {
                count--;
            } else {
                mainElem = l.data[i];
                count = 1;
            }
        } else {
            count++;
        }
    }
    if (count > 0) {
        for (int i = count = 0; i < l.length; ++i) {
            if (l.data[i] == mainElem) {
                count++;
            }
        }
    }
    if (count > l.length / 2) {
        return mainElem;
    } else {
        return -1;
    }
}
