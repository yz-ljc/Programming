#include <iostream>
#include <cstring>
using namespace std;

void InsertString(char s1[], const char s2[], int pos);

int main()
{
    char s1[20], s2[20];
    int index;
    cout << "Input s1:";
    cin >> s1;
    cout << "Input s2:";
    cin >> s2;
    cout << "Input the index:";
    cin >> index;
    InsertString(s1, s2, index);
    cout << "\nThe new string:" << s1 << endl;
    return 0;
}

void InsertString(char *s1, const char *s2, int pos) {

    int len1 = strlen(s1);
    int len2 = strlen(s2);

    for (int i = len1 + len2 - 1; i >= len2; i--) {
        s1[i] = s1[i - len2];
    }

    for (int i = pos - 1, j = 0; j < len2 ; i++, j++) {
        s1[i] = s2[j];
    }
}