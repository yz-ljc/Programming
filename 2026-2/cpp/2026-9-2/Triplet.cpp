#include <iostream>
using namespace std;

typedef char ElemType;
typedef ElemType * Triplet;

bool init(Triplet T, ElemType e1, ElemType e2, ElemType e3);
bool get(Triplet & T, ElemType e);
ElemType max(Triplet & T);