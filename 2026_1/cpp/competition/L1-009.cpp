#include <iostream>

long long gcd(long long a,long long b) {
    return b ? gcd(b,a % b) : a;
}

long long lcm(long long a,long long b) {
    return a * b / gcd(a,b);
}

int main() {
    long long total,last = 0,result = 0;
    char nothing;
    std::cin >> total;
    long long part1[total],part2[total];
    for (int i = 0;i < total;i++) {
        std::cin >> part1[i] >> nothing >> part2[i];
        if (i == 0) continue;
        if (i == 1) {
            last = lcm(part2[i-1],part2[i]);
            continue;
        }
        last = lcm(last,part2[i]);
    }
    for (int i = 0;i < total;i++) {
        part1[i] = last / part2[i] * part1[i];
        result += part1[i];
    }
    const long long intNum = result / last;
    const long long remained = result - intNum * last;
    const long long divided = gcd(remained,last);
    if (intNum != 0) std::cout << intNum;
    if (intNum != 0 && remained != 0) std::cout << " ";
    if (remained != 0) std::cout << remained / divided << "/" << last / divided << std::endl;
    if (intNum == 0 && remained == 0) std::cout << 0 << std::endl;
    return 0;
}