#include <iostream>

int main() {
    int num,maxer = 0;
    std::cin >> num;
    for (int x,i = 0;i < num;i++) {
        std::cin >> x;
        maxer = std::max(maxer,x);
    }
    std::cout << maxer;
    return 0;
}