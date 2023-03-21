//
// Created by xxp on 2023/3/16.
//

#ifndef INC_1_DELETEELEM_FUNCTION_H
#define INC_1_DELETEELEM_FUNCTION_H
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;
// data struct
typedef int ElemType;
typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

typedef struct line {
    struct line *prior;//指向直接前趋
    int data;
    struct line *next;//指向直接后继
} line, *LineList;

typedef struct DlinkNode {
    struct DlinkNode *prior;//指向直接前趋
    int data;
    int freq;
    struct DlinkNode *next;//指向直接后继
} DlinkNode, *DlinkList;
// function
LinkList list_head_insert(LinkList &L);
LinkList arrayToList(vector<int> arr, int n);
DlinkList arrayToDlinkList(vector<int> arr, int n);
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
LineList arrayToLineList(vector<int> arr, int n);
void print_list(LineList L);
// impl
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
LinkList arrayToCircleList(vector<int> arr, int n) {
    LinkList head = (LinkList) malloc(sizeof(LinkList));
    head->next = NULL;

    LinkList cur = head;
    for (int i = 0; i < n; i++) {
        LinkList node = (LinkList) malloc(sizeof(LinkList));
        node->data = arr[i];
        node->next = nullptr;

        cur->next = node;
        cur = node;
    }
    cur->next = head;
    return head;
}


DlinkList arrayToDlinkList(vector<int> arr, int n) {
    DlinkList head = (DlinkList) malloc(sizeof(DlinkList));
    head->prior = nullptr;
    head->next = nullptr;
    DlinkList cur = head;
    for (int i = 0; i < n; i++) {
        DlinkList node = (DlinkList) malloc(sizeof(DlinkList));
        node->data = arr[i];
        node->freq = 0;
        node->next = nullptr;
        node->prior = cur;
        cur->next = node;
        cur = node;
    }
    cur->next = nullptr;
    return head;
}
LineList arrayToLineList(vector<int> arr, int n) {
    LineList head = (LineList) malloc(sizeof(LineList));
    head->next = NULL;
    LineList cur = head;
    for (int i = 0; i < n; i++) {
        LineList node = (LineList) malloc(sizeof(LineList));
        node->data = arr[i];
        node->next = NULL;
        node->prior = cur;
        cur->next = node;
        cur = node;
    }
    cur->next = head;
    head->prior = cur;
    return head;
}
void print_list(LineList L) {
    LineList p = L->next;
    while (p != L) {
        printf("%3d", p->data);//打印当前结点数据
        p = p->next;           //指向下一个结点
    }
    printf("\n");
}
void print_list(DlinkList L) {
    DlinkList p = L->next;
    while (p != nullptr) {
        printf("%3d", p->data);//打印当前结点数据
        p = p->next;           //指向下一个结点
    }
    printf("\n");
}
void print_circle_list(LinkList L) {
    LinkList p = L->next;
    while (p != L) {
        printf("%3d", p->data);//打印当前结点数据
        p = p->next;           //指向下一个结点
    }
    printf("\n");
}

#endif//INC_1_DELETEELEM_FUNCTION_H
