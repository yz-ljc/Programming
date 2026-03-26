#include <iostream>
using namespace std;

int main() {
    int n = 5;
    int matrix[5][5] = {{42, 17, 83, 56, 29}, {74, 38, 95, 21, 63}, {57, 84, 12, 49, 76}, {31, 68, 45, 92, 18}, {86, 53, 27, 64, 71}};
    int sum1 = 0;
    int sum2 = 0;
    for (int i = 0;i < n;i++) {
        sum1 += matrix[i][i];
    }
    for (int i = 0;i < n;i++) {
        sum2 += matrix[i][n-i-1];
    }
    cout << sum1 + sum2 << endl;
    return 0;
}