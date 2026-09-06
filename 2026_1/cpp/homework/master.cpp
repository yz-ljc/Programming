#include "master.h"
#include <iostream>
using namespace std;

void MasterStudent::display(std::ostream &out) {
    Student::display(out);
    out << ", " << type;
}
