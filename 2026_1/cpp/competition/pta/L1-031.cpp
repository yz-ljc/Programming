#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;
    double h[N];
    double m[N];
    double std[N];
    for (int i = 0;i < N;i++) {
        cin >> h[i] >> m[i];
        m[i] = m[i] / 2;
        std[i] = (h[i] - 100) * 0.9;
    }
    for (int i = 0;i < N;i++) {
        // cout << m[i] << " " << h[i] << " " << std[i] << endl;
        if (fabs(m[i] - std[i]) < std[i] * 0.1) {
            cout << "You are wan mei!" << endl;
        } else{
            if (m[i] > std[i]) {
                cout << "You are tai pang le!" << endl;
            }
            else{
                cout << "You are tai shou le!" << endl;
            }
        }
    }
    return 0;
}