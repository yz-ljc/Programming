#include <iostream>
using namespace std;

template<typename ElemType>
bool InitTriplet(ElemType * &T, ElemType e1, ElemType e2, ElemType e3);
template<typename ElemType>
void Traverse(ElemType * T);
template<typename ElemType>
bool Get(ElemType * T, int i, ElemType &e);
template<typename ElemType>
bool Put(ElemType * T, int i, ElemType &e);
template<typename ElemType>
bool IsAscending(ElemType * T);
template<typename ElemType>
bool IsDescending(ElemType * T);
template<typename ElemType>
bool Max(ElemType * T, ElemType &e);
template<typename ElemType>
bool Min(ElemType * T, ElemType &e);
template<typename ElemType>
bool DestroyTriplet(ElemType * &T);

template<typename ElemType>
bool InitTriplet(ElemType * &T, ElemType e1, ElemType e2, ElemType e3) {
	T = new ElemType[3];

	if (!T) return false;

	T[0] = e1;
	T[1] = e2;
	T[2] = e3;
	return true;
}
template<typename ElemType>
void Traverse(ElemType * T) {
	cout << "三元组为：(" << T[0] << "," << T[1] << "," << T[2] << ")\n";
}
template<typename ElemType>
bool Get(ElemType * T, int i, ElemType &e) {
	if (!T) return false;

	int index = i - 1;
	if (index < 0 || index >= 3) return false;

	e = T[index];
	return true;
}
template<typename ElemType>
bool Put(ElemType * T, int i, ElemType &e) {
	if (!T) return false;

	int index = i - 1;
	if (index < 0 || index >= 3) return false;

	T[index] = e;
	return true;
}
template<typename ElemType>
bool IsAscending(ElemType * T) {
	if (!T) return false;

	return (T[0] < T[1] && T[1] < T[2]);
}
template<typename ElemType>
bool IsDescending(ElemType * T) {
	if (!T) return false;

	return (T[0] > T[1] && T[1] > T[2]);
}
template<typename ElemType>
bool Max(ElemType * T, ElemType &e) {
	if (!T) return false;

	e = T[0];
	if (T[1] > e) e = T[1];
	if (T[2] > e) e = T[2];
	return true;
}
template<typename ElemType>
bool Min(ElemType * T, ElemType &e) {
	if (!T) return false;

	e = T[0];
	if (T[1] < e) e = T[1];
	if (T[2] < e) e = T[2];
	return true;
}
template<typename ElemType>
bool DestroyTriplet(ElemType * &T) {
	if (!T) return false;

	delete[] T;
	return true;
}

int main()
{
    int* T1;
    int e1, e2, e3, e;
	cout << "请输入三个元素构造一个三元组（整型）：" << endl;
	cin >> e1 >> e2 >> e3;
	if (InitTriplet(T1, e1, e2, e3))
	{
		cout << "创建成功" << endl;
		Traverse(T1);
	} else {
		cout << "创建失败" << endl;
	    return 1;
	}
	if (IsAscending(T1))
		cout << "三个元素升序排列" << endl;
	else
		cout << "三个元素不是升序排列" << endl;
	if (IsDescending(T1))
		cout << "三个元素降序排列" << endl;
	else
		cout << "三个元素不是降序排列" << endl;
    if (Max(T1, e)) 
		cout << "三个元素最大值为" << e << endl;
	else
		cout << "查询最大值失败" << endl;
    if (Min(T1, e)) 
		cout <<"三个元素最小值为" << e << endl;
	else
		cout <<"查询最小值失败" << endl;
	if (DestroyTriplet(T1))
		cout << "三元组已被销毁" << endl;
	else
		cout << "三元组销毁失败" << endl;
	char* T2;
	char c1, c2, c3, c;
	cout << "请输入三个元素构造一个三元组（字符型）：" << endl;
	cin >> c1 >> c2 >> c3;
	if (InitTriplet(T2, c1, c2, c3))
	{
		cout << "创建成功" << endl;
		Traverse(T2);
	} else {
		cout << "创建失败" << endl;
	    return 1;
	}
	if (IsAscending(T2))
		cout << "三个元素升序排列" << endl;
	else
		cout << "三个元素不是升序排列" << endl;
	if (IsDescending(T2))
		cout << "三个元素降序排列" << endl;
	else 
		cout<< "三个元素不是降序排列" << endl;
    if (Max(T2, c)) 
		cout << "三个元素最大值为" << c << endl;
	else
		cout <<"查询最大值失败" << endl;
    if (Min(T2, c)) 
		cout << "三个元素最小值为" << c << endl;
	else
		cout << "查询最小值失败" << endl;
	if (DestroyTriplet(T2))
		cout << "三元组已被销毁" << endl;
	else
		cout << "三元组销毁失败" << endl;
	double* T3;
	double d1, d2, d3, d;
	cout << "请输入三个元素构造一个三元组（实型）：" << endl;
	cin >> d1 >> d2 >> d3;
	if (InitTriplet(T3,d1,d2,d3))
	{
		cout << "创建成功" << endl;
		Traverse(T3);
	} else {
		cout << "创建失败" << endl;
	    return 1;
	}
	if (IsAscending(T3))
		cout << "三个元素升序排列" << endl;
	else
		cout << "三个元素不是升序排列" << endl;
	if (IsDescending(T3))
		cout << "三个元素降序排列" << endl;
	else
		cout << "三个元素不是降序排列" << endl;
    if (Max(T3,d)) 
		cout << "三个元素最大值为" << d << endl;
	else
		cout << "查询最大值失败" << endl;
    if (Min(T3,d)) 
		cout << "三个元素最小值为" << d << endl;
	else
		cout << "查询最小值失败" << endl;
	if (DestroyTriplet(T3))
		cout << "三元组已被销毁" << endl;
	else
		cout << "三元组销毁失败" << endl;
	return 0;
}