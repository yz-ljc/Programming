#include <bits/stdc++.h>
using namespace std;

int main() {
    int num,result = 0;
    cin >> num;
    for (int i = 1;i < num;i++) {
        for (int j = i;j < num;j++) {
            result += j;
            if (result == num) {
                cout << i << " " << j << endl;
                result = 0;
                break;
            }
            if (result > num) {
                result = 0;
                break;
            }
        }
    }
    return 0;
}