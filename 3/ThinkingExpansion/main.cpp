#include <iostream>
#include <stack>
using namespace std;

class MinStack {
private:
    stack<int> s1;// 主栈，存储数据
    stack<int> s2;// 辅助栈，存储当前最小值

public:
    void push(int x) {
        s1.push(x);
        if (s2.empty() || x <= getMin()) {
            s2.push(x);
        }
    }

    void pop() {
        if (s1.top() == getMin()) {
            s2.pop();
        }
        s1.pop();
    }

    int top() {
        return s1.top();
    }

    int getMin() {
        return s2.top();
    }
};

int main() {
    MinStack ms;
    ms.push(3);
    ms.push(2);
    ms.push(5);
    ms.push(1);
    cout << ms.getMin() << endl;
    return 0;
}
