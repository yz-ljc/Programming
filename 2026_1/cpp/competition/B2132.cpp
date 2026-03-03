#include <iostream>

int isPrime (int a) {
    if (a == 1) return 0;
    for (int i = 2;i < a;i ++) {
        if (a % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n, last = 1;
    bool found = false;
    std::cin >> n;;
    for (int i = 2; i <= n; i++) {
        if (isPrime(i)) {
            if (i - last == 2) {
                found = true;
                std::cout << last << " " << i << std::endl;
            }
            last = i;
        }
    }

    if (!found) std::cout << "empty" << std::endl;
    return 0;
}
