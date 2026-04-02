#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

int main() {
    int h;
    int m;
    int time;
    string str;
    cin >> str;
    char c;
    stringstream ss(str);
    ss >> h >> c >> m;
    // cout << h << " " << m << endl;
    time = h * 60 + m;
    if (time <= 720) {
        cout << "Only " << setw(2) << setfill('0') << h << ":" << setw(2) << setfill('0') <<  m << ".  Too early to Dang." << endl;
    } else{
        int hh = h - 12;
        if (m != 0) hh++;
        for (int i = 0;i < hh; i++) {
            cout << "Dang";
        }
    }
    return 0;
}