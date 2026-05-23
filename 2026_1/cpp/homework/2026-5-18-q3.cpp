#include <iostream>
using namespace std;

class Date {
    int year;
    int month;
    int day;

public:
    Date(const int year = 2026, const int month = 5, const int day = 18) {
        this->year = year;
        this->month = month;
        this->day = day;
    }

    Date(const Date & date) {
        this->year = date.year;
        this->month = date.month;
        this->day = date.day;
    }

    void setDate(const int year, const int month, const int day) {
        this->year = year;
        this->month = month;
        this->day = day;
    }

    friend void display(const Date & date);
};

void display(const Date &date) {
    cout << date.year << "-" << date.month << "-" << date.day << endl;
}

int main() {
    Date today;
    cout << "Default date: ";
    display(today);

    Date birthday(1995, 12, 25);
    cout << "Birthday: ";
    display(birthday);

    Date copyDate(birthday);
    cout << "Copied date: ";
    display(copyDate);

    today.setDate(2023, 1, 1);
    cout << "Modified today: ";
    display(today);

    return 0;
}