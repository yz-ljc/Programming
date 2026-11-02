#include <iostream>
#include <cstring>

using namespace std;

void sort(char **s, int n) {
    
    for (int i = 0; i < n; i++) {
        int min = i;
        
        for (int j = i + 1; j < n; j++) {
            if (strcmp(s[min], s[j]) > 0) {
                min = j;
            }
        }
        
        if (min != i) {
            char * tmp = s[min];
            s[min] = s[i];
            s[i] = tmp;
        }
    }
}

int main() {
    int n;
    cout << "Input n:";
    cin >> n;
    
    char **s = new char*[n];
    cout << "Input the strings:";
    for (int i = 0; i < n; i++) {
        char * t = new char[100];
        cin >> t;
        s[i] = t;
    }
    
    sort(s, n);
    
    cout << "\nThe sorted strings:" << endl;
    for (int i = 0; i < n; i++) {
        cout << s[i] << endl;
        delete[] s[i];
    }
    
    return 0;
}