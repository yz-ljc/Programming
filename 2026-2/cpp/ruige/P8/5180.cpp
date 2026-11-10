#include <iostream>
#include <iomanip>
using namespace std;

const int MAX = 100;
const int OK = 1;
const int ERROR = -1;
typedef int Status;

typedef struct {
    int i, j, e;
} E;

typedef struct {
    E elms[MAX + 1];
    int mu, nu, tu;
} TSMatrix;

void CreateTSMatrix(TSMatrix & T) {
    
    cout << "Input mu nu:";
    cin >> T.mu >> T.nu;
    
    int total = 1;
    while (1) {
        cout << "Input i j e:";
        
        int i, j, e;
        cin >> i >> j >> e;
        
        if (i == -1) break;
        
        T.elms[total].i = i;
        T.elms[total].j = j;
        T.elms[total].e = e;
        total++;
    }
    
    T.tu = total - 1;
}

void PrintTSMatrix(TSMatrix T) {
    cout << "该矩阵是" << T.mu << "*" << T.nu << "的，非零元素个数为" << T.tu << endl;
    cout << "--------------\n";
    cout << "   i   j   e" << endl;
    cout << "--------------\n";
    
    for (int i = 1; i <= T.tu; i++) {
        cout << setw(4) << T.elms[i].i << setw(4) << T.elms[i].j << setw(4) << T.elms[i].e << endl;
    }
    
    cout << "--------------\n";
}

Status TransposeSMatrix(TSMatrix & M1, TSMatrix & M2) {
    M2.tu = M1.tu;
    M2.mu = M1.nu;
    M2.nu = M1.mu;
    
    if (!M2.tu) return ERROR;
    
    int num[MAX];
    int col[MAX];
    
    for (int i = 1; i <= M1.nu; i++) {
        num[i] = 0;
    }
    
    col[1] = 1;
    for (int i = 1; i <= M2.tu; i++) {
        num[M1.elms[i].j] ++;
    }
    
    for (int i = 2; i <= M1.nu; i++) {
        col[i] = col[i - 1] + num[i - 1];
    }
    
    for (int i = 1; i <= M2.tu; i++) {
        int t = col[M1.elms[i].j];
        
        M2.elms[t].j = M1.elms[i].i;
        M2.elms[t].i = M1.elms[i].j;
        M2.elms[t].e = M1.elms[i].e;
        
        col[M1.elms[i].j] ++;
    }
    
    return OK;
}

int main()
{
    TSMatrix M1, M2;  
	cout << "输入一个稀疏矩阵\n";
	CreateTSMatrix(M1);
	cout << "输入完成\n";
	PrintTSMatrix(M1);
	if (TransposeSMatrix(M1, M2) == OK) {
        cout << "转置矩阵\n";
	    PrintTSMatrix(M2);
    }
    else
	    cout << "该矩阵无非零元素" << endl;
	return 0;
}