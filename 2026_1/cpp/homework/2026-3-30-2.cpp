#include <iostream>
using namespace std;

class Area{
private:
    double radius;
    double area;
public:
    Area(double radius) {
        this -> radius = radius;
    }

    void get_radius() {
        cout << "Radius: " << this -> radius << endl;
    }

    void disp_area() {
        this -> area = radius * radius * 3.14;
        cout << "Area: " << this -> area << endl;
    }
};

int main() {
    Area area1(20);
    area1.get_radius();
    area1.disp_area();

    Area area2(1.14514);
    area2.get_radius();
    area2.disp_area();

    return 0;
}