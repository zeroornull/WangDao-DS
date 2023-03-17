#include "function.h"

void DelElem(LinkList &L, ElemType x);
int main() {
    LinkList L = nullptr;
    list_head_insert_without_head(L);
    print_list_without_head(L);
    ElemType x = 1;
    DelElem(L, x);
    print_list_without_head(L);
    return 0;
}
void DelElem(LinkList &L, ElemType x) {
    LinkList p;
    if (L == nullptr) {
        return;
    }
    if (L->data == x) {
        p = L;
        L = L->next;
        free(p);
        DelElem(L, x);
    } else {
        DelElem(L->next, x);
    }
}
