#include <bits/stdc++.h>
using namespace std;

int main() {
    int a,b,c,d,M;
    cin >> a >> b >> c >> d >> M;
    int result;
    if (5*c <= M) {
        result = 5*c - (b-d)*20;
    }else {
        result = 5*c + d*20 - (b-d)*20;
    }
    if (result < 0) {
        result = 0;
    }
    cout << result;
    return 0;
}