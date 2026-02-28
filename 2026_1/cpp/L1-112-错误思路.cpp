#include <iostream>
#include <algorithm>
using namespace std;

/**
 * 这个想法只能过13/20，5个超时2个错误
 * 不会写，似乎需要贪心算法
 */
bool getIndex(int N,int target,int n,int m,int x){
    int r1 = target / m;
    int c1 = target % m;
    int r2 = x / m;
    int c2 = x % m;
    if (r1 == r2 || c1 == c2){
        return true;
    }
    return false;
}

int main(){
    int n,m,k;
    cin >> n >> m >> k;
    int arr[n*m];
    for (int i = 0;i < n*m;i++){
        cin >> arr[i];
    }
    for (int i = 1;i <= k;i++){
        int maxVal = 0,maxIndex = 0;
        for (int j = 0; j < n*m; j++) {
            if (arr[j] > maxVal) {
                maxVal = arr[j];
                maxIndex = j;
            }
        }
        for (int j = 0;j < n*m;j++) {
            bool isBoomed = getIndex(n*m,maxIndex,n,m,j);
            if (isBoomed){
                arr[j] = 0;
            }
        }
    }
    // 下面的是AI思路
    bool hasPrinted = false;
    for (int r = 0; r < n; r++) {
        bool isAllZero = true;
        for (int c = 0; c < m; c++) {
            if (arr[r * m + c] != 0) {
                isAllZero = false;
                break;
            }
        }

        if (isAllZero) continue;
        if (hasPrinted) {
            cout << "\n";
        }

        bool isFirstInRow = true;
        for (int c = 0; c < m; c++) {
            int val = arr[r * m + c];
            if (val != 0) {
                if (!isFirstInRow) cout << " ";
                cout << val;
                isFirstInRow = false;
            }
        }
        hasPrinted = true;
    }
    return 0;
}