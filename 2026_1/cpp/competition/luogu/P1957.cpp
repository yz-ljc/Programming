#include <iostream>
#include <math.h>
#include <vector>
#include <string>
using namespace std;

void print_result(const char pointer,const string str,const bool isRawData) {
    int j = 0;
    if (isRawData) j = 0;
    else j = 2;
    if (pointer == 'a') {
        int result = 0;
        int tmp = 0;
        int count = 0;
        bool isFirst = true;
        for (;j < str.length();j++) {
            if (str[j] != ' ') {
                tmp = tmp*10 + str[j] - '0';
                count++;
            }else{
                result += tmp;
                if (isFirst) cout << tmp << "+";
                tmp = 0;
                isFirst = false;
            }
        }
        cout << tmp;
        result += tmp;
        int len = to_string(result).length();
        cout << "=" << result << endl << count + 2 + len << endl;
    }
    if (pointer == 'b') {
        int result = 0;
        int tmp = 0;
        int count = 0;
        bool isFirst = true;
        for (;j < str.length();j++) {
            if (str[j] != ' ') {
                tmp = tmp*10 + str[j] - '0';
                count++;
            }else{
                result += tmp;
                if (isFirst) cout << tmp << "-";
                tmp = 0;
                isFirst = false;
            }
        }
        cout << tmp;
        result -= tmp;
        int len = to_string(result).length();
        cout << "=" << result << endl << count + 2 + len << endl;
    }
    if (pointer == 'c') {
        int result = 0;
        int tmp = 0;
        int count = 0;
        bool isFirst = true;
        for (;j < str.length();j++) {
            if (str[j] != ' ') {
                tmp = tmp*10 + str[j] - '0';
                count++;
            }else{
                result += tmp;
                if (isFirst) cout << tmp << "*";
                tmp = 0;
                isFirst = false;
            }
        }
        cout << tmp;
        result *= tmp;
        int len = to_string(result).length();
        cout << "=" << result << endl << count + 2 + len << endl;
    }
}

int main() {
    vector<string> data;
    int num;
    cin >> num;
    cin.ignore();
    for (int i = 0;i < num;i++) {
        string tmp;
        getline(cin, tmp);
        data.push_back(tmp);
    }
    char last;
    char pointer;
    for (int i = 0;i < num;i++) {
        if (data[i][0] == 'a' || data[i][0] == 'b' || data[i][0] == 'c') {
            pointer = data[i][0];
            last = data[i][0];
            print_result(pointer,data[i],false);
        }else {
            pointer = last;
            print_result(pointer,data[i],true);
        }

    }
    return 0;
}