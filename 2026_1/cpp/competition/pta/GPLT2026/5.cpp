#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// struct P{
//     int inex;
//     bool b;
// };

int main() {
    int n;
    cin >> n;
    bool isGood[100001] = {false};
    bool isRecord[100001] = {false};
    vector<int> index;
    int total = 0;
    // struct P p[n];
    for (int i = 0;i < n;i++) {
        int a,b;
        cin >> a >> b;
        if (b == 1) {
            isGood[a] = true;
        }
        if (b == 0 && !isRecord[a]) {
            index.push_back(a);
            isRecord[a] = true;
            total++;
        }
    }
    sort(index.begin(), index.end());
    if (total == 0) {
        cout << "NONE" << endl;
        return 0;
    }
    int vaild = 0;
    bool isFirst = false;
    for (int i = 0;i < total;i++) {
        if (isGood[index[i]]) continue;
        if (isFirst) cout << " ";
        cout << index[i];
        isFirst = true;
        vaild++;
    }
    if (vaild == 0) {
        cout << "NONE" << endl;
        return 0;
    }
    return 0;
}