#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int var1 = 0,var2 = 0;
    int integers[N];
    for (int i = 0;i < N;i++) {
        cin >> integers[i];
        if (integers[i] % 2 == 0) {
            var1++;
        }else{
            var2++;
        }
    }
    cout << var2 << " " << var1 << endl;
    return 0;
}