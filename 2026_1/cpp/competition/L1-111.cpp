#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n,index = 0,sq = 0;
    bool found = false;
    cin >> n;
    for (int i = 1;i < n;i++){
        if (n == 0) break;
        for (int result = 0,j = 1;j < n;j++){
            result += pow(j,i);
            if (result == n){
                found = true;
                index = j;
                sq = i;
                break;
            }
            if ((result + pow(j+1,i)) > n ){
                break;
            }
        }
        if ((1 + pow(2,i)) > n){
            break;
        }
    }
    if (found){
        for (int i = 1;i <= index;i++){
            if (i != 1) cout << "+";
            cout << i << "^" << sq;
        }
    }else{
        cout << "Impossible for " << n << ".";
    }
    return 0;
}