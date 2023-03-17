#include "function.h"

void ReversePrint(LinkList L);
int main() {
    LinkList L;
    list_tail_insert(L);
    print_list(L);
    if (L->next!= nullptr){
        ReversePrint(L->next);
    }
    return 0;
}
void ReversePrint(LinkList L) {
    if (L->next != nullptr) {
        ReversePrint(L->next);
    }
    if (L != nullptr) {
        printf("%3d", L->data);
    }
}

