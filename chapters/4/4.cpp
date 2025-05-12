//二叉排序树中查找关键字为key的记录
#include<iostream>
using namespace std;

typedef struct ElemType {
    int key;  // 关键字域
} ElemType;

typedef struct BSTNode {
    ElemType data;    // 结点数据域
    BSTNode *lchild, *rchild;  // 左右孩子指针
} BSTNode, *BSTree;

BSTree SearchBST(BSTree T, int key) {
    if (T == nullptr || T->data.key == key) {
        return T;
    }
    if (key < T->data.key) {
        return SearchBST(T->lchild, key);
    } else {
        return SearchBST(T->rchild, key);
    }
}

void InsertBST(BSTree &T, ElemType e) {
    if (T == nullptr) {
        T = new BSTNode;
        T->data = e;
        T->lchild = nullptr;
        T->rchild = nullptr;
        return;
    }
    if (e.key < T->data.key) {
        InsertBST(T->lchild, e);
    } else if (e.key > T->data.key) {
        InsertBST(T->rchild, e);
    }
}

void InOrderTraverse(BSTree T) {
    if (T == nullptr) {
        return;
    }
    InOrderTraverse(T->lchild);
    cout << T->data.key << " ";
    InOrderTraverse(T->rchild);
}

void CreateBST(BSTree &T) {
    int n, i;
    ElemType e;

    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> e.key;
        InsertBST(T, e);
    }
}

int main() {
    BSTree T, result;
    int key;

    T = nullptr;
    CreateBST(T);
    cout << "当前二叉排序树的中序遍历结果为：";
    InOrderTraverse(T);
    cout << endl;
    cin >> key;
    result = SearchBST(T, key);
    if (result) {
        cout << "查找成功！关键字 " << key << " 存在于二叉排序树中。";
    } else {
        cout << "查找失败！关键字 " << key << " 不存在于二叉排序树中。";
    }

    return 0;
}
