#include <iostream>
using namespace std;
const int size_num = 10;

void findmax(int (&a)[size_num], int n, int i, int &pk);

int main() {
    int a[size_num];
    int n = 0;
    cout << "please input " << size_num << " datas:\n";
    for (int i = 0;i < size_num;i++) {
        cin >> a[i];
    }

    findmax(a, size_num, 0,n);

    cout << "the maximum is " << a[n] << endl << "It's index is " << n << endl;
    return 0;
}

void findmax(int (&a)[size_num], int n, int i, int &pk) {
    if (i < n) {
        if (a[i] > a[pk]) {
            pk = i;
        }
        findmax(a,n,i+1,pk);
    }
}