#include <iostream>
using namespace std;

class Complex {
private:
    double r, i;
public:
    Complex(double r = 0, double i = 0) : r(r), i(i) {}
    Complex operator+(const Complex& c) const {
        return Complex(r + c.r, i + c.i);
    }
    Complex operator-(const Complex& c) const {
        return Complex(r - c.r, i - c.i);
    }
    void display() const {
        cout << "(" << r << "," << i << "i)" << endl;
    }
};

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