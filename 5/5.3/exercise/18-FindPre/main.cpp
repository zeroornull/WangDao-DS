#include <iostream>
typedef int Elemtype;
typedef struct ThreadNode {
    Elemtype data;
    struct ThreadNode *lchild, *rchild;
    int ltag, rtag;
} ThreadNode, *ThreadTree;
// 暂未实现
int main() {
    return 0;
}
ThreadTree InPostPre(ThreadTree t, ThreadTree p) {
    ThreadTree q;
    if (p->rtag == 0) {
        q = p->rchild;
    } else if (p->ltag == 0) {
        q = p->lchild;
    } else if (p->lchild == nullptr) {
        q = nullptr;
    } else {
        while (p->ltag == 1 && p->lchild != nullptr) {
            p = p->lchild;
        }
        if (p->ltag == 0) {
            q = p->lchild;
        } else {
            q = nullptr;
        }
    }
    return q;
}