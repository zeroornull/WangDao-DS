#include "bi_tree.h"
#define MaxSize 100
typedef struct {
    BiTree t;
    int tag;
} stk;
stk s[MaxSize], s1[MaxSize];
BiTree findNode(BiTree root, int value);
BiTree FindCommonAnces(BiTree root, BiTree p, BiTree q);
// 答案不对 暂搁置
int main() {
    vector<int> array1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    BiTree root = sortedArrayToBST(array1);
    levelOrder(root);
    cout << endl;
    BiTree p = findNode(root, 7);
    //    cout << "p = " << p->data << endl;
    BiTree q = findNode(root, 10);
    BiTree r = FindCommonAnces(root, p, q);
    cout << "r = " << r->data << endl;
    return 0;
}
BiTree FindCommonAnces(BiTree root, BiTree p, BiTree q) {
    int top = 0, top1;
    BiTree bt = root;
    while (bt != nullptr || top > 0) {
        while (bt != nullptr) {
            s[++top].t = bt;
            s[top].tag = 0;
            bt = bt->lchild;
        }
        while (top != 0 && s[top].tag == 1) {
            if (s[top].t == p) {
                for (int i = 1; i <= top; ++i) {
                    s1[i] = s[i];
                    top1 = top;
                }
            }
            if (s[top].t == q) {
                for (int i = top; i > 0; i--) {
                    for (int j = top1; j > 0; j--) {
                        cout << s1[j].t->data << " " << s[i].t->data << endl;
                        if (s1[j].t == s[i].t) {
                            return s[i].t;
                        }
                    }
                }
            }
            top--;
        }
        if (top != 0) {
            s[top].tag = 1;
            bt = s[top].t->lchild;
        }
    }
}
/**
 * Q: 二叉树遍历用递归为什么无法返回指定值的节点
 * A: 在递归中，当函数执行到一个节点时，它需要向下递归，访问当前节点的左子树和右子树。如果在左子树或右子树中找到了目标节点，我们需要向上返回该节点的值。
但是，在递归函数中，我们没有办法直接返回一个节点的指针，因为递归函数每次返回时只返回一个值，因此我们通常只能返回节点的值而不是指针。
如果需要返回指定值的节点，我们可以使用迭代算法或在递归函数中使用指向指针的指针。例如，在递归函数中传递一个指向指针的指针，当我们找到目标节点时，可以将该节点的指针赋值给指向指针的指针，以便在递归返回时传递该节点的指针。
 * @param root
 * @param value
 * @return
 */
BiTree findNode(BiTree root, int value) {
    queue<BiTree> q;
    BiTree p;
    q.push(root);
    while (!q.empty()) {
        p = q.front();
        if (p->data == value) {
            return p;
        }
        q.pop();
        if (p->lchild != nullptr) {
            q.push(p->lchild);
        }
        if (p->rchild != nullptr) {
            q.push(p->rchild);
        }
    }
}
