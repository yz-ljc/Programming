#include <iostream>
long long num;

int main() {
    std::cin >> num;
    long long start = 0;
    long long maxLen = 0;
    long long len = 0;
    for (long long i = 2;i * i <= num;i++) {
        long long tmp = num;
        long long j = i;
        while (tmp % j == 0) {
            len++;
            tmp /= j;
            j++;
        }
        if (len > maxLen) {
            maxLen = len;
            start = i;
        }
        len = 0;
    }
    if (maxLen == 0) {
        std::cout << "1" << std::endl;
        std::cout << num << std::endl;
    }else {
        std::cout << maxLen << std::endl;
        for (int i = 0;i < maxLen;i++) {
            if (i > 0) std::cout << "*";
            std::cout << start + i;
        }
    }
    return 0;
}

// int main() {
//     std::cin >> num;
//     long long arr[num / 10 +2];
//     long long j = 0;
//     for (long long i = 2;i < num;i++) {
//         if (num % i == 0) {
//             arr[j++] = i;
//             num /= i;
//         }
//     }
//     long long finalArr[j];
//     long long resultArr[j];
//     long long maxer = 0;
//     long long count1 = 1;
//     finalArr[0] = arr[0];
//     for (long i = 1;i < j;i++) {
//         if (arr[i] - arr[i-1] == 1) {
//             finalArr[count1] = arr[i];
//             count1++;
//         }else {
//             if (count1 >= maxer) {
//                 maxer = count1;
//                 for (int k = 0;k < count1;k++) {
//                     resultArr[k] = finalArr[k];
//                 }
//             }
//             count1 = 1;
//             finalArr[0] = arr[i];
//         }
//     }
//     std::cout << maxer << std::endl;
//     for (long i = 0;i < maxer;i++) {
//         if (i == 0) std::cout << resultArr[0];
//         std::cout << "*" << resultArr[i];
//     }
//     return 0;
// }