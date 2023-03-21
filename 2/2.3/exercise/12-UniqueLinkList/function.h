//
// Created by xxp on 2023/3/16.
//

#ifndef INC_1_DELETEELEM_FUNCTION_H
#define INC_1_DELETEELEM_FUNCTION_H
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;
typedef int ElemType;
typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;
LinkList list_head_insert(LinkList &L);
LinkList arrayToList(vector<int> arr, int n);
/**
 * 不带头节点的单链表创建
 * @param L
 * @return
 */
LinkList list_head_insert_without_head(LinkList &L);
LinkList list_tail_insert(LNode *&L);
LNode *GetElem(LinkList L, int pos);
LNode *LocateElem(LinkList L, ElemType search_value);
void print_list(LinkList L);
/**
 * 不带头节点的单链表print
 * @param L
 */
void print_list_without_head(LinkList L);

LinkList list_head_insert(LinkList &L) {
    L = (LinkList) malloc(sizeof(LNode));//申请头节点空间，指向头节点
    L->next = nullptr;
    LNode *s;
    ElemType e;
    scanf("%d", &e);
    while (e != 9999) {
        s = (LinkList) malloc(sizeof(LNode));
        s->data = e;
        s->next = L->next;
        L->next = s;
        scanf("%d", &e);
    }
    return L;
}
LinkList list_head_insert_without_head(LinkList &L) {
    ElemType e = 0;
    scanf("%d", &e);
    while (e != 9999) {
        LNode *p;
        p = (LNode *) malloc(sizeof(LNode));
        p->data = e;
        p->next = L;
        L = p;
        scanf("%d", &e);
    }
}
void print_list(LinkList L) {
    L = L->next;
    while (L != NULL)//NULL 是为了代表一张空的藏宝图
    {
        printf("%3d", L->data);//打印当前结点数据
        L = L->next;           //指向下一个结点
    }
    printf("\n");
}
void print_list_without_head(LinkList L) {
    while (L != NULL)//NULL 是为了代表一张空的藏宝图
    {
        printf("%3d", L->data);//打印当前结点数据
        L = L->next;           //指向下一个结点
    }
    printf("\n");
}
LinkList list_tail_insert(LNode *&L) {
    L = (LinkList) malloc(sizeof(LNode));//申请头节点空间，指向头节点
    LNode *s, *r = L;
    L->next = nullptr;
    ElemType e;
    scanf("%d", &e);
    while (e != 9999) {
        s = (LNode *) malloc(sizeof(LNode));
        s->data = e;
        r->next = s;
        r = s;
        scanf("%d", &e);
    }
    r->next = nullptr;//尾结点的next 指针赋值为NULL
    return L;
}
/**
 * 按值查找，返回NULL 代表没找到
 * @param L
 * @param search_value
 * @return
 */
LNode *LocateElem(LinkList L, ElemType search_value) {
    LNode *p = L->next;
    while (p != nullptr && p->data != search_value) {
        p = p->next;
    }
    return p;
}
LNode *GetElem(LinkList L, int pos) {
    if (pos < 0) {
        return nullptr;
    }
    int startPos = 0;
    while (L && startPos < pos) {
        L = L->next;
        startPos++;
    }
    return L;
}
LinkList arrayToList(vector<int> arr, int n) {
    LinkList head = (LinkList) malloc(sizeof(LNode));
    head->next = NULL;

    LinkList cur = head;
    for (int i = 0; i < n; i++) {
        LinkList node = (LinkList) malloc(sizeof(LNode));
        node->data = arr[i];
        node->next = NULL;

        cur->next = node;
        cur = node;
    }

    return head;
}

#endif//INC_1_DELETEELEM_FUNCTION_H
