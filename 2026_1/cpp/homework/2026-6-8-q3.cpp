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

    Complex(double r, double i): r(r), i(i) {}

    double getR() {
        return this -> r;
    }

    double getI() {
        return this -> i;
    }

    void display() {
        cout << "(" << r << "," << i << "i)" << endl;
    }
};

Complex operator + (Complex & n1, Complex & n2) {
    return Complex(n1.getR() + n2.getR(), n1.getI() + n2.getI());
}

Complex operator - (Complex & n1, Complex & n2) {
    return Complex(n1.getR() - n2.getR(), n1.getI() - n2.getI());
}

int main() {

    Complex n1(3,4);
    Complex n2(5,-9);
    Complex n3,n4;
    cout << "c1=";
    n1.display();
    cout << "c2=";
    n2.display();
    n3 = n1 + n2;
    cout << "c3=c1+c2=";
    n3.display();
    n4 = n1 - n2;
    cout << "c4=c1-c2=";
    n4.display();

    return 0;
}