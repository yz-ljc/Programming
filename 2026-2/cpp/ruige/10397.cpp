#include <iostream>
#include <iomanip>
using namespace std;

//定义ElemType
typedef int ElemType;

//顺序表类型定义
typedef struct {
    ElemType *elem;
    int length;
    int listsize;
    int incrementsize;
} LNode, *SqList;

//顺序表基本操作函数原型
bool InitList_Sq(SqList &L, int maxsize, int incresize);
bool CreateList_Sq(SqList L, int n);
bool ListEmpty_Sq(SqList L);
int ListLength_Sq(SqList L);
void ListTraverse_Sq(SqList L, void (*visit)(ElemType));
void Partition_Sq(SqList L);
void PrintElem(ElemType);

//顺序表基本操作函数实现
bool InitList_Sq(SqList &L, int maxsize, int incresize) {
    L = new LNode;
    if (L == NULL) return false;

    L->elem = new ElemType[maxsize];
    L->length = 0;
    L->listsize = maxsize;
    L->incrementsize = incresize;

    return true;
}

bool CreateList_Sq(SqList L, int n) {
    if (L == NULL || n < 0) return false;

    if (n > L->listsize) {
        delete[] L->elem;
        L->elem = new ElemType[n];
        L->listsize = n;
    }

    for (int i = 0; i < n; i++) {
        cin >> L->elem[i];
    }

    L->length = n;
    return true;
}

bool ListEmpty_Sq(SqList L) {
    return L->length == 0;
}

int ListLength_Sq(SqList L) {
    return L->length;
}

void ListTraverse_Sq(SqList L, void (*visit)(ElemType)) {
    for (int i = 0; i < L->length; i++) {
        visit(L->elem[i]);
    }
}

void Partition_Sq(SqList L) {
    if (L->length == 0) return;

    int i = 0, j = L->length - 1;
    ElemType k = L->elem[0];

    while (i < j) {
        while (i < j && L->elem[j] >= k) {
            j--;
        }

        L->elem[i] = L->elem[j];

        while (i < j && L->elem[i] <= k) {
            i++;
        }

        L->elem[j] = L->elem[i];
    }

    L->elem[i] = k;
}

void PrintElem(ElemType);

//主函数
int main()
{
    SqList L;  int n;
    cout<<"------创建线性表L(正序)------"<<endl; //创造一个新线性表
	if(!InitList_Sq(L, 10, 2))
	{
		cout<<"初始化失败"<<endl;
		return 1;
	}
	cout<<"请输入线性表中元素个数："<<endl;
	cin >> n;
	if(CreateList_Sq(L, n))
		cout<<"\n创建完毕,";
	if (!ListEmpty_Sq(L)) {
        cout<<"顺序表中的元素为：";
    	ListTraverse_Sq(L, PrintElem);
    	cout<<"，共有"<<ListLength_Sq(L)<<"项"<<endl;
    	cout<<"---------一次划分L----------"<<endl;
    	Partition_Sq(L);
    	cout << "顺序表L变为：";
    	ListTraverse_Sq(L, PrintElem);
    	cout<<"，共有"<<ListLength_Sq(L)<<"项"<<endl;
	}
	return 0;
}

void PrintElem(ElemType e) {
    cout << setw(4) << e;
}