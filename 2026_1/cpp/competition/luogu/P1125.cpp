#include <iostream>
#include <string>
using namespace std;

bool isPrime(const int a) {
    if (a == 0 || a == 1) return false;
    if (a == 2) return true;
    for (int i = 3;i < a;i +=2) {
        if (a % i == 0) return false;
    }
    return true;
}

int main() {
    string str;
    getline(cin,str);
    int maxNum = 0,minNum = 100;
    int count[26] = {0};
    for (int i = 0;i < str.length();i++) {
        count[str[i] - 'a']++;
    }
    for (int i = 0;i < 26;i++) {
        if (count[i] == 0) continue;
        if (count[i] > maxNum) maxNum = count[i];
        if (count[i] < minNum) minNum = count[i];
    }
    int result = maxNum - minNum;
    if (isPrime(result)) {
        cout << "Lucky Word" << endl << result << endl;
    }else{
        cout << "No Answer" << endl << "0" << endl;
    }
    return 0;
}