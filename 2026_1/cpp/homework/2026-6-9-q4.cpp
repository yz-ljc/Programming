#include <iostream>
#include <cmath>
using namespace std;

class Shape {
public:
    virtual double getArea() = 0;

    virtual double getPrtim() = 0;

    virtual ~Shape() {
    }
};

class Rectangle : public Shape {
    double a;
    double b;

public:
    Rectangle(double a, double b) {
        this->a = a;
        this->b = b;
    }

    double getArea() override {
        return a * b;
    }

    double getPrtim() override {
        return (a + b) * 2;
    }
};

class Circle : public Shape {
    double r;
public:
    Circle(double r) {
        this->r = r;
    }

    double getArea() override {
        return r * r * M_PI;
    }

    double getPrtim() override {
        return 2 * M_PI * r;
    }
};

int main() {
    Rectangle r(5, 3);
    Circle c(4);

    cout << "Rect area:" << r.getArea() << " perimeter:" << r.getPrtim() << endl;
    cout << "Circle area:" << c.getArea() << " perimeter:" << c.getPrtim() << endl;

    return 0;
}
