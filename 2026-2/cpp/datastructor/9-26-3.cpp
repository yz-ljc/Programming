// 编写算法DivideList_Sq()，将整型顺序表A复制到两个顺序表B和C，其中：顺序表B是A中的所有值为奇数的数据元素，顺序表C是A中的所有值为偶数的数据元素。
// 要求：先写出数据类型定义，再写算法。

#include <iostream>
using namespace std;

typedef struct SqList {
    int *List;
    int length;
} SqList;

bool DivideList_Sq(SqList A, SqList &B, SqList &C);

bool DivideList_Sq(SqList A, SqList &B, SqList &C) {
    if (A.List == nullptr || A.length == 0) return false;

    int *p = &A.List[0];
    int b = 0;
    int c = 0;
    for (int i = 0; i < A.length; i++) {
        if (*p % 2 == 0) {
            C.List[c++] = *p;
        } else {
            B.List[b++] = *p;
        }

        p++;
    }

    B.length = b;
    C.length = c;

    return true;
}
