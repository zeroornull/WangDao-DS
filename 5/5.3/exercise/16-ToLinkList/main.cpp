#include "bi_tree.h"


BiTree head, pre = nullptr;
BiTree Inorder(BiTree bt);
void print_list(BiTree L);
int main() {
    vector<int> array1 = {1, 2, 3, 4, 5, 6};
    BiTree root = sortedArrayToBST(array1);
    head = Inorder(root);
    print_list(head);
    return 0;
}
BiTree Inorder(BiTree bt) {
    if (bt) {
        Inorder(bt->lchild);
        if (bt->lchild == nullptr && bt->rchild == nullptr) {
            if (pre == nullptr) {
                head = bt;
                pre = bt;
            } else {
                pre->rchild = bt;
                pre = bt;
            }
        }
        Inorder(bt->rchild);
        pre->rchild = nullptr;
    }
    return head;
}
void print_list(BiTree L) {
    while (L != NULL)//NULL 是为了代表一张空的藏宝图
    {
        printf("%3d", L->data);//打印当前结点数据
        L = L->rchild;         //指向下一个结点
    }
    printf("\n");
}