#include <iostream>
using namespace std;
int weigh[] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
char checkMap[] = {'1','0','X','9','8','7','6','5','4','3','2'};

int main() {
    int N,correctNum = 0;
    cin >> N;
    char id[N][19];
    bool vaildLine[N];
    for (int i= 0;i < N;i++) {
        cin >> id[i];
    }
    for (int i = 0;i < N;i++) {
        int total = 0;
        bool vaild = true;
        for (int j = 0;j < 17;j++) {
            if (!(id[i][j] >= '0' && id[i][j] <= '9')) {
                vaild = false;
                vaildLine[i] = false;
                break;
            }
            total += (id[i][j] -  '0') * weigh[j];
        }
        if (vaild) {
            char checkId = checkMap[total % 11];
            if (checkId == id[i][17]) {
                vaildLine[i] = true;
                correctNum++;
            }else{
                vaildLine[i] = false;
            }
        }
    }
    if (correctNum == N) {
        cout << "All passed" << endl;
    }else {
        for (int i = 0;i < N;i++) {
            if (!vaildLine[i]) {
                cout << id[i] << endl;
            }
        }
    }
    return 0;
}