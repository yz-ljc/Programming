#include <iostream>
using namespace std;

int main() {
    int init, x, tmp;
    char result[16];
    char *p = result;

    cin >> init >> x;

    if (init == 0) {
        cout << 0;
        return 0;
    }

    while (init > 0) {
        tmp = init % x;
        if (tmp >= 10) {
            *p++ = tmp - 10 + 'A';
        } else {
            *p++ = tmp + '0';
        }
        init /= x;
    }
    *p = '\0';

    char *start = result;
    char *end = p - 1;

    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }

    cout << result << endl;
    return 0;
}