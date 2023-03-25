#include <iostream>
#include <queue>// 队列
#include <stack>//栈
#include <vector>
using namespace std;
int main() {
    vector<int> array = {1, 2, 3, 4, 5};
    stack<int> s;
    queue<int> q;
    for (const auto &item: array) {
        q.push(item);
    }
    while (!q.empty()) {
        cout << q.front() << " " ;
        s.push(q.front());
        q.pop();
    }
    cout << endl;
    while (!s.empty()) {
        cout << s.top() << " " ;
        q.push(s.top());
        s.pop();
    }cout << endl;

    while (!q.empty()) {
        cout << q.front() << " " ;
        q.pop();
    }
    return 0;
}
