#include "function.h"
#include <iostream>
#include <vector>
using namespace std;
LinkList arrayToList(vector<int> arr, int n);
LinkList Search_1st_Common(LinkList L1, LinkList L2);
int Length(LinkList L);
/**
 * 暂时没想到怎么复现公共节点
 * @return
 */
int main() {
//    vector<int> array1 = {1, 2, 3, 4, 5};
//    vector<int> array2 = {5, 6, 7, 8, 9};
//    LinkList L1 = arrayToList(array1, array1.size());
//    LinkList L2 = arrayToList(array2, array2.size());
//    LinkList L3 = Search_1st_Common(L1, L2);
//    print_list(L3);
    return 0;
}
LinkList arrayToList(vector<int> arr, int n) {
    LinkList head = (LinkList) malloc(sizeof(LNode));
    head->data = arr[0];
    head->next = NULL;

    LinkList cur = head;
    for (int i = 1; i < n; i++) {
        LinkList node = (LinkList) malloc(sizeof(LNode));
        node->data = arr[i];
        node->next = NULL;

        cur->next = node;
        cur = node;
    }

    return head;
}
LinkList Search_1st_Common(LinkList L1, LinkList L2) {
    int len1 = Length(L1);
    int len2 = Length(L2);
    LinkList longList, shortList;
    int dist;
    if (len1 > len2) {
        longList = L1->next;
        shortList = L2->next;
        dist = len1 - len2;
    } else {
        longList = L2->next;
        shortList = L1->next;
        dist = len2 - len1;
    }
    while (dist--) {
        longList = longList->next;
    }
    while (longList != nullptr) {
        if (longList == shortList) {
            return longList;
        } else {
            longList = longList->next;
            shortList = shortList->next;
        }
    }
    return nullptr;
}
int Length(LinkList L) {
    LinkList q = L;
    int length = 0;
    while (q != nullptr) {
        q = q->next;
        length++;
    }
    return length;
}
