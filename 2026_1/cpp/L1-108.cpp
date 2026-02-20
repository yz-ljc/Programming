#include <iostream>
using namespace std;

int main(){
    long long money,max = 0;
    cin >> money;
    if (money == 0){
        cout << "0" << endl;
        return 0;
    }
    if (money == 1){
        cout << "1" << endl;
        return 0;
    }
    if (money == 2){
        cout << "2" << endl;
        return 0;
    }
    for (long long i = 2;i <= money;){
        if (i >= max) max = i;
        i *= 2;
    }
    cout << max << endl;
    return 0;
}