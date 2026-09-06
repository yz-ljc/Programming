#ifndef STUDENT
#define STUDENT
#include <iostream>
#include <cstring>
using namespace std;

class Student {
    char pName[20];
    unsigned int uID;
    float grade;
public:
    virtual ~Student() {}

    Student(char * pS, unsigned num, float g) {
        strcpy(pName, pS);
        uID = num;
        grade = g;
    }

    virtual void display(std::ostream & out);
};

ostream& operator <<(ostream& out, Student& st);

#endif