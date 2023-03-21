#include "function.h"

bool IsContinousSubseq(LinkList L1, LinkList L2);
int main() {
    vector<int> array1 = {1, 2, 3, 4, 5};
    vector<int> array2 = {4, 5};
    LinkList L1 = arrayToList(array1, array1.size());
    LinkList L2 = arrayToList(array2, array2.size());
    bool result = IsContinousSubseq(L1, L2);
    if (result) {
        printf("is subseq");
    } else {
        printf("isn't subseq");
    }
    return 0;
}
bool IsContinousSubseq(LinkList L1, LinkList L2) {
    LinkList p = L1->next, q = L2->next, r = p;
    while (p && q) {
        if (p->data == q->data) {
            p = p->next;
            q = q->next;
        } else {
            r = r->next;
            p = r;
            q = L2->next;
        }
    }
    if (q == nullptr) {
        return true;
    }
    return false;
}
