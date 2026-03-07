#include <iostream>
#include <queue>
using namespace std;

int main() {
    int N,M;
    int count = 0;
    cin >> N >> M;
    queue<int> words;
    for (int i = 0;i < M;i++) {
        int tmp;
        bool found = false;
        cin >> tmp;
        queue<int> temp = words;
        while(!temp.empty()) {
            if (temp.front() == tmp) {
                found = true;
                break;
            }
            temp.pop();
        }
        if (!found) {
            if (words.size() >= N) {
                words.pop();
            }
            words.push(tmp);
            count++;
        }
    }
    cout << count << endl;
    return 0;
}