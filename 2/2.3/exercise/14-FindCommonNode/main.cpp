#include "function.h"

LinkList FindCommonNode(LinkList L1, LinkList L2);
int main() {
    vector<int> array1 = {1, 2, 3, 4, 5};
    vector<int> array2 = {4, 5, 6, 7};
    LinkList L1 = arrayToList(array1, array1.size());
    LinkList L2 = arrayToList(array2, array2.size());
    LinkList L3 = FindCommonNode(L1, L2);
    print_list(L3);
    return 0;
}
LinkList FindCommonNode(LinkList L1, LinkList L2) {
    LinkList L3 = (LinkList) malloc(sizeof(LinkList));
    LinkList p = L1->next, q = L2->next, r = L3;
    while (p != nullptr && q != nullptr) {
        if (p->data == q->data) {
            LinkList node = (LinkList) malloc(sizeof(LinkList));
            node->data = p->data;
            r->next = node;
            r = node;
            p = p->next;
            q = q->next;
        } else if (p->data < q->data) {
            p = p->next;
        } else {
            q = q->next;
        }
    }
    r->next = nullptr;
    return L3;
}
