#include "bi_tree.h"

int DsonNodes(BiTree root);
int main() {
    vector<int> array1 = {1, 2, 3, 4, 5, 6};
    BiTree root = sortedArrayToBST(array1);
    int result = DsonNodes(root);
    cout << result << endl;
    levelOrder(root);
    return 0;
}
int DsonNodes(BiTree root) {
    if (root == nullptr) {
        return 0;
    } else if (root->lchild != nullptr && root->rchild != nullptr) {
        return DsonNodes(root->lchild) + DsonNodes(root->rchild) + 1;
    } else {
        return DsonNodes(root->lchild) + DsonNodes(root->rchild);
    }
    return 0;
}
