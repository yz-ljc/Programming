#include <iostream>

int main(){
    int F,C;
    std::cin >> F;
    C = 5 * (F - 32) / 9;
    std::cout << "Celsius = " << C <<std::endl;
    return 0;
}