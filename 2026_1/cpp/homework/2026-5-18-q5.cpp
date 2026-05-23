#include <iomanip>
#include <iostream>
using namespace std;

class Score {
    int score;
    static int sum;
    static int total;
public:
    Score(int score) {
        if (score < 0) {
            cout << "成绩不能为负数" << endl;
            this->score = 0;
            total++;
            return;
        }
        this->score = score;
        sum += score;
        total++;
    }

    void setScore(int score) {
        if (score < 0) {
            cout << "成绩不能为负数，修改失败" << endl;
            return;
        }
        sum -= this->score;
        this->score = score;
        sum += this->score;
    }

    static int getSum() {
        return sum;
    }

    static double getAverage() {
        return static_cast<double>(sum) / total;
    }
};

int Score::sum = 0;
int Score::total = 0;

int main() {
    Score s1(85);
    Score s2(90);
    Score s3(78);

    cout << "当前总分: " << Score::getSum() << endl;

    s2.setScore(95);
    cout << "修改后总分: " << Score::getSum() << endl;

    Score s4(88);
    cout << "添加后总分: " << Score::getSum() << endl;

    Score s5(-1);
    s5.setScore(-114514);

    cout << "平均分：" << fixed << setprecision(2) << Score::getAverage() << endl;

    return 0;
}