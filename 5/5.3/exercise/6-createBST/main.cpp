#include "bi_tree.h"

BiTree PreInCreat(vector<int> A, vector<int> B, int l1, int h1, int l2, int h2);
int main() {
    vector<int> array1 = {3, 1, 2, 5, 4, 6};
    vector<int> array2 = {1, 2, 3, 4, 5, 6};

    BiTree root = sortedArrayToBST(array1);
    levelOrder(root);
    cout << endl;
    BiTree root2 = PreInCreat(array1, array2, 0, array1.size() - 1, 0, array2.size() - 1);
    levelOrder(root);
    return 0;
}
BiTree PreInCreat(vector<int> A, vector<int> B, int l1, int h1, int l2, int h2) {
    auto root = new BiTNode(A[l1]);
    int i,llen,rlen;
    for(i=l2;B[i]!=root->data;i++);
    llen = i-l2;
    rlen = h2-i;
    if (llen){
        root->lchild = PreInCreat(A,B,l1+1,l1+llen,l2,l2+llen-1);
    } else{
        root->lchild = nullptr;
    }
    if (rlen){
        root->rchild = PreInCreat(A,B,h1-rlen+1,h1,h2-rlen+1,h2);
    } else{
        root->rchild = nullptr;
    }


    return root;












    //    auto root = new BiTNode(A[l1]);
    //    int i, llen, rlen;
    //    for (i = l2; B[i] != root->data; ++i)
    //        ;
    //    llen = i - l2;
    //    rlen = h2 - i;
    //    if (llen) {
    //        root->lchild = PreInCreat(A, B, l1 + 1, l1 + llen, l2, l2 + llen - 1);
    //    } else {
    //        root->lchild = nullptr;
    //    }
    //    if (rlen) {
    //        root->rchild = PreInCreat(A, B, h1 - rlen + 1, h1, h2 - rlen + 1, h2);
    //    } else {
    //        root->rchild = nullptr;
    //    }
    //    return root;
}
