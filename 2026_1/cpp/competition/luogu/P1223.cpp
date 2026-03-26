#include <iostream>
#include <iomanip>
using namespace std;

struct users{
    int uid;
    int time;
};

int main() {
    int n;
    cin >> n;
    struct users u[n];
    double total_time = 0;
    double player[n];
    int index[n];
    for (int i = 0;i < n;i++) {
        u[i].uid = i;
        cin >> u[i].time;
    }
    for (int i = 0;i < n;i++) {
        int min = 1000001;
        int k = 0;
        for (int j = 0;j < n;j++) {
            if (u[j].time < min || (u[j].time == min && u[j].uid < u[k].uid)) {
                min = u[j].time;
                k = j;
            }
        }
        u[k].time = 1000001;
        total_time += min;
        player[i] = total_time;
        index[i] = k;
    }
    for (int i = 0;i < n;i++) {
        if (i != 0) cout << " ";
        cout << index[i] + 1;
    }
    cout << endl;
    double result = 0;
    for (int i = 0;i < n -1;i++) {
        result += player[i];
    }
    cout << fixed << setprecision(2) << result / (double)n << endl;
    return 0;
}