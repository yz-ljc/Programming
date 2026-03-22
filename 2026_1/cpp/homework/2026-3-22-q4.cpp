#include <iostream>
using namespace std;

void display(double var) {
    cout << "A double: " << var << endl;
}

void display(int var) {
    cout << "A int: " << var << endl;
}

void display(char var) {
    cout << "A char: " << var << endl;
}

int main() {
    double a = 3.1415926;
    float b = 12.34;
    int c = 114514;
    char d = 'F';
    short e = 25565;
    display(a);
    display(b);
    display(c);
    display(d);
    display(e);
    return 0;
}

// 函数重载的时候会根据具体的类型自己进行适配，比如float -> double, short -> int