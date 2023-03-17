#include "function.h"

int main() {
    LinkList L;
    list_tail_insert(L);
    print_list(L);
    DeleteBetween(L);
    print_list(L);
    return 0;
}
