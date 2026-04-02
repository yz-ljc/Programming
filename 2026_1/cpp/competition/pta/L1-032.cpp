#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    int N;
    char c;
    string str;
    cin >> N >> c;
    cin.ignore(); 
    getline(cin, str);
    if (str.length() <= N) {
        cout << setfill(c) << setw(N) << str << endl;
    } else{
        size_t len = str.length();
        int sub = len - N;
        cout << str.substr(sub);
    }
    return 0;
}