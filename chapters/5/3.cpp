// 简单选择排序
#include <iostream>
using namespace std;
#define MAXSIZE 100  // 顺序表的最大长度

typedef struct {
    int key;
    char* otherinfo;
} ElemType;

// 顺序表的存储结构
typedef struct {
    ElemType* r;  // 存储空间的基地址
    int length;   // 顺序表长度
} SqList;  // 顺序表类型

// 简单选择排序的实现
void SelectSort(SqList& L) {
    int i, j, minIndex;

    for (i = 0; i < L.length - 1; i++) {
        minIndex = i;
        // 遍历未排序部分找到最小值
        for (j = i + 1; j < L.length; j++) {
            if (L.r[j].key < L.r[minIndex].key) {
                minIndex = j;
            }
        }
        // 将最小值交换到已排序序列末尾
        if (minIndex != i) {
            swap(L.r[i], L.r[minIndex]);
        }
    }
}

// 创建顺序表并初始化数据
void Create_Sq(SqList& L) {
    int n, i;

    cin >> n;
    L.r = new ElemType[n]; // 动态分配数组空间
    L.length = n; // 设置顺序表长度
    for (i = 0; i < n; i++) {
        cin >> L.r[i].key; // 读取输入元素
    }
}

void Print_SqList(SqList L) {
    int i;

    for (i = 0; i < L.length; i++) {
        if (i > 0) {
            cout << " ";
        }
        cout << L.r[i].key;
    }
    cout << endl;
}

int main() {
    SqList L;

    Create_Sq(L); // 创建并初始化顺序表
    SelectSort(L); // 执行选择排序

    cout << "排序后的结果为：";
    Print_SqList(L); // 输出排序结果

    delete[] L.r; // 释放动态分配的数组空间

    return 0;
}
