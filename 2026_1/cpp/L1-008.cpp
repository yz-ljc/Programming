#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int a,b,sum = 0;
    cin >> a >> b;
    int total = b - a + 1;
    for (int i = 0;i < total;i++){
        if (i % 5 == 0 && i != 0) cout << "\n";
        cout << setw(5) << a + i;
        sum += a + i;
    }
    cout << "\n";
    cout << "Sum = " << sum << endl;
    return 0;
}