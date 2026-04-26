#include <iostream>
using namespace std;

struct Pro{
    int index;
    int score;
};

int main() {
    int n;
    cin >> n;
    struct Pro p[n];
    for (int i = 0;i < n;i++) {
        p[i].index = i;
        cin >> p[i].score;
    }
    int m;
    cin >> m;
    int stdd[m];
    for (int i = 0;i < m;i++) {
        cin >> stdd[i];
    }
    for (int i = 0;i < m;i++) {
        bool f = false;
        bool h = false;
        int maxer = 1e-8;
        for (int j = 0;j < n;j++) {
            if (p[j].score > stdd[i]) {
                if (p[j].score < maxer)
                    h = true;
                f = true;
            }
        }
        if (!h) cout << 0;
        else{
            cout << maxer;
        }
        cout << "\n";
    }
    return 0;
}