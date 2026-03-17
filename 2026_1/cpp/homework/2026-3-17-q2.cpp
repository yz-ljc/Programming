#include <iostream>
using namespace std;

int str_cmp(char *s1, char *s2) {
    while (*s1 == *s2 && *s1 != '\0') {
        s1++;
        s2++;
    }
    if (*s1 > *s2) return 1;
    else if (*s1 == *s2) return 0;
    else return -1;
}

double find_maxer(int a, int b) {
    return (double) (a > b ? a : b);
}

double find_maxer(double a, double b, double c) {
    double maxNum = a;
    if (b > maxNum) maxNum = b;
    if (c > maxNum) maxNum = c;
    return maxNum;
}

double find_maxer(char *s1, char *s2) {
    return (double) str_cmp(s1, s2);
}

int main() {
    cout << "Find max int:\t" << find_maxer(5, 6) << endl;
    cout << "Find max num:\t" << find_maxer(1.111, 2.222, -114514) << endl;
    cout << "Find max str:\t" << find_maxer("yzljc", "yuljc") << endl;
    return 0;
}
