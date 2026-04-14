#include <iostream>
using namespace std;

class Box{
private:
    double length;
    double width;
    double height;
public:
    Box() {
        length = 3;
        width = 4;
        height = 5;
    }
    Box(double length, double width, double height) {
        this -> length = length;
        this -> width = width;
        this -> height = height;
    }
    void getter() {
        cout << "length: " << this->length << " width: " << this->width << " height: " << this->height << endl;
    }
    void setter(double length, double width, double height) {
        this -> length = length;
        this -> width = width;
        this -> height = height;
    }
    double get_area() {
        return length * width * 2 + length * height * 2 + width * height * 2;
    }
    double get_volume() {
        return length * width * height;
    }
};

int main() {
    Box default_box;
    Box box1(5415, 541, 45);
    Box box2(3.14,15,9.26);
    default_box.getter();
    box1.getter();
    box2.getter();
    default_box.setter(1, 2, 3);
    default_box.getter();
    cout << "Box2 Area: " << box2.get_area() << endl;
    cout << "Box2 Volume: " << box2.get_volume() << endl;

    return 0;
}