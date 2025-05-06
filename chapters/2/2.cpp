#include <iostream>

using namespace std;

// 二叉树的二叉链表存储表示
typedef struct BiNode {
    char data; // 结点数据域
    BiNode *lchild, *rchild; // 左右孩子指针
} BiTNode, *BiTree;

// 链栈的定义
typedef struct StackNode {
    BiTNode *data;
    StackNode *next;
} StackNode, *LinkStack;

// 初始化栈
void InitStack(LinkStack &S) {
    S = nullptr;
}

// 判断栈是否为空
bool StackEmpty(LinkStack S) {
    return S == nullptr;
}

// 入栈操作
void Push(LinkStack &S, BiTNode *e) {
    StackNode *newNode;

    newNode = new StackNode;
    newNode->data = e;
    newNode->next = S;
    S = newNode;
}

// 出栈操作
void Pop(LinkStack &S, BiTNode *&e) {
    StackNode *temp;

    if (!S) {
        e = nullptr;
        return;
    }
    temp = S;
    e = temp->data;
    S = S->next;
    delete temp;
}

// 非递归中序遍历算法
void InOrderTraverse(BiTree T) {
    LinkStack S;
    BiTNode *current;

    InitStack(S);
    current = T;
    while (current || !StackEmpty(S)) {
        while (current) {
            Push(S, current);
            current = current->lchild;
        }
        if (!StackEmpty(S)) {
            Pop(S, current);
            cout << current->data;
            current = current->rchild;
        }
    }
    cout << endl;
}

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

int main() {
    BiTree T;
    string values;
    int index;

    T = nullptr;
    cin >> values;
    index = 0;
    CreateBiTree(T, values, index);
    cout << "中序遍历的结果为：" << endl;
    InOrderTraverse(T);

    return 0;
}
