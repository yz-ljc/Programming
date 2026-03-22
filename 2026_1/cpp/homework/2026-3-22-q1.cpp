// 使用内联函数编写一个求圆形面积的程序，分别输出半径为1.5和2的圆形面积。
#include <iostream>
using namespace std;
const double PI = 3.14;

inline double get_result(double r) {
    return r * r * PI;
}

int main() {
    double r1 = 1.5;
    double r2 = 2.0;
    cout << "R = 1.5, " << "S = " << get_result(r1) << endl;
    cout << "R = 2.0, " << "S = " << get_result(r2) << endl;
    return 0;
}