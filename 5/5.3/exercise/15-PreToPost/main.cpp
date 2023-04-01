#include <iostream>
#include <vector>
using namespace std;

void PreToPost(vector<char> pre, int l1, int h1, vector<char> &post, int l2, int h2);
int main() {
    vector<char> pre = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    vector<char> post(7);
    PreToPost(pre, 0, 6, post, 0, 6);
    for (int i = 0; i <= 6; ++i) {
        cout << post[i] << " ";
    }
    cout << endl;

    return 0;
}
void PreToPost(vector<char> pre, int l1, int h1, vector<char> &post, int l2, int h2) {
    int half;
    if (h1 >= l1) {
        post[h2] = pre[l1];
        half = (h1 - l1) / 2;
        PreToPost(pre, l1 + 1, l1 + half, post, l2, l2 + half - 1);
        PreToPost(pre, l1 + half + 1, h1, post, l2 + half, h2 - 1);
    }
}
