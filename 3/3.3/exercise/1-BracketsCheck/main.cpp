#include <iostream>
#include <stack>
#include <string>
using namespace std;
bool BracketsCheck(stack<char> &s, string string);
int main() {
    stack<char> s;
    string str = "([{}])";
    BracketsCheck(s, str);

    return 0;
}
bool BracketsCheck(stack<char> &s, string str) {
    for (char i: str) {
        switch (i) {
            case '(':
                s.push(i);
                break;
            case '[':
                s.push(i);
                break;
            case '{':
                s.push(i);
                break;
            case ')':
                if (s.top() != '(') {
                    return false;
                }
                s.pop();
                break;
            case ']':
                if (s.top() != '[') {
                    return false;
                }
                s.pop();
                break;
            case '}':
                if (s.top() != '{') {
                    return false;
                }
                s.pop();
                break;
            default:
                break;
        }
    }
    if (s.empty()) {
        cout << "check well" << endl;
    } else {
        cout << "check not well" << endl;
    }
}
