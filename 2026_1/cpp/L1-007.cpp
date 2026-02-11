#include <iostream>
#include <string.h>
using namespace std;
struct Reflect{
    char zw[8];
};

int main(){
    struct Reflect num[10];
    char input[32];
    strcpy(num[0].zw, "ling");
    strcpy(num[1].zw, "yi");
    strcpy(num[2].zw, "er");
    strcpy(num[3].zw, "san");
    strcpy(num[4].zw, "si");
    strcpy(num[5].zw, "wu");
    strcpy(num[6].zw, "liu");
    strcpy(num[7].zw, "qi");
    strcpy(num[8].zw, "ba");
    strcpy(num[9].zw, "jiu");
    cin >> input;
    char *p = input;
    bool isFirst = true;
    while (*p != '\0'){
        if (!isFirst) cout << " ";
        if (*p == '-') {
            cout << "fu";
            isFirst = false;
        }else {
            int index = *p - '0';
            cout << num[index].zw;
            isFirst = false;
        }
        p++;
    }
    return 0;
}