#include <iostream>
using namespace std;

typedef int SElemType;
typedef struct LNode {
    SElemType data;
    struct LNode * next;
} LNode;

typedef LNode * LinkStack;

void DisplayElem(SElemType e)
{
    cout << e << "**";
}

void conversion(int n, int r);
bool InitStack_L(LinkStack &s);
void Push_L(LinkStack &s, SElemType &e);
bool StackEmpty_L(LinkStack s);
bool GetTop_L(LinkStack s, SElemType &e);
void StackTraverse_L(LinkStack s, void (*visit)(SElemType));
void DestroyStack_L(LinkStack &s);
void Pop_L(LinkStack &s, SElemType &e);

void StackTraverse_L(LinkStack s, void (*visit)(SElemType)) {
    if (s == NULL) return;
    
    while (s != NULL) {
        visit(s->data);
        s = s->next;
    }
}

bool InitStack_L(LinkStack &s) {
    s = NULL;
    return true;
}

bool StackEmpty_L(LinkStack s) {
    if (s == NULL) return true;
    return false;
}

bool GetTop_L(LinkStack s, SElemType &e) {
    if (s == NULL) return false;

    e = s->data;
    return true;
}

void Push_L(LinkStack &s, SElemType &e) {

    LNode * p = new LNode;
    if (p == NULL) return;
    p->data = e;
    p->next = s;

    s = p;
}

void Pop_L(LinkStack &s, SElemType &e) {
    
    if (s == NULL) return;

    LNode * p = s;
    s = p->next;
    e = p->data;

    delete p;
}

void DestroyStack_L(LinkStack &s) {
    if (s == NULL) return;

    while (s != NULL) {
        LNode * p = s;
        s = p->next;
        delete p;
    }
}

void conversion(int n, int r) {
    LinkStack s;
    InitStack_L(s);
    
    int tmp = n;

    while (n) {
        SElemType t = n % r;
        
        Push_L(s, t);
        n = n / r;
    }
    
    cout << tmp << "转化为" << r << "进制数为：";

    while (!StackEmpty_L(s)) {
        SElemType e;
        Pop_L(s, e);
        cout << e;
    }
}

int main()
{
    LinkStack S;
    int n, i;
    SElemType e;
    if(InitStack_L(S))
        cout << "初始化链栈成功" << endl;
    else {
        cout << "初始化链栈失败" << endl;
        return 1;
    }
    cout << "请输入链栈元素个数：" << endl;
    cin >> n;
    cout << "请输入链栈元素：" << endl;
    for (i=0; i<n; i++) {
        cin >> e;
        Push_L(S, e);
    }
    cout << "栈中元素为";
    if (StackEmpty_L(S))
        cout<<"线性表为空"<<endl;
    else {
        if (GetTop_L(S,e))
            cout << "栈顶元素为" << e << endl;
        //cout << "-------StackTraverse_L(S);------------\n";
        //StackTraverse_L(S);
        //cout << "1" << endl;
        cout << "----StackTraverse_L(S,DisplayElem);---\n";
        StackTraverse_L(S, DisplayElem);
        cout<<endl;
        DestroyStack_L(S);
    }
    int r;
    cout << "将十进制数转化为r(1<r<10)进制数，输入r：" << endl;
    cin >> r;
    cout << "输入要转化的数：" << endl;
    cin >> n;
    conversion(n, r);
    return 0;
}