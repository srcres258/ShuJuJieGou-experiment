#include <iostream>

using namespace std;

// 二叉树的二叉链表存储表示
typedef struct BiNode {
    char data; // 结点数据域
    BiNode *lchild, *rchild; // 左右孩子指针
} BiTNode, *BiTree;

// 递归创建二叉树
void CreateBiTree(BiTree &T, const string &values, int &i) {
    char ch;
    
    if (i >= values.size()) {
        T = nullptr;
        return;
    }
    ch = values[i++];
    if (ch == '#') {
        T = nullptr;
    } else {
        T = new BiTNode;
        T->data = ch;
        T->lchild = nullptr;
        T->rchild = nullptr;
        CreateBiTree(T->lchild, values, i);
        CreateBiTree(T->rchild, values, i);
    }
}

// 递归实现后序遍历
void PostOrderTraverse(BiTree T) {
    if (T) {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        cout << T->data;
    }
}

int main() {
    BiTree T;
    string values;
    int index;

    T = nullptr;
    cin >> values;
    index = 0;
    CreateBiTree(T, values, index);
    cout << "后序遍历的结果为：" << endl;
    PostOrderTraverse(T);
    cout << endl;

    return 0;
}
