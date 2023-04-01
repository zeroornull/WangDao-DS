#include "bi_tree.h"

void swapLR(BiTree root);
int main() {
    vector<int> array1 = {1, 2, 3, 4, 5, 6};
    BiTree root = sortedArrayToBST(array1);
    levelOrder(root);
    cout<<endl;
    swapLR(root);
    levelOrder(root);
    cout<<endl;
    return 0;
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
