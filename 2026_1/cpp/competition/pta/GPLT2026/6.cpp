#include <iostream>
#include <string>
using namespace std;

int main() {
    string phone[11];
    int n[11];
    for (int i = 0;i < 11;i++) {
        string t = "-";
        getline(cin, t);
        if (t == "\n" || t == "" || t == "-" || t == " ") {
            t = "-";
            phone[i]  = "-";
        }else {
            phone[i] = t;
        }
    }
    for (int i = 0;i < 11;i++) {
        int tmp = phone[i].length();
        if (phone[i] == "-") {
            tmp = 0;
        }
        cout << tmp;
    }
    return 0;
}