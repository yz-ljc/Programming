#include <iostream>
using namespace std;

int main() {
    int n;
    char str[1000];
    cout << "Please input the string:";
    cin >> str;
    cout << "Please input the number of swap-char:";
    cin >> n;

    int len = 0;
    while (str[len] != '\0') {
        len++;
    }

    //    len--;

    for (int i = 0, j = len - 1; i < n; i++, j--) {
        char tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
    }

    for (int i = 0, j = n - 1; i < n; i++, j--) {
        char tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
    }

    for (int i = len - n, j = len - 1; i <= j; i++, j--) {
        char tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
    }

    cout << "The new string is " << str << endl;
    return 0;
}