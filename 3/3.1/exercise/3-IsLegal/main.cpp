#include <iostream>
#include <string>
using namespace std;

#define MAX 100//定义数组长度
struct Stack   //建立栈
{
    int value[MAX];
    int top;//栈顶的数组序号
};

void Init(Stack &s);
int Push(Stack &s, int e);
int IsEmpty(Stack s);
int Pop(Stack &s, int &e);

int main() {
    Stack S;
    Init(S);
    int e;
    string str = "IIOIOIOO";
    for (auto ch: str) {
        if (ch == 'I') {
            Push(S, 1);
        } else {

            Pop(S, e);
        }
    }
    if (S.top!=-1){
        cout << "illegal"<<endl;
    } else{
        cout << "legal"<<endl;
    }
    return 0;
}


void Init(Stack &s)//初始化栈
{
    s.top = -1;
}
int Push(Stack &s, int e)//把元素e压入栈顶
{
    if (s.top > MAX - 1)//如果超出栈的容量，返回0
        return 0;
    s.top++;           //栈顶加1
    s.value[s.top] = e;//把e赋给栈顶
    return 1;
}
int IsEmpty(Stack s)//判定栈是否为空
{
    if (s.top == -1)
        return 1;
    else
        return 0;
}
int Pop(Stack &s, int &e)//取出栈顶元素，并删除栈顶
{
    if (s.top == -1)//top与base重合时，栈为空
        return 0;
    s.top--;//top先减1，再取元素
    e = s.value[s.top];
    return 1;
}
