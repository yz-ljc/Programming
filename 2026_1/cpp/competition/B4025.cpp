#include <iostream>

// bbaba
int gcd(int a,int b) {
    return b?gcd(b,a%b) : a;
}

int main() {
    int a,b;
    std::cin >> a >> b;
    int result = gcd(a,b);
    std::cout << result;
    return 0;
}