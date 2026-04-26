#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Homework{
    int index;
    int c;
};

int main() {
    int n,T;
    cin >> n >> T;
    vector<int> q;
    struct Homework h[n];
    for (int i = 0;i < n;i++) {
        h[i].index = i + 1;
        cin >> h[i].c;
    }
    int avg = T;
    int remain = n;
    bool checked[1001] = {false};
    int no = 1;
    vector<int> home;
    while(remain > 0) {
        int total = 0;
        int left = 0;
        if (no % 2 == 1) {
            for (int i = 0;i < n;i++) {
                if (checked[h[i].index]) continue;
                if (h[i].c > avg) {
                    total += h[i].c;
                    left ++;
                    home.push_back(i);
                } else{
                    q.push_back(h[i].index);
                    checked[h[i].index] = true;
                }
            }
        } else{
            for (int j = home.size() - 1 ;j >= 0;j--) {
                int i = home[j];
                if (checked[h[i].index]) continue;
                if (h[i].c > avg)  {
                    total += h[i].c;
                    left ++;
                    home.push_back(i);
                } else{
                    q.push_back(h[i].index);
                    checked[h[i].index] = true;
                }
            }
            home.clear();
        }
        if (left == 0) break;
        avg = total / left;
        remain = left;
        no++;
    }
    bool isFirst = false;
    for (int a : q) {
        if (isFirst) cout << " ";
        cout << a;
        isFirst = true;
    }
    return 0;
}