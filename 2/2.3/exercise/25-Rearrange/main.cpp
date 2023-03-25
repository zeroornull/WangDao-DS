#include "function.h"

void Rearrange(LinkList &L);
int main() {
    vector<int> array1 = {1, 2, 3, 4, 5};
    LinkList L1 = arrayToList(array1, array1.size());
    Rearrange(L1);
    print_list(L1);
    return 0;
}
/**
 * 1.find mid node
 * 2.reverse second half node
 * 3.take nodes from the front and back ends
 * @param L
 */
void Rearrange(LinkList &L) {
    LinkList p, q, r, s;
    p = q = L;
    while (q->next != nullptr) {
        p = p->next;
        q = q->next;
        if (q->next != nullptr) {
            q = q->next;
        }
    }
    q = p->next;
    p->next = nullptr;
    while (q != nullptr) {
        r = q->next;
        q->next = p->next;
        //使用p的next来标记q_pre
        p->next = q;
        q = r;
    }
    s = L->next;
    q = p->next;
    p->next = nullptr;
    while (q != nullptr) {
        r = q->next;
        q->next = s->next;
        s->next = q;
        s = q->next;
        q = r;
    }
}
