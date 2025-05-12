//设置监视哨的顺序查找
#include<iostream>
using namespace std;
#define MAXSIZE 50
#define OK 1

typedef struct{
	int key;//关键字域
}ElemType;

typedef struct{
	ElemType *R;
	int length;
}SSTable;

int InitList_SSTable(SSTable &L) {
	L.R = new ElemType[MAXSIZE + 1]; // 分配空间，R[0]作为哨兵
    if (!L.R) {
        return 0;
    }
    L.length = 0;
    return OK;
}

int Insert_SSTable(SSTable &L, int key) {
    if (L.length >= MAXSIZE) {
        return 0;
    }
    L.length++;
    L.R[L.length].key = key;
    return OK;
}

int Search_Seq(SSTable ST, int key) {
    int i;
    
    ST.R[0].key = key; // 设置监视哨
    for (i = ST.length; ST.R[i].key != key; i--); // 从后往前查找
    return i;
}

int main() {
    SSTable L;
    int n, pos, i, num, target;

    InitList_SSTable(L);
    
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> num;
        Insert_SSTable(L, num);
    }

    cin >> target;
    pos = Search_Seq(L, target);

    if (pos) {
        cout << "查找" << target << "：查找成功，返回位置" << pos << endl;
    } else {
        cout << "查找" << target << "：查找失败，返回0" << endl;
    }

    delete[] L.R; // 释放内存

    return 0;
}
