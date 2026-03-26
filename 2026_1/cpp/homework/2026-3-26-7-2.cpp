#include <iostream>
using namespace std;

int insert_num(int arr[], int x, int N) {
    int len = N;
    int deprecated = 0;
    if (x > arr[len - 1]) {
        return x;
    }
    if (x >= arr[len - 2] && x < arr[len - 1]) {
        deprecated = arr[len - 1];
        arr[len - 1] = x;
        return deprecated;
    }
    deprecated = arr[len - 1];
    for (int i = 0;i < len - 1;i++) {
        if (x > arr[i] && x < arr[i+1]) {
            for (int j = len - 1;j > i;j--) {
                arr[j] = arr[j - 1];
                if (j == i + 1) {
                    arr[j] = x;
                    break;
                }
            }
        }
    }
    return deprecated;
}

int main() {
    int test_arr[] = {1,2,3,4,5,7,8,18,19,100};
    int n;
    cin >> n;
    for (int i = 0;i < 10;i++) {
        if (i != 0) cout << " ";
        cout << test_arr[i];
    }
    cout << endl;
    int a = insert_num(test_arr,n,10);
    for (int i = 0;i < 10;i++) {
        if (i != 0) cout << " ";
        cout << test_arr[i];
    }
    cout << endl;
    cout << "Deprecated: " << a << endl;
    return 0;
}