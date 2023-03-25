#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void TrainArrange(char *train);
// 感觉写的不对 运行结果怪怪的
int main() {
    //    char carr[] = {'H','S','H','S'};
    char carr[] = "HSHS";
    char *train = carr;
    TrainArrange(train);
    for (const auto &item: carr) {
        cout << item << " ";
    }
    return 0;
}
void TrainArrange(char *train) {
    stack<char> s;
    char *p = train, *q = train, c;
    while (*p) {
        if (*p == 'H') {
            s.push(*p);
        } else {
            *(q++) = *p;
        }
        p++;
    }
    while (!s.empty()) {
        c = s.top();
        s.pop();
        *(q++) = c;
    }
}
