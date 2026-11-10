#include <iostream>
using namespace std;

typedef int ElemType;
typedef struct LNode {
    ElemType e;
    struct LNode *next;
} LNode, *LinkList;

void ErrorMessage(const char *); 
void DisplayElem(ElemType);
bool InitList_L(LinkList & L);
bool CreateList_L(LinkList & L, ElemType * a, int n);
int ListLength_L(LinkList L);
void ListTraverse_L(LinkList L, void (*visit)(ElemType));
bool ListEmpty_L(LinkList L);
bool GetElem_L(LinkList L, int i, ElemType & e);
int LocateElem_L(LinkList L, ElemType e);
bool PriorElem_L(LinkList L, ElemType e, ElemType & pe);
bool NextElem_L(LinkList L, ElemType e, ElemType & ne);
bool ListInsert_L(LinkList & L, int i, ElemType &e);
bool ListDelete_L(LinkList & L, int i, ElemType &e);
bool ListDelete_L(LinkList & L, ElemType e);
void InvertList_L(LinkList L);
void ClearList_L(LinkList L);
void DestroyList_L(LinkList L);

void ErrorMessage(const char * s) {
    cout << s << endl;
}

void DisplayElem(ElemType e) {
    cout << e << " ";
}

bool InitList_L(LinkList & L) {
    L = new LNode;
    
    if (L == NULL) return false;
    
    L->next = NULL;
    return true;
}

bool CreateList_L(LinkList & L, ElemType * a, int n) {
    
    LNode * p = L;
    
    for (int i = 0; i < n; i++) {
        LNode * s = new LNode;
        
        if (s == NULL) return false;
        
        s -> e = a[i];
        s -> next = NULL;
        
        p -> next = s;
        p = s;
    }
    
    return true;
}

int ListLength_L(LinkList L) {
    
    LNode * p = L -> next;
    int n = 0;

    while (p != NULL) {
        p = p -> next;
        n++;
    }
    
    return n;
}

void ListTraverse_L(LinkList L, void (*visit) (ElemType)) {
    LNode * p = L -> next;
    
    while (p != NULL) {
        visit(p -> e);
        p = p -> next;
    }
}

bool ListEmpty_L(LinkList L) {
    if (ListLength_L(L) == 0) {
        return true;
    }
    
    return false;
}

bool GetElem_L(LinkList L, int i, ElemType & e) {
    LNode * p = L;
    
    if (i > ListLength_L(L) || i <= 0) return false;
    
    for (int j = 0; j < i; j++) {
        p = p -> next;
    }
    
    e = p -> e;
    return true;
}

int LocateElem_L(LinkList L, ElemType e) {
    LNode * p = L -> next;
    int i = 0;
    
    while (p != NULL) {
        i++;
        if (p -> e == e) {
            return i;
        }
        p = p -> next;
    }
    
    return 0;
}

bool NextElem_L(LinkList L, ElemType e, ElemType & pe) {
    LNode * p = L -> next;
    
    while (p != NULL && p -> next != NULL) {
        if (p -> e == e) {
            pe = (p -> next) -> e;
            return true;
        }
        p = p -> next;
    }
    
    return false;
}

bool PriorElem_L(LinkList L, ElemType e, ElemType & ne) {
    LNode * p = L -> next;
    
    if (p == NULL) return false;
    
    ElemType tmp = p -> e; 
    p = p -> next;    
    
    while (p != NULL) {
        if (p -> e == e) {
            ne = tmp;
            return true;
        }
        tmp = p -> e;
        p = p -> next;
    }
    
    return false;
}

bool ListInsert_L(LinkList & L, int i, ElemType & e) {
    LNode * p = L;
    
    if (i < 1 || i > ListLength_L(L) + 1) {
        ErrorMessage("位序越界!");
        return false;
    }
    
    for (int j = 0; j < i - 1; j++) {
        if (p == NULL) return false;
        p = p -> next;
    }
    
    LNode * s = new LNode;
    
    if (s == NULL) return false;
    
    s -> next = p -> next;
    s -> e = e;
    
    p -> next = s;
    
    return true;
}

bool ListDelete_L(LinkList & L, int i, ElemType & e) {
    LNode * p = L;
    
    if (i < 1 || i > ListLength_L(L)) {
        ErrorMessage("位序越界!");
        return false;
    }
    
    for (int j = 0; j < i -1; j++) {
        p = p -> next;
    }
    
    LNode * q = p -> next;
    e = q -> e;
    p -> next = q -> next;
    
    delete q;
    
    return true;
}

bool ListDelete_L(LinkList & L, ElemType e) {
    LNode * p = L;
    
    while (p != NULL && (p -> next != NULL) && (p -> next) -> e != e) {
        p = p -> next;
    }
    
    if (p == NULL || p -> next == NULL) return false;
    
    LNode * q = p -> next;
    p -> next = q -> next;
    
    delete q;
    
    return true;
}

void InvertList_L(LinkList L) {
    LNode * p = L -> next;
    
    L -> next = NULL;
    
    while (p != NULL) {
        LNode * q = p -> next;
        p -> next = L -> next;
        L -> next = p;
        
        p = q;
    }
}

void ClearList_L(LinkList L) {
    LNode * p = L -> next;
    LNode * q;
    
    while (p != NULL) {
        q = p -> next;
        delete p;
        p = q;
    }
    
    L -> next = NULL;
}
void DestroyList_L(LinkList L) {
        LNode * p = L -> next;
    LNode * q;
    
    while (p != NULL) {
        q = p -> next;
        delete p;
        p = q;
    }
    
    delete L;
}

int main()
{
	LinkList L;
	int n, i;
	ElemType e;
	if(InitList_L(L))
		cout <<"初始化线性表成功" << endl;
	else
	{
		cout << "初始化线性表失败" << endl;
		return 1;
	}
	cout << "输入线性表的元素个数：";
	cin >> n;
	if (n > 0) {
		ElemType *a = new ElemType[n];
		cout << "输入线性表的数据元素：";
		for (int i=0; i<n; i++)
			cin >> a[i];
		if (!CreateList_L(L, a, n)) {
			cout << "线性表创建失败" << endl;
			return 2;
		}
	}
	if (ListEmpty_L(L)) //检验线性表是否为空
		cout << "线性表为空" << endl;
	else {
		cout << "线性表不为空" << endl;
		cout << "线性表的元素个数为" << ListLength_L(L) << endl;//查询线性表中元素个数
		cout << "线性表的元素为：";
		ListTraverse_L(L, DisplayElem); //遍历
		cout << endl;
	}
	//查询指定位序元素
	cout << "请输入要查询的线性表的位序：" << endl;
	cin >> i;
	if (GetElem_L(L, i, e))
		cout << "线性表中第" << i << "个元素为" << e << endl;
	else 
		cout << "位序越界" << endl;
	//查询元素在线性表中的位序 
	cout << "请输入要查询的元素：" << endl;//查询指定元素位序
    cin >> e;
	int orderID;
	if (orderID = LocateElem_L(L,e))
		cout << "线性表中元素" << e << "为第" << orderID << "个"<<endl;
	else
		cout << "输入元素未在表中" << endl;
	//查找前驱	
	cout << "请输入要查询前驱的元素：" << endl;
	cin >> e;
	ElemType Pre;
	if(PriorElem_L(L, e, Pre))
		cout << "线性表中元素" << e << "的前驱为" << Pre << endl;
	else
		cout << "未在表中找到前驱" << endl;
	//查找后继
	cout << "请输入要查询后继的元素：" << endl;
	cin >> e;
	ElemType Ne;
	if(NextElem_L(L, e, Ne))
		cout << "线性表中元素" << e << "的后继为" << Ne << endl;
	else
		cout << "未在表中找到后继" << endl;
	//测试在链表的第i个元素前插入元素e 
	cout << "请输入线性表插入元素的位序及插入元素值：" << endl;//查询指定位序元素
	cin >> i >> e;
	if(ListInsert_L(L, i, e)) {
		cout << "线性表插入元素成功" << endl;
		cout << "线性表中元素个数为" << ListLength_L(L) << endl;//查询线性表中元素个数
		cout << "线性表的元素为：";
		ListTraverse_L(L, DisplayElem);//遍历
		cout << endl;
	}
	else
		cout << "线性表插入元素失败" << endl;
	//删除L中第m个元素 
	if (!ListEmpty_L(L)) {
		cout << "请输入删除元素的位序：" << endl;//查询指定位序元素
		cin >> i;
		if(ListDelete_L(L,i,e)) {
			cout << "线性表删除元素成功" << endl;
			cout << "线性表中元素个数为" << ListLength_L(L) << endl;//查询线性表中元素个数
			cout << "线性表的元素为：";
			ListTraverse_L(L, DisplayElem); //遍历
			cout << endl;
		}
	}
	//删除L中的元素 e
	if (!ListEmpty_L(L)) {
		cout << "请输入删除元素：" << endl;//查询指定位序元素
		cin >> e;
		if(ListDelete_L(L, e)) {
			cout << "线性表删除元素成功" << endl;
			cout << "线性表中元素个数为" << ListLength_L(L) << endl;//查询线性表中元素个数
			cout << "线性表的元素为：";
			ListTraverse_L(L, DisplayElem); //遍历
			cout << endl;
		}
		else 
			cout << "删除元素未在表中" << endl;
	}
	//逆置线性表
	InvertList_L(L);
	if (!ListEmpty_L(L)) {
		cout << "线性表已逆置" << endl;
		cout << "线性表中元素个数为" << ListLength_L(L) << endl;//查询线性表中元素个数
		cout << "线性表的元素为：";
		ListTraverse_L(L, DisplayElem); //遍历
		cout << endl;
	}
	//清空线性表 
	ClearList_L(L);
	if (ListEmpty_L(L)) {
		cout << "线性表已置空" << endl;
	}
	//销毁线性表 
	DestroyList_L(L);
	cout << "线性表已销毁" << endl;
	return 0;
}
//ErrorMessage()的实现
//DisplayElem()的实现
/******************Linklist.cpp*****************
           链表的基本操作的函数实现 
***********************************************/
//#include "LinkList.h"
//初始化链表 
//正序（尾插法）建立链表L
//判断链表L是否为空 
// 求链表L的长度
//遍历链表L
//查找元素e的位序，不存在返回0
//查找链表的第m个元素，不存在返回false
//在链表的第m个结点之前插入值为e的元素
//删除链表L的第m个元素，其值赋给e。
//删除链表L中值为e的元素
//查找值为 e的元素的前驱 
//查找值为 e的元素的后继 
//清空线性表
//销毁线性表
//逆置链表