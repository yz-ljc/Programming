//  typedef struct {
//      KeyType key;
//      InfoType info;
//  }ElemType;
// 编写算法partition_Link() ，以链表的表头元素为界把链表划分成两部分，要求链接在分界元素之前的元素，其key值都比分界元素小，而链接在其后的元素，其key值都比分界元素大。
// 要求：先写出数据类型定义，再写算法。
#include <iostream>
using namespace std;

typedef int KeyType;
typedef int InfoType;

typedef struct {
    KeyType key;
    InfoType info;
} ElemType;

typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

void partition_Link(LinkList &L) {
    if (L == nullptr || L->next == nullptr) return;

    LinkList left = new LNode;
    left->next = nullptr;

    LinkList right = new LNode;
    right->next = nullptr;

    LNode *tmp = L->next;
    LNode *p = tmp->next;

    while (p != nullptr) {
        if (p->data.key <= tmp->data.key) {
            LNode *t = p;
            p = p->next;
            t->next = left->next;
            left->next = t;
        } else {
            LNode *t = p;
            p = p->next;
            t->next = right->next;
            right->next = t;
        }
    }

    tmp->next = right->next;
    LNode * temp = left->next;

    if (temp != nullptr) {
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = tmp;
        L->next = left->next;
    } else {
        L->next = tmp;
    }

    delete left;
    delete right;
}
