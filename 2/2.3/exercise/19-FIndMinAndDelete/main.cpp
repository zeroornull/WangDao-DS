#include "function.h"

void PrintMinAndDelete(LinkList &L);
int main() {
    vector<int> array1 = {1, 2, 3, 4, 5};
    LinkList L1 = arrayToCircleList(array1, array1.size());
    PrintMinAndDelete(L1);
    return 0;
}
void PrintMinAndDelete(LinkList &L) {
    LinkList p, minp, pre, minpre;
    while (L->next != L) {
        p = L->next;
        pre = L;
        minp = p;
        minpre = pre;
        while (p != L) {
            if (p->data < minp->data) {
                minp = p;
                minpre = pre;
            } else {
                pre = p;
                p = p->next;
            }
        }
        printf("%2d", minp->data);
        minpre->next = minp->next;
        free(minp);
    }
    free(L);
}
