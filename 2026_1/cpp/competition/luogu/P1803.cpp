#include <iostream>
#include <algorithm>
using namespace std;

struct match{
    int start;
    int end;
};

inline bool cmp(match a, match b) {
    return a.end < b.end;
}

int main() {
    int n;
    cin >> n;
    struct match m[n];
    int total = 0;
    for (int i = 0;i < n;i++) {
        cin >> m[i].start >> m[i].end;
    }
    sort(m,m+n,cmp);
    int last_end = 0;
    for (int i = 0;i < n;i++) {
        if (m[i].start >= last_end) {
            total++;
            last_end = m[i].end;
        }
    }
    cout << total << endl;
    return 0;
}