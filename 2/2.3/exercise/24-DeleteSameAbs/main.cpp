#include "function.h"
#include <cstring>
#define MaxSize 500
void DeleteSameAbs(LinkList &L);
int main() {
    vector<int> array1 = {1, -1, 3, -3, 5};
    LinkList L1 = arrayToList(array1, array1.size());
    DeleteSameAbs(L1);
    print_list(L1);
    return 0;
}
void DeleteSameAbs(LinkList &L) {
    LinkList p = L->next, pre = L, q;
    int a[MaxSize];
    memset(a, 0, sizeof(a));
    while (p != nullptr) {
        if (a[abs(p->data)] == 0) {
            a[abs(p->data)] = 1;
            pre = p;
            p = p->next;
        } else {
            q = p;
            p = p->next;
            pre->next = p;
            free(q);
        }
    }
}
