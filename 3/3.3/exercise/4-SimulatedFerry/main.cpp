#include <iostream>
#include <queue>
using namespace std;

queue<int> q;
queue<int> q1;
queue<int> q2;

int main() {
    int i = 0, j = 0, x;
    while (j < 10) {
        if (!q1.empty() && i < 4) {
            x = q1.front();
            q.push(x);
        } else if (i == 4 && !q2.empty()) {
            x = q2.front();
            q.push(x);
            j++;
            i = 0;
        } else {
            while (j < 10 && i < 4 && !q2.empty()) {
                x = q2.front();
                q.push(x);
                i++;
                j++;
            }
            i = 0;
        }
        if (q1.empty() && q2.empty()) {
            j = 11;
        }
    }
    return 0;
}
