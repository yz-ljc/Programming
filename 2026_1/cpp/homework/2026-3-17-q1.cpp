#include <iostream>
using namespace std;

int get_length(char str[]) {
    char *p = str;
    int length = 0;
    while (*p != '\0') {
        length++;
        p++;
    }
    return length;
}

int get_length(int num) {
    int length = 0;
    while (num > 0) {
        num /= 10;
        length++;
    }
    return length;
}

int main() {
    char str[] = "Hello, World!";
    int num = 123456;
    cout << "Length of char:\t" << get_length(str) << endl;
    cout << "Length of int:\t" << get_length(num) << endl;
    return 0;
}
