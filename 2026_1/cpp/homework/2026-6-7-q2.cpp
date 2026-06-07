#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    bool sex;
    int age;

public:
    Person(const string &name, const bool sex, const int age) : name(name), sex(sex), age(age) {
    }
};

class Student : public Person {
    long number;
    string classinfo;
    string major;
    double score;

public:
    Student(const string &name, const bool sex, const int age, const long number,
            const string &classinfo, const string &major, const double score) : Person(name, sex, age), number(number),
        classinfo(classinfo), major(major), score(score) {
    }

    void setStudentInfo(const long number, const string &classinfo, const string &major, const double score) {
        this->number = number;
        this->classinfo = classinfo;
        this->major = major;
        this->score = score;
    }

    void setNumber(long number) {
        this->number = number;
    }

    void setClassinfo(const string &classinfo) {
        this->classinfo = classinfo;
    }

    void setMajor(const string &major) {
        this->major = major;
    }

    void setScore(double score) {
        this->score = score;
    }

    void displayStudentInfo() const {
        cout << "Name: " << this->name << endl;
        cout << "Sex: " << (this->sex ? "Male" : "Female") << endl;
        cout << "Age: " << this->age << endl;
        cout << "Number: " << this->number << endl;
        cout << "Class: " << this->classinfo << endl;
        cout << "Major: " << this->major << endl;
        cout << "Score: " << this->score << endl;
    }
};

class Teacher : public Person {
    long id;
    string title;
    double salary;

public:
    Teacher(const string &name, const bool sex, const int age, const long id,
            const string &title, const double salary) : Person(name, sex, age), id(id),
        title(title), salary(salary) {
    }

    void setTeacherInfo(const long id, const string &title, const double salary) {
        this->id = id;
        this->title = title;
        this->salary = salary;
    }

    void setWorkId(const long id) {
        this->id = id;
    }

    void setTitle(const string &title) {
        this->title = title;
    }

    void setSalary(double salary) {
        this->salary = salary;
    }

    void displayTeacherInfo() const {
        cout << "Name: " << this->name << endl;
        cout << "Sex: " << (this->sex ? "Male" : "Female") << endl;
        cout << "Age: " << this->age << endl;
        cout << "ID: " << this->id << endl;
        cout << "Title: " << this->title << endl;
        cout << "Salary: " << this->salary << endl;
    }
};

int main() {
    Student stu("Alice", true, 20, 2024001, "Class1", "Computer Science", 95.5);
    Teacher tea("Bob", true, 35, 1001, "Professor", 8000.0);

    stu.displayStudentInfo();
    cout << "===========" << endl;
    tea.displayTeacherInfo();

    stu.setNumber(2024002);
    stu.setClassinfo("Class2");
    stu.setMajor("Software Engineering");
    stu.setScore(98.0);
    stu.setStudentInfo(2024003, "Class3", "AI", 99.0);

    tea.setWorkId(1002);
    tea.setTitle("Associate Professor");
    tea.setSalary(9000.0);
    tea.setTeacherInfo(1003, "Dean", 10000.0);

    cout << "===========" << endl;
    stu.displayStudentInfo();
    cout << "===========" << endl;
    tea.displayTeacherInfo();

    return 0;
}
