#include <iostream>
using namespace std;

template <class T>
void swapNum(T & a, T & b) {
    T temp = a;
    a = b;
    b = temp;
}

int main() {
    int a = 1;
    int b = 2;
    swapNum(a, b);
    cout << a << b << endl;
    float c = 1.2;
    float d = 3.4;
    swapNum(c, d);
    cout << c << d << endl;

    return 0;
}