#include <iostream>

int main() {
    char str[1000000];
    std::cin >> str;
    char *p = str,*q = str;
    while (*p != '\0') {
        if ((*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <= 'Z')) {
            *q = *p;
            q++;
        }
        p++;
    }
    *q = '\0';
    std::cout << str << std::endl;
    return 0;
}