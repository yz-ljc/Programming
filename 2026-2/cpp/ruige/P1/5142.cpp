#include <iostream>
using namespace std;

typedef int ElemType;
typedef int * Triplet;

bool InitTriplet(Triplet &T, ElemType e1, ElemType e2, ElemType e3);
void Traverse(Triplet T);
bool Get(Triplet T, int i, ElemType &e);
bool Put(Triplet T, int i, ElemType &e);
bool IsAscending(Triplet T);
bool IsDescending(Triplet T);
bool Max(Triplet T, ElemType &e);
bool Min(Triplet T, ElemType &e);
bool DestroyTriplet(Triplet &T);

bool InitTriplet(Triplet &T, ElemType e1, ElemType e2, ElemType e3) {
    T = new ElemType[3];
    
    if (!T) return false;
    
    T[0] = e1;
    T[1] = e2;
    T[2] = e3;
    return true;
}

void Traverse(Triplet T) {
    cout << "三元组为：(" << T[0] << "," << T[1] << "," << T[2] << ")\n";
}

bool Get(Triplet T, int i, ElemType &e) {
    if (!T) return false;
    
    int index = i - 1;
    if (index < 0 || index >= 3) return false;
    
    e = T[index];
    return true;
}

bool Put(Triplet T, int i, ElemType &e) {
    if (!T) return false;
    
    int index = i - 1;
    if (index < 0 || index >= 3) return false;
    
    T[index] = e;
    return true; 
}

bool IsAscending(Triplet T) {
    if (!T) return false;
    
    return (T[0] < T[1] && T[1] < T[2]);
}

bool IsDescending(Triplet T) {
    if (!T) return false;
    
    return (T[0] > T[1] && T[1] > T[2]);  
}

bool Max(Triplet T, ElemType &e) {
    if (!T) return false;
    
    e = T[0];
    if (T[1] > e) e = T[1];
    if (T[2] > e) e = T[2];
    return true;
}

bool Min(Triplet T, ElemType &e) {
    if (!T) return false;
    
    e = T[0];
    if (T[1] < e) e = T[1];
    if (T[2] < e) e = T[2];
    return true;
}

bool DestroyTriplet(Triplet &T) {
    if (!T) return false;
    
    delete[] T;
    return true;
}
//ElemType的类型定义
//三元组类型定义
//三元组基本操作函数声明
//三元组基本操作函数定义
int main()
{
    cout<<"请输入三个元素构造一个三元组："<<endl;
	ElemType e1,e2,e3;
	cin>>e1>>e2>>e3;
	Triplet T;
	if(InitTriplet(T,e1,e2,e3))
	{
		cout<<"创建成功"<<endl;
		Traverse(T);
	}
	else
	{
		cout<<"创建失败"<<endl;
	    return 1;
	}
	cout<<"请输入整数i来查询第i个元素(1<=i<=3)："<<endl;
	int i;
	cin>>i;
	ElemType e;
	if(!Get(T,i,e))
		cout<<"查询失败"<<endl;
	else
	{
		cout<<"第"<<i<<"个数为"<<e<<endl;
	}
	cout<<"请输入要改变的元素i及改变后的数值e："<<endl;
	cin>>i>>e;
	if(!Put(T,i,e))
		cout<<"改变失败"<<endl;
	else
	{
		cout<<"改变成功"<<endl;
		Traverse(T);
	}
	if(IsAscending(T))
		cout<<"三个元素升序排列"<<endl;
	else
		cout<<"三个元素不是升序排列"<<endl;
	if(IsDescending(T))
		cout<<"三个元素降序排列"<<endl;
	else
		cout<<"三个元素不是降序排列"<<endl;
    if(Max(T,e)) 
		cout<<"三个元素最大值为"<<e<<endl;
	else
		cout<<"查询最大值失败"<<endl;
    if(Min(T,e)) 
		cout<<"三个元素最小值为"<<e<<endl;
	else
		cout<<"查询最小值失败"<<endl;
	if(DestroyTriplet(T))
		cout<<"三元组已被销毁"<<endl;
	else
		cout<<"三元组销毁失败"<<endl;
        /*下面是类的方式
    cout<<"请输入三个元素构造一个三元组："<<endl;
    int e1, e2, e3;
	cin >> e1 >> e2 >> e3;
	Triplet T;
	try {
		T.Init(e1, e2, e3);
	}
	catch (int) {
		cout<<"内存不足，三元组创建失败"<<endl;
		return 1;
	}
	cout<<"创建成功"<<endl;
	T.Traverse();
	cout <<"请输入整数i来查询第i个元素(1<=i<=3)："<<endl;
	int i;
	cin >> i;
	int e;
	if (!T.Get(i, e))
		cout<<"查询失败"<<endl;
	else {
		cout<<"第"<<i<<"个数为"<<e<<endl;
	}
	cout<<"请输入要改变的元素i及改变后的数值e："<<endl;
	cin >> i >> e;
	if (!T.Put(i, e))
		cout<<"改变失败"<<endl;
	else {
		cout<<"改变成功"<<endl;
		T.Traverse();
	}
	if (T.IsAscending())
		cout<<"三个元素升序排列"<<endl;
	else
		cout<<"三个元素不是升序排列"<<endl;
	if (T.IsDescending())
		cout<<"三个元素降序排列"<<endl;
	else
		cout<<"三个元素不是降序排列"<<endl;
    if (T.Max(e)) 
		cout<<"三个元素最大值为"<<e<<endl;
	else
		cout<<"查询最大值失败"<<endl;
    if (T.Min(e)) 
		cout<<"三个元素最小值为"<<e<<endl;
	else
		cout<<"查询最小值失败"<<endl;
    if (T.Destroy()) 
        cout<<"三元组已被销毁！"<<endl;
    */
	return 0;
}