#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    getline(cin, str);
    int total = 0;
    for (int i = 0;i < str.length();i++) {
        if (str[i] != ' ') {
            total++;
        }
    }
    cout << total << endl;
    return 0;
}