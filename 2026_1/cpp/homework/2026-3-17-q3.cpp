#include <iostream>
using namespace std;
struct Time{
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
};
int main() {
    struct Time time[1];
    cout << "Input current date and time with the format: year month day hour minute second" << endl;
    cin >> time[0].year >> time[0].month >> time[0].day >> time[0].hour >> time[0].minute >> time[0].second;
    cout << "Formated Time: " << time[0].year << "-" << time[0].month << "-" << time[0].day << " " << time[0].hour << ":" << time[0].minute << ":" << time[0].second << endl;
    return 0;
}