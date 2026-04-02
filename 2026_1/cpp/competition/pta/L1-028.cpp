#include <iostream>
using namespace std;
typedef long long ll;

bool is_prime(int a) {
    if (a == 2) return true;
    if (a == 1) return false;
    if (a % 2 == 0) return false;
    for (ll i = 3;i * i < a ;i+=2) {
        if (a % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n ;
    cin >> n;
    ll arr[n];
    for (int i = 0;i < n;i++) {
        cin >> arr[i];
    }
    for (ll i : arr) {
        if (is_prime(i)) cout << "Yes" << endl;
        else{
            cout << "No" << endl;
        }
    }
    return 0;
}