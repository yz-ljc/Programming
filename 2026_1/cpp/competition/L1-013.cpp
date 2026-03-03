#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int result = 0;
    int tmp = 1;
    for (int i = 1;i <= N;i++){
        tmp = tmp * i;
        result += tmp;
    }
    cout << result;
    return 0;
}