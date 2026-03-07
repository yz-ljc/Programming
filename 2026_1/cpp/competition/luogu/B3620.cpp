#include <bits/stdc++.h>
using namespace std;

int main() {
    int x,result = 0,count = 0;
    cin >> x;
    char strNum[16];
    cin >> strNum;
    char *p = strNum;
    for (;*p != '\0';p++) {
        if (*p > '9') {
            result = result * x + *p - 'A' + 10;
        }else {
            result = result * x + *p - '0';
        }
    }
    cout << result << endl;
    return 0;
}