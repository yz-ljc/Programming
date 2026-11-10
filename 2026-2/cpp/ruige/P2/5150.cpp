#include <iostream>
#include <iomanip>
using namespace std;
//定义ElemType
typedef int ElemType; 
void ErrorMessage(const char *s);
void PrintElem(ElemType);
//顺序表类型定义

typedef struct LNode {
    ElemType * e;
    int len;
} LNode, *SqList;

//顺序表基本操作函数原型
//顺序表基本操作函数实现

bool InitList_Sq(SqList &A) {
    A = new LNode;
    
    if (A == NULL) return false;
    
    A-> e = NULL;
    A-> len = 0;
    
    return true;
}

bool CreateList_Sq(SqList &A, ElemType * a, int n) {
    if (A == NULL) return false;
    
    ElemType * s = new ElemType[n];
    
    for (int i = 0; i < n; i++) {
        s[i] = a[i];
    }
    
    delete[] A->e;
    A->e = s;
    A->len = n;
    return true;
}

bool ListEmpty_Sq(SqList A) {
    return A->len == 0;
}

int ListLength_Sq(SqList A) {
    return A->len;
}

void ListTraverse_Sq(SqList A, void (*visit)(ElemType)) {
    if (A == NULL) return;
    
    for (int i = 0; i < A->len; i++) {
        visit(A->e[i]);
    }
}

bool MergeList_Sq(SqList A, SqList B, SqList & C) {
    InitList_Sq(C);
    
    C->len = A->len + B->len;
    C->e = new ElemType[C->len];
    
    int i = 0, j = 0, k = 0;
    while (i < A->len && j < B->len) {
        if (A->e[i] <= B->e[j]) {
            C->e[k] = A->e[i];
            i++;
        } else {
            C->e[k] = B->e[j];
            j++;
        }
        k++;
    }
    
    while (i < A->len) {
        C->e[k++] = A->e[i++];
    }
    
    while (j < B->len) {
        C->e[k++] = B->e[j++];
    }
    
    return true;
}

//主函数
int main()
{
    SqList A, B, C;
	int n;
	if(InitList_Sq(A))
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
	if(!CreateList_Sq(A, a, n)) {
		cout<<"线性表A赋值失败"<<endl;
		return 2;
	}
	cout << endl; 
	if(InitList_Sq(B))
		cout<<"初始化线性表B成功"<<endl;
	else {
		cout<<"初始化线性表B失败"<<endl;
		return 3;
	}
	cout << "输入线性表B的元素个数：";
	cin >> n; 
	cout << "输入线性表A的数据元素：";
	ElemType *b = new ElemType[n];
	for (int i=0; i<n; i++)
		cin >> b[i];
	if(!CreateList_Sq(B, b, n)) {
		cout<<"线性表B赋值失败"<<endl;
		return 4;
	}
	cout << endl;
	if(ListEmpty_Sq(A))//检验线性表是否为空
		cout<<"线性表A为空"<<endl;
	else {
		cout<<"线性表A中元素个数为"<<ListLength_Sq(A)<<"，元素为：";//查询线性表中元素个数
		ListTraverse_Sq(A, PrintElem);//遍历
		cout << endl;
	}
	if(ListEmpty_Sq(B))//检验线性表是否为空
		cout<<"线性表B为空"<<endl;
	else {
		cout<<"线性表B中元素个数为"<<ListLength_Sq(B)<<"，元素为：";//查询线性表中元素个数
		ListTraverse_Sq(B, PrintElem);//遍历
		cout << endl;
	}
	if(!MergeList_Sq(A,B,C))
	{
		cout<<"归并线性表A和B失败"<<endl;
		return 3;
	}
	if(ListEmpty_Sq(C))//检验线性表是否为空
		cout<<"线性表C为空"<<endl;
	else {
		cout<<"线性表C中元素个数为"<<ListLength_Sq(C)<<"，元素为：";//查询线性表中元素个数
		ListTraverse_Sq(C, PrintElem);//遍历
		cout << endl;
	}
	return 0;
}
//PrintElem() 函数定义
void PrintElem(ElemType e)
{
    cout << setw(4) << e;
}
void ErrorMessage(const char *s)
{
	cout << s;
}