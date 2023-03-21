#include "function.h"

void IncrementalOutput(LinkList &L);
int main() {
    vector<int> array1 = {1, 2, 3, 4, 5};
    LinkList L = arrayToList(array1, array1.size());
    IncrementalOutput(L);
    return 0;
}
void IncrementalOutput(LinkList &L) {
    LinkList q = L->next, pre = L, del;
    while (L->next != nullptr) {
        while (q->next != nullptr) {
            if (q->next->data < q->data) {
                pre = q;
            }
            q = q->next;
        }
        del = pre->next;
        printf("%3d", del->data);
        pre->next = del->next;
        free(del);
    }
    free(L);
}
