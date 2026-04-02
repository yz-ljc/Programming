#include <iostream>
using namespace std;

class Tree{
    int ages;
public:
    Tree() {
        this -> ages = 0;
    }
    void grow(int year) {
        this->ages += year;
    }
    void age() {
        cout << "Ages: " << this -> ages << endl;
    }
};

int main() {
    Tree tree;
    tree.grow(100);
    tree.age();
    return 0;
}