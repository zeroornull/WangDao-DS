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

bool DeleteMin(SqList &L, ElemType &value);
int main() {
    SqList L;
    L.data[0] = 1;
    L.data[1] = 2;
    L.data[2] = 3;
    L.length = 3;
    bool ret = ListInsert(L, 3, 60);
    if (ret) {
        printf("insert sqlist success\n");
        PrintList(L);
    } else {
        printf("insert sqlist fail\n");
    }
    ElemType min = 0;
    ret = DeleteMin(L, min);
    if (ret) {
        PrintList(L);
        printf("min=%d", min);
    } else {
        printf("DeleteMin sqlist fail\n");
    }

    return 0;
}
bool DeleteMin(SqList &L, ElemType &value) {
    if (L.length == 0) {
        return false;
    }
    value = L.data[0];
    int pos = 0;
    for (int i = 1; i < L.length; ++i) {
        if (L.data[i] < value) {
            value = L.data[i];
            pos = i;
        }
    }
    L.data[pos] = L.data[L.length - 1];
    L.length--;
    return true;
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