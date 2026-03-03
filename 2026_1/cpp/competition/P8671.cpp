#include <iostream>
using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    int pos = 0;
    for (int i = 2;i <= n;i++) {
        pos = (pos + m) % i;
    }
    cout << pos + 1;
    return 0;
}