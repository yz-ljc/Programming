#include <iostream>

long long isPrime(long long a) {
    if (a == 2) return 1;
    if (a < 2 || a % 2 == 0) return 0;
    for (long long i = 3;i * i <= a;i+=2) {
        if (a % i == 0) return 0;
    }
    return 1;
}

int main() {
    long long x,y,total = 0;
    std::cin >> x >> y;
    if (x > y) std::swap(x,y); // 草泥马
    for (long long i = x;i <= y;i++) {
        if (isPrime(i)) {
            total++;
        }
    }
    std::cout << total;
    return 0;
}