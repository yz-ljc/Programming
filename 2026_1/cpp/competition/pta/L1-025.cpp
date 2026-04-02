#include <iostream>
#include <string>
using namespace std;

int main() {
    string rawStr;
    string A = "";
    string B = "";
    getline(cin, rawStr);
    bool end = false;
    for (char c : rawStr) {
        if (c == ' ') {
            end = true;
            continue;
        }
        if (!end) A += c;
        else{
            B += c;
        }
    }
    int iA = 0;
    int iB = 0;
    bool canA = true;
    bool canB = true;
    for (char c : A) {
        if (!(c >= '0' && c <= '9')) {
            canA = false;
            break;
        }else{
            iA = iA * 10 + c - '0';
            if (iA > 1000 || iA < 1) canA = false;
        }

    }
    for (char c : B) {
        if (!(c >= '0' && c <= '9')) {
            canB = false;
            break;
        }else{
            iB = iB * 10 + c - '0';
            if (iB > 1000 || iB < 1) canB = false;
        }
    }

    if (canA) {
        cout << iA << " ";
    } else{
        cout << "? ";
    }
    cout << "+" << " ";
    if (canB) {
        cout << iB << " = ";
    } else{
        cout << "? = ";
    }
    if (canA && canB) cout << iA + iB;
    else cout << "?" << endl;
    return 0;
}