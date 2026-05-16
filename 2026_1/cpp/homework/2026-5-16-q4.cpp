#include <iostream>
using namespace std;

class CAT {
protected:
    int *itsAge;

public:
    CAT();

    CAT(const CAT &);

    ~CAT();

    int GetAge() const {
        return *itsAge;
    }

    void SetAge(int age) {
        *itsAge = age;
    }
};

CAT::CAT() {
    itsAge = new int;
    *itsAge = 5;
}

CAT::CAT(const CAT &v) {
    this->itsAge = new int;
    *itsAge = *v.itsAge;
}

CAT::~CAT() {
    delete itsAge;
    itsAge = 0;
}

int main() {
    CAT frisky;
    cout << "frisky's age: " << frisky.GetAge() << endl;
    cout << "Setting frisky to 6...\n";
    frisky.SetAge(6);

    cout << "Creating boots from frisky\n";
    CAT boots(frisky);
    cout << "frisky's age: " << frisky.GetAge() << endl;
    cout << "boots' age: " << boots.GetAge() << endl;
    cout << "setting frisky to 7...\n";
    frisky.SetAge(7);
    cout << "frisky's age: " << frisky.GetAge() << endl;
    cout << "boots' age: " << boots.GetAge() << endl;
    return 0;
}
