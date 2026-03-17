#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void print_my_text(int arr[]) {
    sort(arr, arr + 3);
    cout << "Output 3 integers: ";
    for (int i = 0;i < 3;i++) {
        if (i != 0) cout << " ";
        cout << arr[i];
    }
    cout << endl;
}

void print_my_text(string str[]) {
    sort(str, str + 3);
    cout << "Output 3 strings: ";
    for (int i =0;i < 3;i++) {
        if (i != 0) cout << " ";
        cout <<str[i];
    }
    cout << endl;
}

void q3_print_result(int arr[]) {
    cout << "Question 3 result:";
    for (int i = 0;i < 10;i++) {
        cout << " " << arr[i];
    }
    cout << endl;
}

void q3_swap_num(int arr[]) {
    int maxNum = 0;
    int maxindex = 0;
    for (int i = 0;i < 10;i++) {
        if (arr[i] > maxNum) {
            maxNum = arr[i];
            maxindex = i;
        }
    }

    int tmp = arr[maxindex];
    arr[maxindex] = arr[9];
    arr[9] = tmp;
    q3_print_result(arr);
}

void q3_input_num() {
    int arr[10];
    for (int i = 0;i < 10;i++) {
        cin >> arr[i];
    }
    // q3_2
    q3_swap_num(arr);
}

int main() {
    int arr[] = {123,456,114514};
    string str[] = {"hello","yzljc","world!"};
    // question 1
    print_my_text(arr);
    // question 2
    print_my_text(str);
    // question 3
    q3_input_num();
}