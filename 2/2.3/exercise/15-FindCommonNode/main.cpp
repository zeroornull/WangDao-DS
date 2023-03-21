#include "function.h"

void FindCommonNode(LinkList &L1, LinkList &L2);
void Union(LinkList &la, LinkList &lb);
int main() {
    vector<int> array1 = {1, 2, 3, 4, 5};
    vector<int> array2 = {4, 5, 6, 7};
    LinkList L1 = arrayToList(array1, array1.size());
    LinkList L2 = arrayToList(array2, array2.size());
    //    FindCommonNode(L1, L2);
    Union(L1, L2);
    print_list(L1);
    return 0;
}
void Union(LinkList &la, LinkList &lb) {
    LinkList pa = la->next, pb = lb->next, pc = la, u;
    while (pa && pb) {
        if (pa->data == pb->data) {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
            u = pb;
            pb = pb->next;
            free(u);
        } else if (pa->data < pb->data) {
            u = pa;
            pa = pa->next;
            free(u);
        } else {
            u = pb;
            pb = pb->next;
            free(u);
        }
    }
    if (pa) {
        pa = pb;
    }
    while (pa) {
        u = pa;
        pa = pa->next;
        free(u);
    }
    pc->next = nullptr;
    free(lb);
}
void FindCommonNode(LinkList &L1, LinkList &L2) {
    LinkList r1 = L1, p = L1->next, q = L2->next, r;
    r1->next = nullptr;
    while (p != nullptr && q != nullptr) {
        if (p->data == q->data) {
            r = p->next;
            r1->next = p;
            r1 = p;
            p->next = nullptr;
            p = r;
            q = q->next;
        } else if (p->data < q->data) {
            p = p->next;
        } else {
            q = q->next;
        }
    }
}
