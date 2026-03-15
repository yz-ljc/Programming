#include <iostream>
#include <iomanip>
using namespace std;
const double pi = 3.1415926;

int main() {
    double r1 = 40;
    double r2 = 928.335;
    double result1 = r1 * r1 * pi;
    double result2 = r2 * r2 * pi;
    cout << setprecision(10);
    cout << "PI: " << setw(10) << pi << " R: " << setw(10) << r1 << " S: " << setw(10) << result1 << endl;
    cout << "PI: " << setw(10) << pi << " R: " << setw(10) << r2 << " S: " << setw(10) << result2 << endl;
    return 0;
}