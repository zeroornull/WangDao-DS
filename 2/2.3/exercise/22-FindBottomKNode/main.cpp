#include "function.h"

int FindKNode(LinkList L, int k);
int main() {
    vector<int> array1 = {1, 2, 3, 4, 5};
    LinkList L1 = arrayToList(array1, array1.size());
    int k = 1;
    int result = FindKNode(L1,k);
    return 0;
}
int FindKNode(LinkList L, int k) {
    LinkList p = L->next,q = p;
    while (p!= nullptr){
        if (k>0){
            k--;
            p = p->next;
        } else{
            p = p->next;
            q = q->next;
        }
    }
    if (k<=0){
        printf("%3d",q->data);
        return 1;
    }
    return 0;
}
