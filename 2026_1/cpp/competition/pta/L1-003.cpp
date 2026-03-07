#include <iostream>
#include <cstring>

int main(){
    char num[1001];
    int arr[10] = {0};
    std::cin >> num;
    char *p = num;
    size_t length = strlen(num);
    for (int i = 0;i < length;i++) {
        int index = *p - '0';
        arr[index]++;
        p++;
    }
    for (int i = 0;i < 10;i++) {
        if (arr[i] != 0) {
            std::cout << i << ":" << arr[i] <<std::endl;
        }
    }
    return 0;
}