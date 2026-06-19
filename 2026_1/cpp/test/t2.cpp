#include <iostream>
using namespace std;

class Complex {
    double r;
    double i;
public:
    Complex() {
        this->r = 0;
        this->i = 0;
    }
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
        cout << "(" << r << "," << i << "i)" << endl;
    }
};



int main() {

    Complex n1(3,4);
    Complex n2(5,-10);
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