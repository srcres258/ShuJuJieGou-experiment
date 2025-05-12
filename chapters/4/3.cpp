//非递归算法实现的折半查找
#include<iostream>
using namespace std;
#define MAXSIZE 100
#define OK 1

typedef struct {
	int key; // 关键字域
} ElemType;

typedef struct {
	ElemType* R;
	int length;
} SSTable;

int InitList_SSTable(SSTable& L) {
	L.R = new ElemType[MAXSIZE];
    if (!L.R) {
        return 0;
    }
    L.length = 0;
    return OK;
}

int Insert_SSTable(SSTable& L, int key) {
	if (L.length >= MAXSIZE) {
        return 0;
    }
    L.R[L.length].key = key;
    L.length++;
    return OK;
}

int Search_Bin_Recursive(SSTable ST, int key, int low, int high) {
    int mid;
    
    if (low > high) {
        return 0;
    }

    mid = (low + high) / 2;
    cout << "当前查找区间：[" << low << ", " << high << "]"
        << "，中间位置：" << mid << "，值：" << ST.R[mid].key << endl;
    
    if (ST.R[mid].key == key) {
        return mid + 1;
    } else if (ST.R[mid].key < key) {
        return Search_Bin_Recursive(ST, key, mid + 1, high);
    } else {
        return Search_Bin_Recursive(ST, key, low, mid - 1);
    }
}

int Search_Bin(SSTable ST, int key) {
	return Search_Bin_Recursive(ST, key, 0, ST.length - 1);
}

int main() {
    SSTable L;
    int n, key, i, num, pos;

    InitList_SSTable(L);
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> num;
        Insert_SSTable(L, num);
    }
    cin >> key;
    pos = Search_Bin(L, key);
    if (pos) {
        cout << "查找" << key << "：查找成功，返回位置" << pos << endl;
    } else {
        cout << "查找" << key << "：查找失败，返回0" << endl;
    }

    delete[] L.R; // 释放动态分配的内存

    return 0;
}
