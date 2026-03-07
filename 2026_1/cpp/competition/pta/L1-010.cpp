#include <iostream>
const int N = 3;

int main() {
    int a,b,c;
    std::cin >> a >> b >> c;
    for (int i = 0;i < N;i++) {
        if (a <= b) {
            int tmp = b;
            b = a;
            a = tmp;
        }
        if (b <= c) {
            int tmp = c;
            c = b;
            b = tmp;
        }
        if (a <= c) {
            int tmp = c;
            c = a;
            a = tmp;
        }
    }
    std::cout << c << "->" << b << "->" << a << std::endl;
    return 0;
}