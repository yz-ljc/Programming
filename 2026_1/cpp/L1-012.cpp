#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long result;
    result = pow(2,n);
    cout << "2^" << n << " = " << result << endl;
    return 0;
}