// ElemType的数据类型定义如下：
//  typedef struct {
//      KeyType key;
//      InfoType info;
//  }ElemType;
// 编写算法partition_Sq()，将顺序表中的元素以第一个元素的key为界划分成两部分，要求排在分界元素之前的元素，其key值都比分界元素小，而排在其后的元素，其key值都比分界元素大。
// 要求：先写出顺序表数据类型定义，再写算法。

#include <iostream>
using namespace std;

typedef int KeyType;
typedef int InfoType;

typedef struct {
    KeyType key;
    InfoType info;
} ElemType;

typedef struct SqList {
    ElemType * List;
    int length;
} SqList;

void partition_Sq(SqList* L) {

    if (L == nullptr || L->List == nullptr || L->length <= 1) return;

    ElemType et = L->List[0];
    KeyType kt = et.key;

    int low = 1;
    int high = L->length - 1;

    while (low <= high) {

        while (low <= high && L->List[low].key < kt) {
            low++;
        }
        while (low <= high && L->List[high].key > kt) {
            high--;
        }

        if (low <= high) {
            const ElemType tmp_e = L->List[low];
            L->List[low] = L->List[high];
            L->List[high] = tmp_e;
            low++;
            high--;
        }
    }

    L->List[0] = L->List[high];
    L->List[high] = et;
}
