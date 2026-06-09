#include <iostream>
using namespace std;

class Complex {
    double r;
    double i;

public:
    Complex() {
        r = 0;
        i = 0;
    }

    Complex(double r, double i) : r(r), i(i) {
    }

    friend Complex operator+(Complex &n1, Complex &n2);

    friend Complex operator-(Complex &n1, Complex &n2);

    void display() {
        cout << r;
        if (i >= 0) cout << "+";
        cout << i << "i";
    }
};

Complex operator+(Complex &n1, Complex &n2) {
    return Complex(n1.r + n2.r, n1.i + n2.i);
}

Complex operator-(Complex &n1, Complex &n2) {
    return Complex(n1.r - n2.r, n1.i - n2.i);
}

int main() {

    Complex a = Complex();
    Complex b = Complex(1.23, 4.56);
    Complex c = Complex(1, 10);

    Complex d = a + b;
    Complex e = b - c;
    Complex f = b + c;

    a.display();
    cout << " + ";
    b.display();
    cout << " = ";
    d.display();
    cout << endl;
    b.display();
    cout << " - ";
    c.display();
    cout << " = ";
    e.display();
    cout << endl;
    b.display();
    cout << " + ";
    c.display();
    cout << " = ";
    f.display();
    cout << endl;

    return 0;
}
