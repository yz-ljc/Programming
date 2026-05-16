#include <iostream>
using namespace std;

class X {
private:
    int a;

public:
    X(int);

    X(const X &);

    ~X();
};

X::X(int a) {
    this->a = a;
    cout << "[+] Data Init Event: " << this->a << endl;
}

X::X(const X &x) {
    this->a = x.a;
    cout << "[+] Data Copy Init Event: " << a << endl;
}

X::~X() {
    cout << "[-] Data Destroy Event: " << a << endl;
}

X f(X x) {
    cout << "[+] Function f Called Event" << endl;
    return x;
}

int main() {
    X a(1);
    X b = f(X(2));
    a = f(a);
    return 0;
}
