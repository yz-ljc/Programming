#include <iostream>
using namespace std;
int str_cmp(const char * str1, const char * str2);

int main() {
    char str1[64];
    char str2[64];
    cin >> str1 >> str2;
    int checkResult = str_cmp(str1, str2);
    cout << checkResult << endl;
    return 0;
}

int str_cmp(const char *str1, const char *str2) {
    const char *originalStr = str1;
    while (*str1 == *str2 && *str1 != '\0') {
        str1++;
        str2++;
    }
    if (*str1 > *str2) {
        return str1 - originalStr + 1;
    }
    if (*str1 < *str2) {
        return originalStr - str1 - 1;
    }
    return 0;
}