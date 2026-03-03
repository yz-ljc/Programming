#include <iostream>
#include <string>
using namespace std;

int main() {
    string A;
    string B;
    getline(cin,A);
    getline(cin,B);
    for (int i = 0;i < A.length();i++){
        for (int j = 0;j < B.length();j++){
            if (A[i] == B[j]){
                break;
            }
            if (j == B.length() - 1){
                cout << A[i];
            }
        }
    }
    return 0;
}