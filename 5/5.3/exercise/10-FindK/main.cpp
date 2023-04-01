#include "bi_tree.h"

int findK(BiTree root, int k);
void preOrderWithQueue(BiTree root, queue<BiTree> &queue);
int main() {
    vector<int> array1 = {1, 2, 3, 4, 5, 6};
    BiTree root = sortedArrayToBST(array1);
    preorderTraversal(root);
    cout << endl;
    int k = 3;
    int result = findK(root, k);
    cout << result << endl;
    return 0;
}
int findK(BiTree root, int k) {
    queue<BiTree> queue;
    preOrderWithQueue(root, queue);
    for (int i = 0; i < k-1; ++i) {
        queue.pop();
    }
    return queue.front()->data;
}
void preOrderWithQueue(BiTree root, queue<BiTree> &queue) {
    if (root == nullptr) {
        return;
    }
    queue.push(root);
    preOrderWithQueue(root->lchild, queue);
    preOrderWithQueue(root->rchild, queue);
}
