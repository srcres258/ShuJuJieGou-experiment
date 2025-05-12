#include <iostream>
using namespace std;
#define MAXSIZE 100    // 顺序表的最大长度

typedef struct {
    int key;
    char *otherinfo; // 此处题目未使用，仅保留结构
} ElemType;

// 顺序表的存储结构
typedef struct {
    ElemType *r;     // 存储空间的基地址
    int length;      // 顺序表长度
} SqList;           // 顺序表类型

// 直接插入排序实现
void InsertSort(SqList &L) {
    int i, j;
    ElemType temp;
    
    // 从第二个元素开始遍历（下标1）
    for (i = 1; i < L.length; i++) {
        temp = L.r[i]; // 暂存当前待插入元素
        j = i - 1; // 从有序区末尾开始比较

        // 寻找插入位置并后移元素
        while (j >= 0 && L.r[j].key > temp.key) {
            L.r[j + 1] = L.r[j]; // 将大于temp的元素后移
            j--;
        }
        L.r[j + 1] = temp; // 插入到正确位置
    }
}

// 创建顺序表并读取输入
void Create_Sq(SqList &L) {
    int n, i;

    cin >> n; // 读取元素个数

    L.r = new ElemType[MAXSIZE]; // 动态分配存储空间
    for (i = 0; i < n; i++) {
        cin >> L.r[i].key; // 读取每个元素值
    }
    L.length = n; // 设置顺序表长度
}

int main() {
    SqList L;
    int i;

    Create_Sq(L); // 创建并初始化顺序表
    InsertSort(L); // 执行插入排序

    cout << "排序后的结果为：";
    for (i = 0; i < L.length; i++) { // 输出排序结果
        cout << L.r[i].key << " ";
    }
    cout << endl;

    delete[] L.r; // 释放动态分配的内存

    return 0;
}
