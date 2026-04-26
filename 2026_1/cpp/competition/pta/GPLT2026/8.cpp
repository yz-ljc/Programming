#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    int maxer = 0;
    int miner = 1000000;
    int record[1001];
    vector<int> finals;
    vector<int> h;
    long long total = 0;
    for (int i = 0;i < n;i++) {
        int tmp;
        cin >> tmp;
        record[i] = tmp;
        if (tmp > maxer) {
            maxer = tmp;
        }
        if (tmp < miner) {
            miner = tmp;
        }
        total += tmp;
    }
    int avg = total / n * 2;
    for (int i = 0;i < n; i++) {
        if (record[i] > avg) {
            finals.push_back(record[i]);
            h.push_back(i + 1);
        }
    }
    cout << maxer << " " << miner << " " << avg / 2 << endl;
    if (!h.size()) {
        cout << "Normal" << endl;
        return 0;
    }
    bool isFirst = false;
    for (int a : h) {
        if (isFirst) cout << " ";
        cout << a;
        isFirst = true;
    }
    return 0;
}