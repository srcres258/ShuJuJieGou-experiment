#include <iostream>
using namespace std;
#define  MAXSIZE  100           // 顺序表的最大长度（支持用户输入，最大为100）

typedef struct {
    int key;
    char *otherinfo;
} ElemType;

// 顺序表结构
typedef struct {
    ElemType *r;      // 存储空间基地址
    int length;       // 顺序表长度
} SqList;

// 调整大顶堆（下沉操作）
void HeapAdjust(SqList &L, int s, int m) {
    ElemType rc;
    int j;

    rc = L.r[s];
    for (j = 2 * s + 1; j <= m; j = 2 * j + 1) { // 左孩子索引
        if (j < m && L.r[j].key < L.r[j + 1].key) { // 选较大的子节点
            j++;
        }
        if (rc.key >= L.r[j].key) { // 父节点>=子节点则停止
            break;
        }
        L.r[s] = L.r[j]; // 子节点上移
        s = j; // 继续向下调整
    }
    L.r[s] = rc; // 将原父节点放入最终位置
}

// 建立初始堆
void CreatHeap(SqList &L) {
    int n, i;

    n = L.length;
    for (i = n / 2 - 1; i >= 0; i--) { // 从最后一个非叶子节点开始
        HeapAdjust(L, i, n - 1); // 调整整个数组为大顶堆
    }
}

// 堆排序主逻辑
void HeapSort(SqList &L) {
    int i;

    CreatHeap(L); // 初始建堆
    for (i = L.length - 1; i > 0; i--) {
        swap(L.r[0], L.r[i]); // 将堆顶与末尾元素交换
        HeapAdjust(L, 0, i - 1); // 调整剩余元素为大顶堆
    }
}

// 创建顺序表（输入处理）
void Create_Sq(SqList &L) {
    int n, i;

    cin >> n;
    L.r = new ElemType[n];
    L.length = n;
    for (i = 0; i < n; i++) {
        cin >> L.r[i].key; // 输入元素值
    }
}

// 输出顺序表
void Print_SqList(const SqList &L) {
    int i;

    for (i = 0; i < L.length; i++) {
        cout << L.r[i].key;
        if (i != L.length - 1) {
            cout << " ";
        }
    }
    cout << endl;
}

// 主函数
int main() {
    SqList L;

    Create_Sq(L); // 输入数据
    HeapSort(L); // 堆排序

    cout << "堆排序后的结果为（升序）：";
    Print_SqList(L); // 输出结果

    delete[] L.r; // 释放内存

    return 0;
}
