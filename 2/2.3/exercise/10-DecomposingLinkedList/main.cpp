#include "function.h"

LinkList breakDownList(LinkList &L1);
int main() {
    vector<int> array1 = {1, 2, 3, 4, 5};
    LinkList L1 = arrayToList(array1, array1.size());
    LinkList L2 = breakDownList(L1);
    print_list(L1);
    print_list(L2);
    return 0;
}
LinkList breakDownList(LinkList &L1) {
    LinkList L2 = (LinkList) malloc(sizeof(LinkList));
    L2->next = nullptr;
    LinkList p = L1->next, r1 = L1, r2 = L2;
    r1->next = nullptr;
    while (p != nullptr) {
        r1->next = p;
        r1 = p;
        p = p->next;
        if (p != nullptr) {
            r2->next = p;
            r2 = p;
            p = p->next;
        }
    }
    r1->next = nullptr;
    r2->next = nullptr;
    return L2;
}
