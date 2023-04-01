#include "bi_tree.h"

bool IsSimilar(BiTree root1, BiTree root2);
int main() {
    vector<int> array1 = {1, 2, 3, 4, 5, 6};
    vector<int> array2 = {7, 8, 9, 10, 11, 12, 13};
    BiTree root1 = sortedArrayToBST(array1);
    BiTree root2 = sortedArrayToBST(array2);
    bool result = IsSimilar(root1, root2);
    if (result) {
        cout << " is " << endl;
    } else {
        cout << " is not " << endl;
    }
    return 0;
}
bool IsSimilar(BiTree root1, BiTree root2) {
    bool leftR, rightR;
    if (root1 == nullptr && root2 == nullptr) {
        return true;
    } else if (root1 == nullptr || root2 == nullptr) {
        return false;
    } else {
        leftR = IsSimilar(root1->lchild, root2->lchild);
        rightR = IsSimilar(root1->rchild, root2->rchild);
        return leftR && rightR;
    }
}
