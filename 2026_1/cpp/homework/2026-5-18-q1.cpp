#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    long studentId;
    string studentName;
    double score;
    static int totalStudentNum;
    static double totalStudentScore;

public:
    Student(const long studentId, const string &studentName, const double score) {
        this->studentId = studentId;
        this->studentName = studentName;
        this->score = score;
        totalStudentNum++;
        totalStudentScore += score;
    }

    static double Average() {
        return totalStudentScore / totalStudentNum;
    }

    void Print() const {
        cout << "ID: " << studentId
             << ", Name: " << studentName
             << ", Score: " << score << endl;
    }
};

int Student::totalStudentNum = 0;
double Student::totalStudentScore = 0;

int main() {
    Student s1(1001, "Alice", 95.0);
    Student s2(1002, "Bob", 88.5);
    Student s3(1003, "Charlie", 76.0);

    s1.Print();
    s2.Print();
    s3.Print();

    cout << "Average Score: " << Student::Average() << endl;

    return 0;
}