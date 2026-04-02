#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double H;
    cin >> H;
    double result = (H - 100) * 0.9 * 2;
    cout << fixed << setprecision(1) << result << endl;
    return 0;
}