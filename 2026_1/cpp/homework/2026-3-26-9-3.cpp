#include <iostream>
using namespace std;

void swap_char(char *&a,char *&b) {
    char * tmp = a;
    a = b;
    b = tmp;
}

int main() {
    char * ap = "hello";
    char * bp = "how are you?";
    cout << "original: " << ap << " " << bp << endl;
    swap_char(ap, bp);
    cout << "swapped: " << ap << " " << bp << endl;
    return 0;
}