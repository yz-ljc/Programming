#include <iostream>
using namespace std;
/***********************user.h****************
     与具体应用相关的数据定义及函数说明 
*********************************************/
//ElemType的类型定义
typedef int ElemType;
typedef struct LNode {
    ElemType data;
    LNode * next;
} LNode, *LinkList;
//相关函数说明 
void ErrorMessage(const char *); 
void DisplayElem(ElemType);

bool InitList_L(LinkList & L);
bool CreateList_L_Head(LinkList & L, ElemType *a, int n);
bool ListEmpty_L(LinkList & L);
void ListTraverse_L(LinkList L, void (*visit)(ElemType));
bool MergeList_L(LinkList & A, LinkList & B, LinkList & C);
int ListLength_L(LinkList C);

void ErrorMessage(const char *s) {
    cout << s << endl;
}

void DisplayElem(ElemType e) {
    cout << e << " ";
}

bool InitList_L(LinkList & L) {
    L = new LNode;
    if (L == NULL)
    return false;
    
    L->next = NULL;
    return true;
}

bool CreateList_L_Head(LinkList & L, ElemType *a, int n) {
    if (L == NULL || n < 0) return false;
    
//    LNode * s = new LNode;
//    if (s == NULL) return false;
//    
//    LNode * p = s;
    
    for (int i = n - 1; i >= 0; i--) {
        LNode * t = new LNode;
        t->data = a[i];
        t->next = L->next;
        L->next = t;
    }
    
    return true;
}

bool ListEmpty_L(LinkList & L) {
    if (L->next == NULL) return true;
    return false;
}
void ListTraverse_L(LinkList L, void (*visit)(ElemType)) {
    LNode *p = L->next;
    
    while (p != NULL) {
        visit(p->data);
        p = p->next;
    }
}

bool MergeList_L(LinkList & A, LinkList & B, LinkList & C) {
    
    LNode * a = A->next;
    LNode * b = B->next;
    
    C = new LNode;
    C->next = NULL;
    
    LNode * c = C;
    
    while (a != NULL && b != NULL) {
        if (a->data >= b->data) {
            LNode * t = b;
            c->next = t;
            b = t->next;
            c = t;
        } else {
            LNode * t = a;
            c->next = t;
            a = t->next;
            c = t;
        }
    }
    
    while (a != NULL) {
            LNode * t = a;
            c->next = t;
            a = t->next;
            c = t;
    }
    
    while (b != NULL) {
            LNode * t = b;
            c->next = t;
            b = t->next;
            c = t;
    }
    
    return true;
}

int ListLength_L(LinkList C) {
    int i = 0;
    LNode * p = C->next;
    
    while (p != NULL) {
        i++;
        p = p->next;
    }
    
    return i;
}


int main()
{
    //测试MergeList_L()
	LinkList A, B, C;
	int n;
	if(InitList_L(A))
		cout<<"初始化线性表A成功"<<endl;
	else {
		cout<<"初始化线性表A失败"<<endl;
		return 1;
	}
	cout << "输入线性表A的元素个数：";
	cin >> n; 
	cout << "输入线性表A的数据元素：";
	ElemType *a = new ElemType[n];
	for (int i=0; i<n; i++)
		cin >> a[i];
	if(!CreateList_L_Head(A, a, n)) {
		cout<<"线性表A赋值失败"<<endl;
		return 2;
	}
	cout << endl; 
	if(InitList_L(B))
		cout<<"初始化线性表B成功"<<endl;
	else {
		cout<<"初始化线性表B失败"<<endl;
		return 3;
	}
	cout << "输入线性表B的元素个数：";
	cin >> n; 
	cout << "输入线性表B的数据元素：";
	ElemType *b = new ElemType[n];
	for (int i=0; i<n; i++)
		cin >> b[i];
	if(!CreateList_L_Head(B, b, n)) {
		cout<<"线性表B赋值失败"<<endl;
		return 4;
	}
	cout << endl;
	if(ListEmpty_L(A))//检验线性表是否为空
		cout<<"线性表A为空"<<endl;
	else {
		cout << "线性表A中元素个数为" << ListLength_L(A) << "，";//查询线性表中元素个数
		cout << "线性表的元素为：";
		ListTraverse_L(A, DisplayElem);//遍历
		cout << endl;
	}
	if(ListEmpty_L(B))//检验线性表是否为空
		cout<<"线性表B为空"<<endl;
	else {
		cout << "线性表B中元素个数为" << ListLength_L(B) << "，";//查询线性表中元素个数
		cout << "线性表的元素为：";
		ListTraverse_L(B, DisplayElem);//遍历
		cout << endl;
	}
    if(MergeList_L(A, B, C)) {
    	if(ListEmpty_L(C))//检验线性表是否为空
    		cout<<"线性表C为空"<<endl;
    	else {
    		cout << "线性表C中元素个数为" << ListLength_L(C) << "，";//查询线性表中元素个数
    		cout << "线性表的元素为：";
    		ListTraverse_L(C, DisplayElem);//遍历
    		cout << endl;
    	}
    }
	return 0;
}