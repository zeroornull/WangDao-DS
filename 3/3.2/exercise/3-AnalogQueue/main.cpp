#include <iostream>
#include <stack>
using namespace std;
stack<int> s1;
stack<int> s2;
void Enqueue(int x);
int Dequeue();
void QueueEmpty();
int main() {
    int x = 1;
    Enqueue(x);
    Enqueue(x);
    x = Dequeue();
    x = Dequeue();
    QueueEmpty();
    return 0;
}
void QueueEmpty() {
    if (s1.empty() && s2.empty()) {
        cout << "empty" << endl;
    }
}
int Dequeue() {
    while (!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
    }
    int enqueueValue = s2.top();
    s2.pop();
    return enqueueValue;
}
void Enqueue(int x) {
    s1.push(x);
}
