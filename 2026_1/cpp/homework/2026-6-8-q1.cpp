#include <iostream>
using namespace std;

class Complex {
    double r;
    double i;
public:
    Complex(double r, double i) {
        this->r = r;
        this->i = i;
    }

    Complex operator+(const Complex & x) {
        Complex temp = Complex(this->r + x.r, this->i + x.i);
        return temp;
    }

    Complex operator-(const Complex & x) {
        Complex temp = Complex(this->r - x.r, this->i - x.i);
        return temp;
    }

    void display() {
        cout << this->r << " + " << this->i << "i" << endl;
    }
};



int main() {

    Complex num1 = Complex(1, 6);
    Complex num2 = Complex(10.3, 7);
    num1.display();
    num2.display();
    Complex num3 = num1 + num2;
    Complex num4 = num2 - num1;
    num3.display();
    num4.display();

    return 0;
}