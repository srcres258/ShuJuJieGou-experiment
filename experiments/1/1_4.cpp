/**
 * 实验内容4：用单链表ha存储多项式A(x)=a_0+a_1*x^1+a_2*x^2+...+a_n*x^n（其中a_n为非零系数），
 * 用单链表hb存储多项式B(x)=b_0+b_1*x^1+b_2*x^2+...+b_m*x^m（其中b_m为非零系数），要求计算C(x)=A(x)+B(x)，
 * 结果存到单链表hc中，试写出程序。
 */

#include "common.h"

int main() {
    LinkedList ha, hb, hc, p, pa, pb, pc, n;
    array<int, 5> ai = {1, 2, 3, 4, 5};
    array<int, 5> bi = {6, 7, 8, 9, 10};

    CreateList_L(ha, ai);
    cout << "单链表ha建立成功！初始元素是：";
    for (p = ha->next; p; p = p->next) {
        cout << p->data << " ";
    }
    cout << endl;

    CreateList_L(hb, bi);
    cout << "单链表hb建立成功！初始元素是：";
    for (p = hb->next; p; p = p->next) {
        cout << p->data << " ";
    }
    cout << endl;

    InitList_L(hc);
    pa = ha->next;
    pb = hb->next;
    pc = hc;
    while (pa || pb) {
        n = new LNode;
        if (!pa) {
            n->data = pb->data;
        } else if (!pb) {
            n->data = pa->data;
        } else {
            n->data = pa->data + pb->data;
        }
        n->next = nullptr;
        pc->next = n;
        pc = n;
        if (pa) {
            pa = pa->next;
        }
        if (pb) {
            pb = pb->next;
        }
    }

    cout << "单链表hc计算完成，hc的元素为：";
    for (p = hc->next; p; p = p->next) {
        cout << p->data << " ";
    }
    cout << endl;

    return 0;
}
