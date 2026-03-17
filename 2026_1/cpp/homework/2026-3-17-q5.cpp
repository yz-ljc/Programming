#include <iostream>
#include <iomanip>
using namespace std;

struct Students {
    string name;
    double scores[5];
};

void class1_avg(struct Students stu[]) {
    double result = 0;
    for (int i = 0; i < 4; i++) {
        result += stu[i].scores[0];
    }
    cout << "Average score of the first lesson: " << fixed << setprecision(2) << result / 4 << endl;
}

void question2_impl(struct Students stu[]) {
    bool invalid_stu[4] = {false};
    double sc[4] = {0};
    for (int i = 0; i < 4; i++) {
        int total = 0;
        for (int j = 0; j < 5; j++) {
            sc[i] += stu[i].scores[j];
            if (stu[i].scores[j] < 60) {
                total++;
            }
            if (total >= 2) {
                invalid_stu[i] = true;
                break;
            }
        }
    }
    int i = 0;
    for (bool e : invalid_stu) {
        if (e) {
            cout << "Student " << stu[i].name << " have 2 or more exams failed!" << endl;
            cout << "Average score: " << fixed << setprecision(2) << sc[i] / 5 << "\t" << "Total score: " << fixed << setprecision(2) << sc[i] << endl;
        }
        i++;
    }
}

void question3_impl(struct Students stu[]) {
    bool excellent_stu[4] = {false};
    for (int i = 0;i < 4; i++) {
        bool tmp = true;
        double sc = 0;
        for (int j = 0;j < 5; j++) {
            if (stu[i].scores[j] < 85) {
                tmp = false;
            }
            sc += stu[i].scores[j];
        }
        if (sc / 5 >= 90 || tmp) {
            excellent_stu[i] = true;
        }
    }
    int i = 0;
    cout << "Excellent students(avg >= 90 or all lessons above 85 scores):";
    for (bool e : excellent_stu) {
        if (e) {
            cout << " " << stu[i].name;
        }
        i++;
    }
}

int main() {
    struct Students stu[4];
    cout << "Input students data:" << endl;
    for (int i = 0; i < 4; i++) {
        cout << "Input score data for student " << i << ": " << endl;
        cin >> stu[i].name;
        for (int j = 0;j < 5; j++) {
            cin >> stu[i].scores[j];
        }
    }

    class1_avg(stu);
    question2_impl(stu);
    question3_impl(stu);

    return 0;
}
