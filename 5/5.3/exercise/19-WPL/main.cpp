#include "bi_tree.h"

int WPL(BiTree root, int deep);
int wpl_LevelOrder(BiTree root);
int main() {
    vector<int> array1 = {1, 2, 3, 4, 5, 6};
    BiTree root = sortedArrayToBST(array1);
    int result = WPL(root, 0);
    int result1 = wpl_LevelOrder(root);
    cout << "result = " << result << endl;
    return 0;
}
// wait to impl
int wpl_LevelOrder(BiTree root) {
    return 0;
}
int WPL(BiTree root, int deep) {
    static int wpl = 0;
    if (root->lchild == nullptr && root->rchild == 0) {
        wpl += deep * root->data;
    }
    if (root->lchild != nullptr) {
        WPL(root->lchild, deep + 1);
    }
    if (root->rchild != nullptr) {
        WPL(root->rchild, deep + 1);
    }
    return wpl;
}
