#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct S{
    int sex;
    string name;
    bool selected;
};

int main() {
    int N;
    cin >> N;
    struct S s[N];
    vector<string> g;
    for (int i = 0;i < N;i++) {
        cin >> s[i].sex >> s[i].name;
        s[i].selected = false;
    }
    int t = 0;
    for (int i = 0;i < N;i++) {
        if (s[i].selected) continue;
        for (int j = N-1;j > 0;j--) {
            if (s[j].selected || s[i].selected) continue;
            if (s[i].sex != s[j].sex) {
                g.push_back(s[i].name + " " + s[j].name);
                s[i].selected = true;
                s[j].selected = true;
                t++;
            }
        }
    }
    for (string s1 : g) {
        cout << s1 << endl;
    }
    return 0;
}