#include "function.h"

void DeleteBetween(LinkList &L, int start, int anEnd);
int main() {
    LinkList L;
    list_tail_insert(L);
    print_list(L);
    int start = 1, end = 3;
    DeleteBetween(L, start, end);
    print_list(L);
    return 0;
}
void DeleteBetween(LinkList &L, int start, int end) {
    LinkList q = L->next, pre = L;
    while (q != nullptr) {
        if (q->data > start && q->data < end) {
            pre->next = q->next;
            free(q);
            q = pre->next;
        } else {
            pre = q;
            q = q->next;
        }
    }
}
