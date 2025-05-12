//关键字取整数的记录进行整序
#include <iostream>
using namespace std;

#define MAXSIZE 100

typedef struct {
    int key;
    char* otherinfo;  // 可选信息，这里未使用
} ElemType;

typedef struct {
    ElemType* r;  // 存储基地址
    int length;   // 实际长度
} SqList;

void Reorder_PositiveFirst(SqList& L) {
    int i, j;

    i = 0;
    j = L.length - 1;
    while (i < j) {
        if (L.r[i].key < 0) {
            // 从右向左找第一个非负数
            while (i < j && L.r[j].key < 0) {
                j--;
            }
            // 交换i和j位置的元素
            if (i < j) {
                swap(L.r[i], L.r[j]);
                i++;
                j--;
            }
        } else {
            i++;
        }
    }
}

void Create_Sq(SqList& L) {
    int n, i;

    cin >> n;
    L.r = new ElemType[n];
    L.length = n;
    for (i = 0; i < n; i++) {
        cin >> L.r[i].key;
    }
}

void Print_SqList(const SqList& L) {
    int i;

    for (i = 0; i < L.length; i++) {
        if (i > 0) {
            cout << " ";
        }
        cout << L.r[i].key;
    }
}

int main() {
    SqList L;

    Create_Sq(L);
    Reorder_PositiveFirst(L);

    cout << "重排后的结果为：";
    Print_SqList(L);
    cout << endl;
    
    delete[] L.r; // 释放动态分配的内存

    return 0;
}
