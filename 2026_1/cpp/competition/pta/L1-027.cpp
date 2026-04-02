#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    string tel;
    cin >> tel;
    vector<int> arrNum;
    vector<int> index;
    bool numMap[10] = {false};
    int i = 0;
    for (char c : tel) {
        int tmp = c - '0';
        if (numMap[tmp]) continue;
        arrNum.push_back(tmp);
        numMap[tmp] = true;
    }
    sort(arrNum.begin(), arrNum.end(),[] (int a, int b){
         return a > b;
    });
    for (char c : tel) {
        int tmp = c - '0';
        int j = 0;
        for (int i : arrNum) {
            if (i == tmp) {
                index.push_back(j);
                break;
            }
            j++;
        }
    }
    cout << "int[] arr = new int[]{";
    bool o = false;
    for (int i : arrNum) {
        if (i != arrNum[0]) cout << ",";
        cout << i;
    }
    cout << "};" << endl << "int[] index = new int[]{";
    for (int i : index) {
        if (o) cout << ",";
        cout << i;
        o = true;
    }
    cout << "};" << endl;
    return 0;
}