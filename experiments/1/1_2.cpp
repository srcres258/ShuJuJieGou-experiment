/**
 * 实验内容2：实现单链表的增加和删除。
 */

#include "common.h"

int main() {
    LinkedList L, p, n, prev;
    array<int, 5> initial({1, 2, 3, 4, 5});
    array<int, 4> toBeAppended({6, 7, 8, 9});
    array<int, 3> toBeDeleted({2, 4, 6});

    // 初始化链表
    CreateList_L(L, initial);
    cout << "单链表建立成功！初始元素是：";
    for (p = L->next; p; p = p->next) {
        cout << p->data << " ";
    }
    cout << endl;

    // 增加元素
    for (p = L->next; p->next; p = p->next);
    for (auto &e : toBeAppended) {
        cout << "向单链表中增加元素：" << e << endl;
        n = new LNode;
        n->data = e;
        n->next = nullptr;
        p->next = n;
        p = n;
    }
    cout << "增加元素完毕，现在单链表中的元素有：";
    for (p = L->next; p; p = p->next) {
        cout << p->data << " ";
    }
    cout << endl;

    // 删除元素
    for (auto &e : toBeDeleted) {
        prev = L;
        for (p = L->next; p; prev = p, p = p->next) {
            if (p->data == e) {
                cout << "从单链表中删除元素：" << e << endl;
                prev->next = p->next;
                delete p;
                break;
            }
        }
    }
    cout << "删除元素完毕，现在单链表中的元素有：";
    for (p = L->next; p; p = p->next) {
        cout << p->data << " ";
    }
    cout << endl;

    return 0;
}
