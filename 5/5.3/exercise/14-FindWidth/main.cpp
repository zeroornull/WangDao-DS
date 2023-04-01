#include "bi_tree.h"
#define MaxSize 100
typedef struct {
    BiTree data[MaxSize];
    int level[MaxSize];
    int front, rear;
} Qu;
int FindWidth(BiTree root);
int main() {
    vector<int> array1 = {1, 2, 3, 4, 5, 6};
    BiTree root = sortedArrayToBST(array1);
    int width = FindWidth(root);
    cout << "width = " << width << endl;
    return 0;
}

int FindWidth(BiTree root) {
    BiTree p;
    int k, max, i, n;
    Qu Qu;
    Qu.front = Qu.rear = -1;
    Qu.rear++;
    Qu.data[Qu.rear] = root;
    Qu.level[Qu.rear] = 1;
    while (Qu.front < Qu.rear) {
        Qu.front++;
        p = Qu.data[Qu.front];
        k = Qu.level[Qu.front];
        if (p->lchild != nullptr) {
            Qu.rear++;
            Qu.data[Qu.rear] = p->lchild;
            Qu.level[Qu.rear] = k + 1;
        }
        if (p->rchild != nullptr) {
            Qu.rear++;
            Qu.data[Qu.rear] = p->rchild;
            Qu.level[Qu.rear] = k + 1;
        }
    }
    max = 0;
    i = 0;
    k = 1;
    while (i <= Qu.rear) {
        n = 0;
        while (i <= Qu.rear && Qu.level[i] == k) {
            n++;
            i++;
        }
        k = Qu.level[i];
        if (n > max) {
            max = n;
        }
    }
    return max;
}
