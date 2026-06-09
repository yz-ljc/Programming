#include <iostream>
using namespace std;

class BaseClass {
public:
    virtual void fn1() {
        cout << "BaseClass fn1" << endl;
    }

    void fn2() {
        cout << "BaseClass fn2" << endl;
    }

    virtual ~BaseClass() {}
};

class DerivedClass : public BaseClass {
public:
    void fn1() {
        cout << "Derived fn1" << endl;
    }

    void fn2() {
        cout << "Derived fn2" << endl;
    }
};

int main() {
    DerivedClass d1;

    BaseClass* p = &d1;
    p->fn1();
    p->fn2();

    DerivedClass* q = &d1;
    q->fn1();
    q->fn2();

    return 0;
}