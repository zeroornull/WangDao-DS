#include "bi_tree.h"

bool IsComplete(BiTree root);
void swapLR(BiTree root);
// 存疑
int main() {
    vector<int> array1 = {1, 2, 3, 4, 5, 6};
    BiTree root = sortedArrayToBST(array1);
    bool result = IsComplete(root);
    if (result) {
        cout << "it is" << endl;
    } else {
        cout << "it is not" << endl;
    }
    levelOrder(root);
    cout << endl;
    swapLR(root);
    levelOrder(root);
    cout << endl;
    result = IsComplete(root);
    if (result) {
        cout << "it is" << endl;
    } else {
        cout << "it is not" << endl;
    }
    return 0;
}
bool IsComplete(BiTree root) {
    queue<BiTree> queue;
    BiTree p;
    queue.push(root);
    while (!queue.empty()) {
        p = queue.front();
        queue.pop();
        if (p) {
            queue.push(p->lchild);
            queue.push(p->rchild);
        } else {
            while (!queue.empty()) {
                p = queue.front();
                if (p) {
                    return false;
                }
            }
        }
    }
    return true;
}
void swapLR(BiTree root) {
    if (root) {
        swapLR(root->lchild);
        swapLR(root->rchild);
        BiTree temp = root->lchild;
        root->lchild = root->rchild;
        root->rchild = temp;
    }
}
