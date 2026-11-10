#include <iostream>
using std::cin;
using std::cout;
using std::endl;
void ErrorMessage(const char *s);

typedef int ElemType;
struct SqList {
    ElemType * List;
    int length;
};

bool InitList_Sq(SqList & L);
bool CreateList_Sq(SqList & L, int i);
bool ListEmpty_Sq(SqList L);
void ListTraverse_Sq(SqList L);
bool GetElem_Sq(SqList L, int i, ElemType & e);
int LocateElem_Sq(SqList L, ElemType e);
bool PriorElem_Sq(SqList L, ElemType var1, ElemType &var2);
bool NextElem_Sq(SqList L, ElemType var1, ElemType &var2);
bool ListInsert_Sq(SqList &L, int i, ElemType e);
bool ListDelete_Sq(SqList &L, int i, ElemType e);
int ListLength_Sq(SqList L);
bool ListEmpty_Sq(SqList L); // list.isEmpty(), checkable func
void ClearList_Sq(SqList &L);
void DestroyList_Sq(SqList &L);

bool InitList_Sq(SqList & L) {
    L.List = new ElemType[1];
    if (L.List == NULL) return false;
    
    L.length = 0;
    return true;
}

bool CreateList_Sq(SqList & L, int i) {
    delete[] L.List;
    L.length = 0;
    
    L.List = new ElemType[i];
    
    if (L.List == NULL) return false;
    cout << "请输入各元素：";
    for (int k = 0; k < i; k++) {
        cin >> L.List[k];
    }
    
    L.length = i;
    return true;
}

bool ListEmpty_Sq(SqList L) {
    if (L.length == 0) return true;
    return false;
}

void ListTraverse_Sq(SqList L) {
    for (int i = 0; i < L.length; i++) {
        if (i != 0) cout << " ";
        cout << L.List[i];
    }
    cout << "\n";
}

bool GetElem_Sq(SqList L, int i, ElemType & e) {
    if (i > L.length || i <= 0) return false;
    
    e = L.List[i - 1];
    return true;
}

int LocateElem_Sq(SqList L, ElemType e) {
    for (int i = 0; i < L.length; i++) {
        if (L.List[i] == e) {
            return i + 1;
        }
    }
    return 0;
}

bool PriorElem_Sq(SqList L, ElemType var1, ElemType &var2) {
    
    for (int i = 0; i < L.length; i++) {
        if (var1 == L.List[0]) return false;
        
        if (i + 1 >= L.length) continue;
        
        if (L.List[i + 1] == var1) {
            var2 = L.List[i];
            return true;
        }
    }
    
    return false;
}

bool NextElem_Sq(SqList L, ElemType var1, ElemType &var2) {
    
    for (int i = 0; i < L.length; i++) {
        if (L.List[L.length - 1] == var1) return false;
        
        if (i - 1 < 0) continue;
        
        if (L.List[i - 1] == var1) {
            var2 = L.List[i];
            return true;
        }
    }
    
    return false;
}

bool ListInsert_Sq(SqList &L, int i, ElemType e) {
    
    if (i > L.length) return false;
    
    ElemType* tmp = new ElemType[L.length];
    int length = L.length;
    
    for (int t = 0; t < length; t++) {
        tmp[t] = L.List[t];
    }
    
    delete[] L.List;
    L.List = new ElemType[length + 1];
    
    if (L.List == NULL) return false;
    
    for (int k = 0; k < i - 1; k++) {
        L.List[k] = tmp[k];
    }
    
    L.List[i - 1] = e;
    
    for (int k = i; k < length + 1; k++) {
        L.List[k] = tmp[k - 1];
    }
    
    L.length = length + 1;
    
    delete[] tmp;
    return true;
}

bool ListDelete_Sq(SqList &L, int i, ElemType e) {
    
    if (i > L.length) return false;
    
    ElemType* tmp = new ElemType[L.length];
    int length = L.length;
    
    for (int t = 0; t < length; t++) {
        tmp[t] = L.List[t];
    }
    
    delete[] L.List;
    L.List = new ElemType[length - 1];
    
    if (L.List == NULL) return false;
    
    for (int k = 0; k < i - 1; k++) {
        L.List[k] = tmp[k];
    }
    
    for (int k = i; k < length; k++) {
        L.List[k - 1] = tmp[k];
    } 
    
    L.length = length - 1;
    
    delete[] tmp;
    return true;    
}

int ListLength_Sq(SqList L) {
    return L.length;
}

void ClearList_Sq(SqList &L) {
    L.length = 0;
}
void DestroyList_Sq(SqList &L) {
    delete[] L.List;
}


//定义ElemType
//顺序表类型定义
//顺序表基本操作函数原型
//顺序表基本操作函数实现
//主函数
int main()
{
    SqList L;
	int n,i;
	ElemType e;
	if(InitList_Sq(L))
		cout <<"初始化线性表成功" << endl;
	else
	{
		cout << "初始化线性表失败" << endl;
		return 1;
	}
	cout << "请输入线性表中元素个数：" << endl;
	cin >> n;
	if(!CreateList_Sq(L,n))
	{
		cout << "线性表赋值失败" << endl;
		return 2;
	}
	if(ListEmpty_Sq(L))//检验线性表是否为空
		cout << "线性表为空" << endl;
	else
	{
		cout << "线性表不为空"<<endl;
		cout << "线性表中元素个数为"<<ListLength_Sq(L) << endl;//查询线性表中元素个数
		ListTraverse_Sq(L);//遍历
		cout << "请输入要查询的线性表元素的位序：" << endl;//查询指定位序元素
		cin >> i;
		if(GetElem_Sq(L,i,e))
			cout << "线性表中第" << i << "个元素为" << e << endl;
		else
			cout << "输入位序超过线性表长度" << endl;
		cout << "请输入要查询的元素：" << endl;//查询指定元素位序
		cin >> e;
		int orderID;
		if(orderID=LocateElem_Sq(L,e))
			cout << "线性表中元素" << e << "为第" << orderID << "个"<<endl;
		else
			cout << "输入元素未在表中"<<endl;
		cout << "请输入要查询前驱的元素：" << endl;//查找前驱
		ElemType Pe;
		cin >> e;
		if(PriorElem_Sq(L,e,Pe))
			cout << "线性表中元素" << e << "的前驱为" << Pe << endl;
		else
			cout << "输入元素未在表中找到前驱" << endl;
		cout << "请输入要查询后继的元素：" << endl;//查找后继
		ElemType Ne;
		cin >> e;
		if(NextElem_Sq(L,e,Ne))
			cout << "线性表中元素" << e << "的后继为" << Ne << endl;
		else
		cout << "输入元素未在表中找到后继" << endl;
	}
	cout << "请输入线性表插入元素的位序及插入元素值：" << endl;//查询指定位序元素
	cin >> i >> e;
	if(ListInsert_Sq(L,i,e))
	{
		cout << "线性表插入元素成功" << endl;
		cout << "线性表中元素个数为" << ListLength_Sq(L) << endl;//查询线性表中元素个数
		ListTraverse_Sq(L);//遍历
	}
	else
		cout<<"线性表插入元素失败"<<endl;
	if(!ListEmpty_Sq(L))//检验线性表是否为空
	{
		cout << "请输入线性表删除元素的位序：" << endl;//查询指定位序元素
		cin >> i;
		if(ListDelete_Sq(L,i,e))
		{
			cout << "线性表删除元素成功" << endl;
			cout << "线性表中元素个数为" << ListLength_Sq(L) << endl;//查询线性表中元素个数
			ListTraverse_Sq(L);//遍历
		}
	}
	if(!ListEmpty_Sq(L))//检验线性表是否为空
	{
		ClearList_Sq(L);
		cout << "线性表已置空" << endl;
	}
	DestroyList_Sq(L);
	cout << "线性表已销毁" << endl;
	return 0;
}
void ErrorMessage(const char *s)
{
	cout << s;
}