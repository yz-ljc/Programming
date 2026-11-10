#include <iostream>
using namespace std;
int g(int, int);
int main()
{
    int m, n;
    cout << "g(m,n)=??\nInput m n: " << endl;
    cin >> m >> n;
    cout << "g(" << m << "," << n << ")=" << g(m,n) << endl;
    return 0;
}

int g(int m, int n) {
    if (m == 0) {
        return 0;
    } else {
        return g(m - 1, 2 * n) + n / 2 + m + 10;
    }
}