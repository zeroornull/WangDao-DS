#include "function.h"
#include <iostream>
#include <vector>
using namespace std;
vector<int> listToArray(LinkList head);
void quickSort(vector<int> &nums, int left, int right);
void Sort(LinkList &L);
LinkList arrayToList(vector<int> arr, int n);
int main() {
    LinkList L;
    list_tail_insert(L);
    print_list(L);
    // 链表转数组
    vector<int> array = listToArray(L);
    quickSort(array, 0, array.size() - 1);
    L = arrayToList(array, array.size());
    //    Sort(L);
    print_list(L);
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
/**
 * 插排
 * @param L
 */
void Sort(LinkList &L) {
    LinkList p = L->next, pre;
    LinkList r = p->next;
    p->next = nullptr;
    p = r;
    while (p != nullptr) {
        r = p->next;
        pre = L;
        while (pre->next != nullptr && pre->next->data < p->data) {
            pre = pre->next;
        }
        p->next = pre->next;
        pre->next = p;
        p = r;
    }
}
vector<int> listToArray(LinkList head) {
    vector<int> array;
    LinkList node = head;

    // 将链表中的元素存储到数组中
    while (node != NULL) {
        array.push_back(node->data);
        node = node->next;
    }

    return array;
}
void quickSort(vector<int> &nums, int left, int right) {
    if (left >= right) {
        return;
    }

    int pivot = nums[left];
    int i = left + 1;
    int j = right;

    while (i <= j) {
        while (i <= j && nums[i] < pivot) {
            i++;
        }
        while (i <= j && nums[j] > pivot) {
            j--;
        }
        if (i <= j) {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }

    swap(nums[left], nums[j]);

    quickSort(nums, left, j - 1);
    quickSort(nums, j + 1, right);
}
