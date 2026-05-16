#include <iostream>
using namespace std;

class Vector {
public:
    Vector(int s = 100);

    Vector(const Vector &v);

    int &Elem(int ndx);

    void Display();

    void Set();

    ~Vector();

protected:
    int size;
    int *buffer;
};

Vector::Vector(int s) {
    buffer = new int[size = s];
    for (int i = 0; i < size; i++) {
        buffer[i] = i + 1;
    }
}

Vector::Vector(const Vector &v) {
    this->size = v.size;
    this->buffer = new int[this->size];
    for (int i = 0; i < this->size; i++) {
        this->buffer[i] = v.buffer[i];
    }
}

int &Vector::Elem(int ndx) {
    if (ndx < 0 || ndx >= size) {
        cout << "error in index" << endl;
        exit(1);
    }
    return buffer[ndx];
}

void Vector::Display() {
    for (int j = 0; j < size; j++) {
        cout << Elem(j) << endl;
    }
}

void Vector::Set() {
    for (int j = 0; j < size; j++) {
        Elem(j) = j + 1;
    }
}

Vector::~Vector() {
    delete[] buffer;
}

int main() {
    Vector a(10);
    Vector b(a);
    a.Set();
    b.Display();
    return 0;
}
