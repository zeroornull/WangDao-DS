#include "bi_tree.h"
#define maxsize 100
int Length(BiTree root);
int main() {
    vector<int> array = {1, 2, 3, 4, 5, 6};
    BiTree root = sortedArrayToBST(array);
    int length = Length(root);
    cout << "length = " << length << endl;
    return 0;
}
int Length(BiTree root) {
    int front = -1, rear = -1;
    int last = 0, level = 0;
    BiTree Q[maxsize];
    Q[++rear] = root;
    BiTree p;
    while (front < rear) {
        p = Q[++front];
        if (p->lchild) {
            Q[++rear] = p->lchild;
        }
        if (p->rchild) {
            Q[++rear] = p->rchild;
        }
        if (front == last) {
            level++;
            last = rear;
        }
    }
    return level;
}
