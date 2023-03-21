#include "function.h"

void Connect(CNode &L1, CNode L2);
CNode find_addr(CNode L1, CNode L2);
int listlen(CNode L);
int main() {
    vector<char> array1 = {'l', 'o', 'a', 'd'};
    vector<char> array2 = {'b', 'e'};
    vector<char> array3 = {'i','n','g'};
    CNode L1 = arrayToCNodeList(array1, array1.size());
    CNode L2 = arrayToCNodeList(array2, array2.size());
    CNode L3 = arrayToCNodeList_without_head(array3, array3.size());
    Connect(L1,L3);
    Connect(L2,L3);
    print_list(L1);
    print_list(L2);
    CNode p = find_addr(L1,L2);
    printf("%c",p->data);
    return 0;
}
CNode find_addr(CNode L1, CNode L2) {
    int m,n;
    CNode p,q;
    m = listlen(L1);
    n = listlen(L2);
    for(p=L1;m>n;m--){
        p = p->next;
    }
    for(q=L2;m<n;n--){
        q =q->next;
    }
    while (p->next!= nullptr&&p->next!=q->next){
        p = p->next;
        q = q->next;
    }
    return p->next;
}
int listlen(CNode L) {
    int len = 0;
    while (L->next!= nullptr){
        len++;
        L = L->next;
    }
    return len;
}
void Connect(CNode &L1, CNode L2) {
    CNode p =L1;
    while (p->next!= nullptr){
        p = p->next;
    }
    p->next = L2;
}
