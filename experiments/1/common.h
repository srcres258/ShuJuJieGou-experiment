#ifndef COMMON_H
#define COMMON_H

/**
 * 实验一 线性表
 * 
 * [问题描述] 
 * 用链表形式存储一组数据元素，插入、删除某个数据元素，最后按正序、逆序两种方式输出数据元素。
 * 
 * [存储结构]
 * 采用链式存储结构
 * 
 * [算法的基本思想]
 * 建立单链表：当读入字符不是结束符时，给结点分配存储空间，写数据域，将新结点插到表尾；插入数据元素：根据读入的字符在链表中找到插入位置，将新结点插入到该位置之前；删除字符：根据读入的待删除数据元素在链表中找到被删结点后，将其从链表中删除；链表逆转：从链表的第一个结点开始对所有结点处理，将每个结点的前驱变为它的后继；打印链表：从链表的第一个结点开始，依次打印各个结点的数据域。
 * 
 * [实验步骤]
 * （1）建立单链表。 
 * （2）输出数据元素 X 的位置。 
 * （3）输出第 i 个数据元素。 
 * （4）在第 i 个元素前插入值为 y 的数据元素，然后输出单链表。 
 * （5）输出删除第 i 个元素后的链表
 */

#include <iostream>
#include <array>

using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status;     // Status是函数返回值类型，其值是函数结果状态代码
typedef int ElemType;   // ElemType为可定义的数据类型，此设为int类型

typedef struct LNode {
    ElemType data;      // 结点的数据域
    LNode *next;        // 结点的指针域
} *LinkedList;          // LinkedList为指向结构体LNode的指针类型

Status InitList_L(LinkedList &L) {  // 算法2.6 单链表的初始化
    L = new LNode;      // 生成新结点作为头结点，用头指针L指向头结点
    L->next = nullptr;  // 头结点的指针域置空
    return OK;
}

void CreateList_L(LinkedList &L, array<int, 5> &a) {  // 算法2.12 后插法创建单链表
    LNode *r, *p;
    int i;
    
    // 建立到头结点的单链表L
    L = new LNode;
    L->next = nullptr;
    r = L;
    for (i = 0; i < 5; i++) {
        p = new LNode;
        p->data = a[i];
        p->next = nullptr;
        r->next = p;
        r = p;
    }
}

Status ListInsert_L(LinkedList &L, int i, ElemType &e) {    // 算法2.9 单链表的插入
    int j;
    LNode *p, *s;

    p = L;
    j = 0;
    while (p && j < i - 1) {    // 寻找第i-1个结点
        p = p->next;
        j++;
    }
    if (!p || j > i - 1) {      // i大于表长+1或者小于1
        return ERROR;
    }
    s = new LNode;              // 生成新结点s
    s->data = e;                // 将结点s的数据域置为e
    s->next = p->next;          // 将结点s插入L中
    p->next = s;

    return OK;
}

/** 在带头结点的单链表L中，删除第i个位置，并由e返回值 */
Status ListDelete_L(LinkedList &L, int i, ElemType &e) {    // 算法2.10 单链表的删除
    LNode *p, *q;
    int j;

    p = L;
    j = 0;
    while (p && j < i - 1) {        // 寻找第i-1个结点
        p = p->next;
        j++;
    }
    if (!(p->next) || j > i - 1) {  // i大于表长+1或者小于1
        return ERROR;
    }
    q = p->next;                    // 临时保存被删结点的地址以备释放
    p->next = q->next;              // 改变删除结点前驱结点的指针域
    e = q->data;                    // 保存删除结点的数据域
    delete q;                       // 释放删除结点的空间

    return OK;
}

#endif /* COMMON_H */
