#include "function.h"

void Inversion(LinkList L);
int main() {
    LinkList L;
    list_tail_insert(L);
    print_list(L);
    Inversion(L);
    print_list(L);
    return 0;
}
void Inversion(LinkList L) {
    LinkList pre,p = L->next,r = p->next;
    p->next = nullptr;
    while (r!= nullptr){
        pre = p;
        p = r;
        r = r->next;
        p->next = pre;
    }
    L->next = p;
}
