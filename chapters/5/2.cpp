//冒泡排序算法
#include <iostream>
using namespace std;
#define MAXSIZE 100   // 顺序表的最大长度

typedef struct {
    int key;
    char* otherinfo;
} ElemType;

// 顺序表的存储结构
typedef struct {
    ElemType* r;  // 存储空间的基地址
    int length;   // 顺序表长度
} SqList;  // 顺序表类型

void BubbleSort(SqList& L) {
    int i, j;
    
    // 外层循环控制排序轮数，每轮确定一个最大元素的位置
    for (i = 0; i < L.length - 1; i++) {
        // 内层循环进行相邻元素比较和交换
        for (j = 0; j < L.length - i - 1; j++) {
            if (L.r[j].key > L.r[j + 1].key) { // 若前大后小则交换
                swap(L.r[j], L.r[j + 1]); // 使用标准库交换元素
            }
        }
    }
}

void Create_Sq(SqList& L) {
    int n, i;

    cin >> n; // 读取元素个数
    L.r = new ElemType[MAXSIZE]; // 动态分配内存
    L.length = n; // 设置顺序表长度
    for (i = 0; i < n; i++) {
        cin >> L.r[i].key; // 循环读取每个元素
    }
}

void Print_SqList(SqList L) {
    int i;

    if (L.length == 0) { // 处理空表情况
        return;
    }
    cout << L.r[0].key; // 输出第一个元素
    for (i = 1; i < L.length; i++) {
        cout << " " << L.r[i].key; // 后续元素前加空格
    }
    cout << endl; // 换行符
}

int main() {
    SqList L;

    Create_Sq(L); // 创建顺序表
    BubbleSort(L); // 冒泡排序

    cout << "排序后的结果为：";
    Print_SqList(L); // 输出排序结果

    delete[] L.r; // 释放内存

    return 0;
}
