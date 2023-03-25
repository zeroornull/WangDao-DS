#include "function.h"

void IsSymmetry(LinkList L, int length);
int main() {
    vector<int> array1 = {1, 2, 3, 2, 1};
    LinkList L1 = arrayToList(array1, array1.size());
    IsSymmetry(L1, array1.size());
    return 0;
}
void IsSymmetry(LinkList L, int length) {
    LinkList p = L->next;
    int i;
    char s[length / 2];
    for (i = 0; i < length / 2; i++) {
        s[i] = p->data;
        p = p->next;
    }
    i--;
    if (i % 2 == 1) {
        p = p->next;
    }
    while (p != nullptr && s[i] == p->data) {
        i--;
        p = p->next;
    }
    if (i == -1) {
        ::printf("is");
    } else {
        ::printf("not");
    }
}
