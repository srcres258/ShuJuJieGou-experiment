/**
 * 实验内容1：实现单链表的创建。
 */

#include "common.h"

int main() {
    LinkedList L, p;
    array<int, 5> arr({ 1, 2, 3, 4, 5 });

    CreateList_L(L, arr);
    cout << "单链表建立成功！初始元素是：";
    for (p = L->next; p; p = p->next) {
        cout << p->data << " ";
    }
    cout << endl;

    return 0;
}
