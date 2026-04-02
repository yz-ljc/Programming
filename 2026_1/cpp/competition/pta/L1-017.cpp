#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    string N; 
    cin >> N;
    double multiply1 = 1;
    double multiply2 = 1;
    bool needCut1 = false;
    double num2 = 0;
    size_t l1 = N.length();
    if (N[0] == '-') {
        multiply1 += 0.5;
        needCut1 = true;
    }
    if ((N[l1 - 1] - '0') % 2 == 0) multiply2 += 1;
    for (char c : N) {
        if (c == '2') num2++;
    }
    size_t len = needCut1 ? N.length() - 1 : N.length();
    // cout << multiply1<< " " << multiply2 << needCut1 << endl;
    double result = num2 / len * multiply1 * multiply2 * 100;
    cout << fixed << setprecision(2) << result << "%" << endl;
    return 0;
}