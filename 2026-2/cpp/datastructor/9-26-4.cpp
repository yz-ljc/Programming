// 编写算法DivideList_L()，将整型链表A分成两个链表B和C，其中：链表B是A中的所有数据元素值为奇数的结点，链表C是A中的所有数据元素值为偶数的结点，链表A成为空表。
// 要求：先写出数据类型定义，再写算法。

#include <iostream>
using namespace std;

typedef int ElemType;

typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

void DivideList_L(LinkList & A, LinkList & B, LinkList & C) {
    if (A == nullptr || A->next == nullptr) return;

    LNode * p = A->next;

    while (p != nullptr) {

        LNode * t = p->next;

        if (p->data % 2 == 0) {
            p->next = C->next;
            C->next = p;
        } else {
            p->next = B->next;
            B->next = p;
        }

        p = t;
    }

    A->next = nullptr;
}