#include <iostream>
using namespace std;

class Symmetry{
    double x;
    double y;
public:
    Symmetry(double x,double y) {
        this -> x = x;
        this -> y = y;
    }

    void get_symmetry() {
        cout << "Symmetry: " << -x << ", " << -y << endl;
    }
};

int main() {
    Symmetry s1(5,10);
    s1.get_symmetry();

    Symmetry s2(114514,1234);
    s2.get_symmetry();

    Symmetry s3(-1.56, -65);
    s3.get_symmetry();

    return 0;
}