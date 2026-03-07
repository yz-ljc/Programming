#include <iostream>
using namespace std;

int main() {
    double n;
    char c;
    cin >> n >> c;
    int lines;
    if  (n / 2 >= (int)n/2+0.5){
        lines = (int)n/2 +1;
    }else{
        lines = (int)n/2;
    }
    for (int i = 0;i < lines;i++) {
        for (int i = 0;i < n;i++) {
            cout << c;
        }
        cout << "\n";
    }
    return 0;
}