#include "function.h"

void DeleteMin(LinkList &L);
int main() {
    LinkList L;
    list_tail_insert(L);
    print_list(L);
    DeleteMin(L);
    print_list(L);
    return 0;
}
void DeleteMin(LinkList &L) {
    LinkList p = L->next, pre = L, min = L->next, minPre = L;
    while (p != nullptr) {
        if (p->data < min->data) {
            min = p;
            p = p->next;
            minPre = pre;
            pre = pre->next;
        } else {
            p = p->next;
            pre = pre->next;
        }
    }
    minPre->next = min->next;
    free(min);
}
