#include "function.h"

void Link(LinkList L1, LinkList L2);
int main() {
    vector<int> array1 = {1, 2, 3, 2, 1};
    vector<int> array2 = {1, 2, 3, 4, 5};
    LinkList L1 = arrayToCircleList(array1, array1.size());
    LinkList L2 = arrayToCircleList(array2, array2.size());
    Link(L1, L2);
    print_circle_list(L1);
    return 0;
}
void Link(LinkList L1, LinkList L2) {
    LinkList p = L1->next, q = L2->next;
    while (p->next != L1) {
        p = p->next;
    }
    p->next = q;
    while (q->next != L2) {
        q = q->next;
    }
    q->next = L1;
}
