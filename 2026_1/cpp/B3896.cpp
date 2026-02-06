#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n,a,k,b;
    cin >> n >> a >> k >> b;
    if (n % 2 != 0) {
        cout << -1;
        return 0;
    }
    const long long tmp = n / 2;
    long long hand = 0,car = 0,result_hand,result_car,result = 0,min = LLONG_MAX;
    for (long long i = 0;i <= tmp / k;i++) {
        car = i;
        hand = tmp - car * k;
        if (car * k <= tmp - hand && (car + 1) * k >= tmp) {
            long long stamina_hand = hand * a;
            long long stamina_car = 1 * b;
            if (stamina_car < stamina_hand) {
                car++;
                hand = 0;
            }
        }
        result_hand = hand * a;
        result_car = car * b;
        result = result_car + result_hand;
        if (min > result) min = result;
    }
    cout << min * 2 << endl;
    return 0;
}