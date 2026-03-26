#include <iostream>
using namespace std;

int main() {
    const int arr1[3][3] = {{5, 7, 8}, {2, -2, 4}, {1, 1, 1}};
    const int arr2[3][3] = {{4, -2, 3}, {3, 9, 4}, {8, -1, 2}};
    int arr_result[3][3];
    cout << "Result:" << endl;
    for (int i = 0;i < 3;i++) {
        for (int j = 0;j < 3;j++) {
            arr_result[i][j] = arr1[i][j] + arr2[i][j];
            cout << " " << arr_result[i][j];
        }
        cout << endl;
    }
    return 0;
}
