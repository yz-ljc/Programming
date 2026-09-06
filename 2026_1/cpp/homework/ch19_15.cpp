#include "student.h"
#include "master.h"
#include <fstream>
using namespace std;

int main() {
    ofstream out("1.txt");
    Student s1("A1", 12567, 3.5);
    MasterStudent s2("B2", 12667, 4.1, 'A');
    MasterStudent s3("C3", 12579, 3.8, 'B');
    out << s1;
    out << s2;
    out << s3;
    return 0;
}