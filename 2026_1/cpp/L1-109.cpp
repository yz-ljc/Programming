#include <iostream>
using namespace std;

int main(){
    char atri[1024];
    int arr[26],result = 0,count[26] = {0};
    cin >> atri;
    for (int i =0;i < 26;i++){
        cin >> arr[i];
    }
    char *p = atri;
    while (*p != '\0'){
        int index = *p - 'a';
        count[index]++;
        result += arr[index];
        p++;
    }
    for (int i = 0;i < 26;i++){
        if (i != 0) cout << " ";
        cout << count[i];
    }
    cout << "\n";
    cout << result;
    return 0;
}