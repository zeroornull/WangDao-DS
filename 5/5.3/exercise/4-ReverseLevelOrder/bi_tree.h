//
// Created by xxp on 2023/3/25.
//

#ifndef INC_4_REVERSELEVELORDER_BI_TREE_H
#define INC_4_REVERSELEVELORDER_BI_TREE_H

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef int ElemType;
typedef struct BiTNode {
    ElemType data;
    struct BiTNode *lchild, *rchild;
    BiTNode(int x) : data(x), lchild(nullptr), rchild(nullptr) {}
} BiTNode, *BiTree;

BiTree sortedArrayToBST(vector<int> &nums);
BiTree buildTree(vector<int> &nums, int left, int right);
void inorderTraversal(BiTree root);
void preorderTraversal(BiTree root);
void postorderTraversal(BiTree root);
void levelOrder(BiTree root);

void levelOrder(BiTree root) {
    queue<BiTree> q;
    BiTree p;
    q.push(root);
    while (!q.empty()) {
        p = q.front();
        cout << p->data << " ";
        q.pop();
        if (p->lchild != nullptr) {
            q.push(p->lchild);
        }
        if (p->rchild != nullptr) {
            q.push(p->rchild);
        }
    }
}
BiTree sortedArrayToBST(vector<int> &nums) {
    return buildTree(nums, 0, nums.size() - 1);
}
BiTree buildTree(vector<int> &nums, int left, int right) {
    if (left > right) {
        return nullptr;
    }
    int mid = (left + right) / 2;
    auto root = new BiTNode(nums[mid]);
    root->lchild = buildTree(nums, left, mid - 1);
    root->rchild = buildTree(nums, mid + 1, right);
    return root;
}
void inorderTraversal(BiTree root) {
    if (root == nullptr) {
        return;
    }
    inorderTraversal(root->lchild);
    cout << root->data << " ";
    inorderTraversal(root->rchild);
}
void preorderTraversal(BiTree root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << " ";
    preorderTraversal(root->lchild);
    preorderTraversal(root->rchild);
}
void postorderTraversal(BiTree root) {
    if (root == nullptr) {
        return;
    }
    postorderTraversal(root->lchild);
    postorderTraversal(root->rchild);
    cout << root->data << " ";
}
#endif//INC_4_REVERSELEVELORDER_BI_TREE_H
