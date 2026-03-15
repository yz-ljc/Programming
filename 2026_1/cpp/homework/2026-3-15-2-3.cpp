#include <iostream>
#include <iomanip>
using namespace std;
const double E = 2.718281828;

int main() {
    cout << setprecision(10) << E << endl;
    cout << fixed << setprecision(8) << E << endl;
    cout << scientific << setprecision(8) << E << endl;
    return 0;
}
