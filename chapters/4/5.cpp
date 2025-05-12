//哈希表查找操作
#include<iostream>
using namespace std;

#define m 13  // 哈希表的表长
#define NULLKEY -1  // 空单元的标记

struct HashTable {
    int key;  // 关键字域
};


int H(int key) {
    return key % 13; // 哈希函数直接返回模13的结果
}


int SearchHash(HashTable HT[], int key) {
    int h, count;

    h = H(key);
    count = 0;
    while (count < m) { // 最多探测m次，防止无限循环
        if (HT[h].key == key) {
            return h; // 找到目标元素，返回位置
        }
        if (HT[h].key == NULLKEY) {
            break; // 遇到空单元，说明后续不可能存在该元素
        }
        h = (h + 1) % m; // 线性探测下一个位置
        count++;
    }

    return -1; // 未找到
}

void PrintHashTable(HashTable HT[]) {
    int i;

    for (i = 0; i < m; i++) {
        cout << "[" << i << "] -> ";
        if (HT[i].key == NULLKEY) {
            cout << "空";
        } else {
            cout << HT[i].key;
        }
        cout << endl;
    }
}

int main() {
    HashTable HT[m];
    int i, n, key, h, target, pos;

    // 初始化哈希表为空
    for (i = 0; i < m; i++) {
        HT[i].key = NULLKEY;
    }
    cin >> n;
    // 插入元素到哈希表
    for (i = 0; i < n; i++) {
        cin >> key;
        h = H(key);
        // 线性探测找到空位置插入
        while (HT[h].key != NULLKEY) {
            h = (h + 1) % m;
        }
        HT[h].key = key;
    }
    // 打印哈希表
    cout << "哈希表当前内容：" << endl;
    PrintHashTable(HT);
    // 查找目标元素
    cin >> target;
    pos = SearchHash(HT, target);
    if (pos != -1) {
        cout << "元素 " << target << " 找到在哈希表位置：" << pos;
    } else {
        cout << "元素 " << target << " 不在哈希表中。";
    }

    return 0;
}
