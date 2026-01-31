#include <bits/stdc++.h>
using namespace std;

int main() {
    int count;
    long long result = 0;
    cin >> count;
    long long arr[count],sum[count],total = 0;
    for (int i = 0;i < count ; i++) {
        cin >> arr[i];
        total += arr[i];
        if (i == 0) {
            sum[i] = arr[i];
            continue;
        }
        sum[i] = sum[i-1] + arr[i];
    }
    for (int i = 0;i < count-1;i++) {
        result += arr[i] * (total - sum[i]);
    }
    cout << result << endl;
    return 0;
}