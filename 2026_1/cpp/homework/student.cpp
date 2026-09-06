#include "student.h"
#include <iomanip>
using namespace std;

void Student::display(std::ostream &out) {
    out << left << setw(20) << pName << this->uID << ", " << right << setw(4) << grade;
}

ostream& operator<<(ostream& out, Student & st) {
    st.display(out);
    out << endl;
    return out;
}