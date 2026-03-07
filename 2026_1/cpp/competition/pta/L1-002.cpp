#include <iostream>

int main(){
    int count;
    char c;
    std::cin >> count >> c;
    int layer = 1;
    while (layer * layer * 2 - 1 <= count) {
        layer++;
    }
    layer--;
    int total = 2 * layer - 1;
    int used = (layer + layer * (layer - 1)) * 2 - 1;
    for (int i = 0;i < layer;i++){
        for (int j = 0;j < i;j++){
            std::cout << " ";
        }
        for (int j = 1;j <= total - i * 2;j++){
            std::cout << c;
        }
        std::cout << "\n";
    }
    for (int i = layer - 1;i > 0;i--){
        for (int j = 1;j < i;j++){
            std::cout << " ";
        }
        for (int j = total - (i - 1) * 2;j > 0;j--){
            std::cout << c;
        }
        std::cout << "\n";
    }
    std::cout << count - used;
}