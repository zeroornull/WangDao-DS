#include "function.h"

LinkList DivideList(LinkList &L1);
int main() {
    vector<int> array1 = {1, 2, 3, 4, 5, 6};
    LinkList L1 = arrayToList(array1, array1.size());
    LinkList L2 = DivideList(L1);
    print_list(L1);
    print_list(L2);
    return 0;
}
LinkList DivideList(LinkList &L1) {
    LinkList L2 = (LinkList) malloc(sizeof(LinkList));
    L2->next = nullptr;
    LinkList p = L1->next, q, r1 = L1, r2 = L2;
    r1->next = nullptr;
    while (p != nullptr) {
        r1->next = p;
        r1 = p;
        p = p->next;
        if (p != nullptr) {
            q = p->next;
            p->next = r2->next;
            r2->next = p;
            p = q;
        }
    }
    // r2是头 不需置空
    r1->next = nullptr;
    return L2;
}
