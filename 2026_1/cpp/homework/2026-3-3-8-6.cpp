#include <iostream>
using namespace std;
char * strcpy(char * dest, const char * source);

int main() {
    char str1[64];
    char str2[64];
    cin >> str1;
    char * dest = strcpy(str2, str1);
    cout << "str2 address: " << &dest << endl << "str2: " << str2 << " | str1: " << str1 << endl;
    return 0;
}

char *strcpy(char *dest, const char *source) {
    int length_source = 0;
    while (*source != '\0') {
        *dest++ = *source++;
        length_source++;
    }
    *dest = '\0';
    return dest - length_source;
}
