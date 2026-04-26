#include <iostream>
using namespace std;
const int s = 1700;

int main() {
    int n;
    cin >> n;
    int total = 0;
    for (int i = 0;i < n;i++) {
        int tmp;
        cin >> tmp;
        if (tmp < s) {
            total++;
        }
    }
    cout << total << endl;
    return 0;
}