#include <iostream>
#include <stack>
double p(int n, double x);
using namespace std;

int main() {

    int n = 2;
    double x = 2.0;
    double result = p(n, x);
    cout << result << endl;

    return 0;
}
double p(int n, double x) {
    stack<int> s1;
    double fv1 = 1, fv2 = 2 * x, temp;
    for (int i = n; i >= 2; i--) {
        s1.push(i);
    }
    while (!s1.empty()) {
        temp = 2 * x * fv2 - 2 * (s1.top() - 1) * fv1;
        fv1 = fv2;
        fv2 = temp;
        s1.pop();
    }
    if (n == 0) {
        return fv1;
    }
    return fv2;
}
