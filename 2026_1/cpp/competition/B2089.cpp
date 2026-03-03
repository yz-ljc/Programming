#include <iostream>

int main() {
    int num,arr[100];
    int *start = arr,*end = arr;
    std::cin >> num;
    for (int i = 0;i < num;i++) {
        std::cin >> arr[i];
        end++;
    }
    end--;
    while (start < end) {
        int tmp = *start;
        *start++ = *end;
        *end-- = tmp;
    }
    for (int i = 0;i < num;i++) {
        std::cout << arr[i];
        if (i != num -1) {
            std::cout << " ";
        }
    }
    return 0;
}