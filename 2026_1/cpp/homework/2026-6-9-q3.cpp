#include <iostream>
using namespace std;

class Mammal {
public:
    Mammal() {
        cout << "Construct Mammal" << endl;
    }

    virtual void speak() {
        cout << "Default Sound" << endl;
    }

    virtual ~Mammal() {
        cout << "Destruct Mammal" << endl;
    }
};

class Dog : public Mammal {
public:
    Dog() {
        cout <<"Construct Dog" << endl;
    }

    void speak() override {
        cout << "Barking" << endl;
    }

    ~Dog() {
        cout << "Destruct Dog" << endl;
    }
};

int main() {

    Dog dog1;
    dog1.speak();

    Mammal* p = &dog1;
    p->speak();

    return 0;
}