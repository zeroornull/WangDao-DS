#include "function.h"

void DelElem(LinkList &L, ElemType x);
void DelElem2(LinkList &L, ElemType x);
int main() {
    LinkList L;
    list_tail_insert(L);
    print_list(L);
    ElemType x = 1;
//    DelElem(L, x);
    DelElem2(L, x);
    print_list(L);
    return 0;
}
void DelElem2(LinkList &L, ElemType x) {
    LinkList p = L->next,r = L,q;
    while (p!= nullptr){
        if (p->data != x){
            r->next = p;
            r = p;
            p = p->next;
        } else{
            q = p;
            p = p->next;
            free(q);
        }
    }
    r->next = nullptr;
}
void DelElem(LinkList &L, ElemType x) {
    LinkList p = L->next,pre = L,q;
    while (p!= nullptr){
        if (p->data == x){
            q = p;
            p = p->next;
            pre->next = p;
            free(q);
        } else{
            pre = p;
            p = p->next;
        }
    }
}
