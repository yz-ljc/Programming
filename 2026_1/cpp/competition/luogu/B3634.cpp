#include <iostream>

long long gcd(long long a,long long b) {
    return b?gcd(b,a%b) : a;
}

long long lcm(long long a,long long b) {
    return a*b/gcd(a,b);
}

int main() {
    long long a,b;
    std::cin >> a >> b;
    long long result_gcd = gcd(a,b);
    long long result_lcm = lcm(a,b);
    std::cout << result_gcd << " " << result_lcm << std::endl;
    return 0;
}