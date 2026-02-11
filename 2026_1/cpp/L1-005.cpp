#include <iostream>
int total;

struct Student {
    long long examIndex;
    int testNum;
    int formalNum;
};

int main() {
    std::cin >> total;
    Student stu[total];
    int checkLine[total],realLine[total];
    for (int i = 0;i < total;i++) {
        std::cin >> stu[i].examIndex >> stu[i].testNum >> stu[i].formalNum;
    }
    int checkNum;
    std::cin >> checkNum;
    for (int i = 0;i < checkNum;i++) {
        std::cin >> checkLine[i];
    }
    for (int i = 0;i < checkNum;i++) {
        for (int j = 0;j < total;j++) {
            if (checkLine[i] == stu[j].testNum) {
                realLine[i] = j;
            }
        }
    }
    for (int index,i = 0;i < checkNum;i++) {
        index = realLine[i];
        std::cout << stu[index].examIndex << " " << stu[index].formalNum << std::endl;
    }
    return 0;
}