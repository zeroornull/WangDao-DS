#include "bi_tree.h"
#include <stack>
void ReverseLevelOrder(BiTree root);
int main() {
    vector<int> array = {1, 2, 3, 4, 5, 6};
    BiTree root = sortedArrayToBST(array);
    levelOrder(root);
    cout << endl;
    ReverseLevelOrder(root);
    return 0;
}
void ReverseLevelOrder(BiTree root) {
    queue<BiTree> q;
    stack<BiTree> s;
    BiTree p;
    q.push(root);
    while (!q.empty()) {
        p = q.front();
        s.push(p);
        q.pop();
        if (p->lchild != nullptr) {
            q.push(p->lchild);
        }
        if (p->rchild != nullptr) {
            q.push(p->rchild);
        }
    }
    while (!s.empty()) {
        cout << s.top()->data << " ";
        s.pop();
    }
}
