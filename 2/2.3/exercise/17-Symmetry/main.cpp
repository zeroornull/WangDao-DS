#include "function.h"

bool Symmetry(LineList L);
int main() {
    vector<int> array1 = {1, 2, 3, 2, 1};
    vector<int> array2 = {1, 2, 3, 4, 5};
    LineList L1 = arrayToLineList(array1, array1.size());
    LineList L2 = arrayToLineList(array2, array2.size());
    bool result = Symmetry(L1);
    if (result) {
        printf("true");
    } else {
        printf("false");
    }
    print_list(L1);
    return 0;
}
bool Symmetry(LineList L) {
    LineList p = L->next, q = L->prior;
    while (p != q && p->next != q) {
        if (p->data == q->data) {
            p = p->next;
            q = q->prior;
        } else {
            return false;
        }
    }
    return true;
}
