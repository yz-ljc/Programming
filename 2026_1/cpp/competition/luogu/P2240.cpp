#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int N, T;
    cin >> N >> T;
    double m[N];
    double v[N];
    double rate[N];
    for (int i = 0;i < N;i++) {
        cin >> m[i] >> v[i];
        rate[i] = v[i] / m[i];
    }
    double total = 0;
    double totalm = 0;
    for (int i = 0;i < N;i++) {
        double max = 0;
        int index = 0;
        for (int j = 0;j < N;j++) {
            if (rate[j] > max) {
                max = rate[j];
                index = j;
            }
        }
        rate[index] = 0;
        if (totalm + m[index] <= T) {
            total += v[index];
            totalm += m[index];
        }else{
            total += (T - totalm) * max;
            break;
        }
    }
    cout << fixed << setprecision(2) << total << endl;
    return 0;
}