#include <iostream>
using namespace std;
const int N = 17;

int main() {
    bool is_left[N] = {false};
    int remain_num = N;
    int total = 0;
    int index = 0;
    while (remain_num != 1) {
        cout << remain_num << " " << total << " " << index << endl;
        if (is_left[index]) {
            index = (index + 1) % N;
            continue;
        }
        total++;
        if (total % 3 == 0) {
            is_left[index] = true;
            remain_num--;
        }
        index = (index + 1) % N;
    }
    for (int i = 0;i < N;i++) {
        if (!is_left[i]) cout << i + 1 << endl;
    }
    return 0;
}
/** 比赛套路
#include <iostream>
using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    int pos = 0;
    for (int i = 2;i <= n;i++) {
        pos = (pos + m) % i;
    }
    cout << pos + 1;
    return 0;
}
*/