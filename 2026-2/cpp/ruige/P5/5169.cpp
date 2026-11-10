#include <iostream>
using namespace std;

typedef int SElemType;

typedef struct LNode{
    SElemType	data;
    struct LNode *next;
}LNode, * LinkList;
// 栈操作的函数声明
typedef LinkList LinkStack;
void InitStack_L(LinkStack &S);
void Push_L(LinkStack &S, SElemType e);
bool Pop_L(LinkStack &S, SElemType &e);
bool StackEmpty_L(LinkStack S);
// 栈操作的函数定义
void InitStack_L(LinkStack &S)
{ //构造一空栈
    S = NULL;
} //InitStack_L
void Push_L(LinkStack &S, SElemType e)
{ //将新元素e插入链栈S
    LNode *p;
    p=new  LNode;  //分配新结点
    p->data=e;
    p->next=S;  S=p;   //修改栈顶指针
} //push_L
bool Pop_L(LinkStack &S, SElemType &e)
{ //若栈不为空，用e返回栈顶元素，并删除之
    LNode *p;
    if(S) {
        p=S;
        S=S->next;//修改栈顶指针
        e=p->data;
        delete p;//释放结点空间
        return true;
    } else
        return false;
}// Pop_L
bool StackEmpty_L(LinkStack S)
{
    if(S)
        return false;
    else
        return true;
}
int g(int, int);

int g(int m, int n) {

    LinkStack S;
    InitStack_L(S);

    if (m == 0) {
        return 0;
    }

    while (m > 0) {
        Push_L(S, n / 2 + m + 10);
        m--;
        n *= 2;
    }

    int tmp = 0;

    while (!StackEmpty_L(S)) {
        int t = 0;
        Pop_L(S, t);
        tmp += t;
    }

    return tmp;
}

int main() {

    int m, n;
    cout << "g(m,n)=??\nInput m n: ";
    cin >> m >> n;
    cout << "\ng(" << m << "," << n << ")=" << g(m, n);
    return 0;
}