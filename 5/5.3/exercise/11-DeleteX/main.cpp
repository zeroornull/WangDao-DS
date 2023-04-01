#include "bi_tree.h"
#include <stack>
void Search(BiTree &root, int x);
void DeleteXTree(BiTree &root);
int main() {
    vector<int> array1 = {1, 2, 3, 4, 5, 6};
    BiTree root = sortedArrayToBST(array1);
    levelOrder(root);
    cout << endl;
    int x = 5;
    Search(root, x);
    levelOrder(root);
    cout << endl;
    return 0;
}
void Search(BiTree &root, int x) {
    queue<BiTree> queue;
    BiTree p;
    if (root) {
        if (root->data == x) {
            DeleteXTree(root);
            return;
        }
        queue.push(root);
        while (!queue.empty()) {
            p = queue.front();
            queue.pop();
            if (p->lchild) {
                if (p->lchild->data == x) {
                    DeleteXTree(p->lchild);
                    p->lchild = nullptr;
                } else {
                    queue.push(p->lchild);
                }
                if (p->rchild->data == x) {
                    DeleteXTree(p->rchild);
                    p->rchild = nullptr;
                } else {
                    queue.push(p->rchild);
                }
            }
        }
    }
}
void DeleteXTree(BiTree &root) {
    if (root) {
        DeleteXTree(root->lchild);
        DeleteXTree(root->rchild);
        free(root);
    }
}
