#include "function.h"

void UniqueLinkList(LinkList &L);
int main() {
    vector<int> array1 = {1, 2, 2, 4, 4, 6};
    LinkList L1 = arrayToList(array1, array1.size());
    UniqueLinkList(L1);
    print_list(L1);
    return 0;
}
void UniqueLinkList(LinkList &L) {
    LinkList p = L->next, pnext = p->next;
    while (pnext != nullptr) {
        if (p->data == pnext->data) {
            p->next = pnext->next;
            free(pnext);
            pnext = p->next;
        } else {
            p = pnext;
            pnext = pnext->next;
        }
    }
}
