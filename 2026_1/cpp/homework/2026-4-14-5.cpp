#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Student{
private:
    int number;
    string name;
    int score;
public:
    Student(int number, string name, int score) {
        this -> number = number;
        this -> name = name;
        this -> score = score;
    }
    void get_info() {
        cout << "Number: " << number << " Name: " << name << " Score: " << score << endl;
    }
    int get_score() {
        return this -> score;
    }
};

int main() {
    Student s[5] ={Student(10001, "user1", 79), Student(10002, "user2", 100),Student(10003, "user3", 17), Student(10004, "user4", 90), Student(10005, "user5", 96)};
    sort(s, s + 5, [] (Student a, Student b) {return a.get_score() < b.get_score();});
    for (Student a : s) {
        a.get_info();
    }
    return 0;
}