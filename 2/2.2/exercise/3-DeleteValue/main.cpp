#include <stdio.h>
//顺序表插入与排序
#define MaxSize 50
typedef int ElemType;
//静态分配
typedef struct {
    ElemType data[MaxSize];
    int length;//当前顺序表中有多少个元素
} SqList;

bool ListInsert(SqList &L, int pos, ElemType element);
void PrintList(SqList l);

void DeleteByValue(SqList &l, int value);
int main() {
    SqList L;
    L.data[0] = 1;
    L.data[1] = 2;
    L.data[2] = 3;
    L.length = 3;
    bool ret = ListInsert(L, 3, 60);
    ListInsert(L, 3, 60);
    if (ret) {
        printf("insert sqlist success\n");
        PrintList(L);
    } else {
        printf("insert sqlist fail\n");
    }
    int value = 60;
    DeleteByValue(L, value);
    PrintList(L);
    return 0;
}
void DeleteByValue(SqList &l, int value) {
    int j = l.length - 1;
    for (int i = 0; i < l.length; ++i) {
        if (l.data[i] == value) {
            l.data[i] = l.data[j];
            l.length--;
            j = l.length - 1;
        }
    }
}

void PrintList(SqList l) {
    for (int i = 0; i < l.length; ++i) {
        printf("%3d", l.data[i]);
    }
    printf("\n");
}

bool ListInsert(SqList &L, int pos, ElemType element) {
    // 判断pos是否合法
    if (pos <= 1 || pos >= L.length + 1) {
        return false;
    }
    // 存储满也无法插入
    if (L.length >= MaxSize) {
        return false;
    }
    //将后面的元素依次往后移动 空出位置 放入插入的元素
    for (int i = L.length; i >= pos; --i) {
        L.data[i] = L.data[i - 1];
    }
    // 插入所在位置
    L.data[pos - 1] = element;
    // 长度+1
    L.length++;
    return true;
}
