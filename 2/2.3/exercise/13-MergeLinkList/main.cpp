#include "function.h"

void MergeLinkList(LinkList &L1, LinkList &L2);
int main() {
    vector<int> array1 = {1, 2, 3, 4, 5};
    vector<int> array2 = {4, 5, 6, 7};
    LinkList L1 = arrayToList(array1, array1.size());
    LinkList L2 = arrayToList(array2, array2.size());
    MergeLinkList(L1, L2);
    print_list(L1);
    return 0;
}
void MergeLinkList(LinkList &L1, LinkList &L2) {
    LinkList r1 = L1, p = L1->next, q = L2->next, r;
    r1->next = nullptr;
    while (p != nullptr && q != nullptr) {
        if (p->data <= q->data) {
            r = p->next;
            p->next = r1->next;
            r1->next = p;
            p = r;
        } else {
            r = q->next;
            q->next = r1->next;
            r1->next = q;
            q = r;
        }
    }
    //快速判断
    if (p) {
        q = p;
    }
    while (q != nullptr) {
        r = q->next;
        q->next = r1->next;
        r1->next = q;
        q = r;
    }
    free(L2);
}
