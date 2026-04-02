#include <iostream>
using namespace std;

class Box{
    double length;
    double width;
    double height;
public:
    void set_data(double l, double w, double h) {
        this -> length = l;
        this -> width = w;
        this -> height = h;
    }

    void get_data() {
        cout << "Box Data >>  Length: " << length << " Width: " << width << " Height:" << height << endl;
    }

    void get_area() {
        double result = length * width * 2 + length * height * 2 + width * height * 2;
        cout << "Area: " << result << endl;
    }

    void get_volume() {
        cout << "Volume: " << length * width * height << endl;
    }
};

int main() {
    Box box1;
    box1.set_data(3,4,5);
    box1.get_data();
    box1.get_area();
    box1.get_volume();

    return 0;
}