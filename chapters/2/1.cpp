// 按照先序遍历的顺序创建二叉树，并先序打印
#include<iostream>
using namespace std;

// 二叉树的二叉链表存储表示
typedef struct BiNode {
    char data;                   // 结点数据域
    struct BiNode *lchild, *rchild;  // 左右孩子指针
} BiTNode, *BiTree;

// 创建二叉树
void CreateBiTree(BiTree &T, const char* values, int &i) {
    char ch;

    ch = values[i];
    i++;

    if (ch == '#' || ch == '\0') {
        T = nullptr;
        return;
    }

    T = new BiTNode;
    T->data = ch;
    CreateBiTree(T->lchild, values, i);
    CreateBiTree(T->rchild, values, i);
}

// 先序遍历二叉树
void PreOrderTraverse(BiTree T) {
    if (!T) {
        return;
    }

    cout << T->data;

    if (T->lchild) {
        PreOrderTraverse(T->lchild);
        cout << ' ';
    }
    if (T->rchild) {
        PreOrderTraverse(T->rchild);
    }
}

int main() {
    BiTree T;
    string s;
    int i;

    T = nullptr;
    cin >> s;
    i = 0;

    CreateBiTree(T, s.c_str(), i);
    cout << "二叉树创建成功！" << endl;
    cout << "先序遍历结果为：" << endl;
    PreOrderTraverse(T);
    cout << endl;

    return 0;
}
