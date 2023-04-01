#include "bi_tree.h"
/*#include <stack>*/
/*#define MaxSize 100
typedef struct {
    BiTree t;
    int tag;
} stack;*/
void PrintXParent(BiTree bt, int x);
// 无法复现 暂搁置
int main() {
    vector<int> array1 = {1, 2, 3, 4, 5, 6};
    BiTree root = sortedArrayToBST(array1);
    levelOrder(root);
    cout << endl;
    int x = 4;
    PrintXParent(root, x);
    return 0;
}

/*void PrintXParent(BiTree root, int x) {
    stack s[MaxSize];
    int top = 0;
    BiTree p = root;
    while (p != nullptr || top > 0) {
        while (p != nullptr && p->data != x) {
            s[++top].t = p;
            s[++top].tag = 0;
            p = p->lchild;
        }
        if (p != nullptr && p->data == x) {
            printf("value is:\n");
            for (int i = 1; i <= top; ++i) {
                printf("%d", s[i].t->data);
            }
            exit(1);
        }
        while (top != 0 && s[top].tag == 1) {
            top--;
        }
        if (top != 0) {
            s[top].tag = 1;
            p = s[top].t->rchild;
        }
    }
}*/

