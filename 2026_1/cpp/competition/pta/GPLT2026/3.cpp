#include <iostream>
using namespace std;
const int max_age = 250;

int main() {
    int a,b;
    cin >> a >> b;
    int r = b - a;
    if (r > max_age) {
        cout << r << endl;
        cout << "jiu ting tu ran de..." << endl;
    }
    else if (r <= max_age && r > 0) {
        cout << r << endl;
        cout << "nin tai cong ming le!" << endl;
    }
    else{
        cout << r << endl;
        cout << "hai sheng ma?" << endl;
    }
    return 0;
}