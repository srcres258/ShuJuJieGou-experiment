/**
 * 实验内容3：设顺序表A中的数据元素递增有序，试写一程序，将x插入到顺序表的适当位置上，使该表仍然有序。
 */

#include "common.h"

int main() {
    LinkedList A, p, n;
    array<int, 5> initial({1, 14, 51, 419, 1981});
    int x;

    CreateList_L(A, initial);
    cout << "单链表建立成功！初始元素是：";
    for (p = A->next; p; p = p->next) {
        cout << p->data << " ";
    }
    cout << endl;

    cout << "请输入要插入的元素：";
    cin >> x;
    for (p = A->next; p; p = p->next) {
        if (!p->next) {
            n = new LNode;
            n->data = x;
            n->next = nullptr;
            p->next = n;
            break;
        }
        if (p->data <= x && p->next->data >= x) {
            n = new LNode;
            n->data = x;
            n->next = p->next;
            p->next = n;
            break;
        }
    }
    cout << "插入完毕！现在单链表中的元素有：";
    for (p = A->next; p; p = p->next) {
        cout << p->data << " ";
    }
    cout << endl;

    return 0;
}
