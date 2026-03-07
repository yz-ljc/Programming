// 这个玩意叫差分，我他妈怎么知道为啥这么做。学着写呗
#include <bits/stdc++.h>
using namespace std;
int arr[5000001],d[5000001];
int main() {
    int n,p,x,y,z;
    cin >> n >> p;

    for (int i = 1;i <= n;i++) {
        cin >> arr[i];
    }
    for (int i = 1;i <= n;i++) {
        d[i] = arr[i] - arr[i-1];
    }
    for (int i = 1;i <= p;i++) {
        cin >> x >> y >> z;
        d[x] += z;
        d[y+1] -= z;
    }
    int min = 200;
    for (int i = 1;i <= n;i++) {
        arr[i] = arr[i-1] + d[i];
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    cout << min << endl;
    return 0;
}