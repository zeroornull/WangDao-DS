#include <iostream>
#include <stack>
#include <vector>
using namespace std;

typedef int ElemType;
typedef struct BiTNode {
    ElemType data;
    struct BiTNode *lchild, *rchild;
    BiTNode(int x) : data(x), lchild(nullptr), rchild(nullptr) {}
} BiTNode, *BiTree;

BiTree sortedArrayToBST(vector<int> &nums);
BiTree buildTree(vector<int> &nums, int left, int right);

void postorderTraversal(BiTree root);


void postOrderNoRecur(BiTree root);
int main() {
    vector<int> array = {1, 2, 3, 4, 5, 6};
    BiTree root = sortedArrayToBST(array);
    postorderTraversal(root);
    cout << endl;
    postOrderNoRecur(root);
    return 0;
}
void postOrderNoRecur(BiTree root) {
    stack<BiTree> s;
    BiTree p = root, r = nullptr;
    while (p || !s.empty()) {
        if (p) {
            s.push(p);
            p = p->lchild;
        } else {
            p = s.top();
            if (p->rchild && p->rchild != r) {
                p = p->rchild;
            } else {
                p = s.top();
                cout << p->data << " ";
                s.pop();
                r = p;
                p = nullptr;
            }
        }
    }
}

BiTree sortedArrayToBST(vector<int> &nums) {
    return buildTree(nums, 0, nums.size() - 1);
}
BiTree buildTree(vector<int> &nums, int left, int right) {
    if (left > right) {
        return nullptr;
    }
    int mid = (left + right) / 2;
    auto root = new BiTNode(nums[mid]);
    root->lchild = buildTree(nums, left, mid - 1);
    root->rchild = buildTree(nums, mid + 1, right);
    return root;
}

void postorderTraversal(BiTree root) {
    if (root == nullptr) {
        return;
    }
    postorderTraversal(root->lchild);
    postorderTraversal(root->rchild);
    cout << root->data << " ";
}
