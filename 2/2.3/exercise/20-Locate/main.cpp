#include "function.h"

void Locate(DlinkList &L, int value);
int main() {
    vector<int> array1 = {1, 2, 3, 4, 5};
    DlinkList L1 = arrayToDlinkList(array1, array1.size());
    print_list(L1);
    Locate(L1, 5);
    print_list(L1);
    return 0;
}
void Locate(DlinkList &L, ElemType value) {
    DlinkList p = L->next, q;
    while (p && p->data != value) {
        p = p->next;
    }
    if (!p) {
        return;
    } else {
        p->freq++;
        if (p->prior == L || p->prior->freq > p->freq) {
            return;
        }
        if (p->next != nullptr) {
            p->next->prior = p->prior;
        }
        p->prior->next = p->next;
        q = p->prior;
        while (q != L && q->freq <= p->freq) {
            q = q->prior;
        }
        p->next = q->next;
        if (q->next != nullptr) {
            q->next->prior = p;
        }
        q->prior = q;
        q->next = p;
    }
}
