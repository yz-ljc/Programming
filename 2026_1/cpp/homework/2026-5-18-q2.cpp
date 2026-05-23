#include <iostream>
#include <cmath>
using namespace std;

class Point {
    double x;
    double y;
    double z;
public:
    Point(double x, double y, double z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    void disp() const {
        cout << "(" << x << ", " << y << ", " << z << ")";
    }

    friend double Line_length (const Point & p1, const Point & p2);
};

double Line_length(const Point & p1, const Point & p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    double dz = p2.z - p1.z;
    return sqrt(dx * dx + dy * dy + dz * dz);
}

int main() {

    Point A(1.0, 2.0, 3.0);
    Point B(4.0, 6.0, 8.0);

    cout << "Point A: "; A.disp(); cout << endl;
    cout << "Point B: "; B.disp(); cout << endl;

    cout << "Length of line segment AB: " << Line_length(A, B) << endl;

    return 0;
}