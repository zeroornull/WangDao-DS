#include "function.h"

bool IsLoop(LinkList L);
int main() {
    vector<int> array1 = {1, 2, 3, 4, 5};
    vector<int> array2 = {1, 2, 3, 4, 5};
    LinkList L1 = arrayToCircleList(array1, array1.size());
    LinkList L2 = arrayToList(array1, array1.size());
    bool result = IsLoop(L1);
    if (result){
        printf("Is Loop\n");
    } else{
        printf("No Loop\n");
    }
    result = IsLoop(L2);
    if (result){
        printf("Is Loop\n");
    } else{
        printf("No Loop\n");
    }
    return 0;
}
bool IsLoop(LinkList L) {
    LinkList fast = L->next,slow = fast;
    while (fast!= nullptr&&fast->next!= nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if (slow==fast){
            return true;
        }
    }
    return false;
}
