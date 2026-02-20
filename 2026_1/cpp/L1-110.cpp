#include <iostream>
using namespace std;

void insertElm(int rawArr[], const int elm, const int index,int *N){
    for (int i = *N;i > index;i--) {
        rawArr[i] = rawArr[i-1];
    }
    rawArr[index] = elm;
}

void extendArr(int rawArr[],const int count,int index,int *N) {
    for (int i = *N + count - 1;i > index;i--) {
        rawArr[i] = rawArr[i - count];
    }
    *N = *N + count;
}

void decreaseArr(int rawArr[],const int count,int index,int *N,int L2) {
    for (int i = index + L2;i < *N - count;i++) {
        rawArr[i] = rawArr[i+count];
    }
    *N = *N - count;
}

void way1(int rawArr[],int *N){
    int L1,foundIndex = 0;
    bool found = false;
    cin >> L1;
    int arr[L1];
    for (int i = 0;i < L1;i++){
        cin >> arr[i];
    }
    int L2;
    for (int i = 0;i < *N;i++){
        bool isCorrect = true;
        for (int j = 0;j < L1;j++){
            if (i+j >= *N) {
                isCorrect = false;
                break;
            }
            if (arr[j] != rawArr[i+j]){
                isCorrect = false;
                break;
            }
        }
        if (isCorrect) {
            found = true;
            foundIndex = i;
            break;
        }
    }
    if (found) {
        cin >> L2;
        if (L2 > L1) {
            extendArr(rawArr,L2 - L1,foundIndex,N);
        }else {
            decreaseArr(rawArr,L1 - L2,foundIndex,N,L2);
        }
        for (int i = 0;i < L2;i++){
            cin >> rawArr[foundIndex+i];
        }
    }else {
        cin >> L2;
        int Loser;
        for (int i = 0;i < L2;i++){
            cin >> Loser;
        } // 只承接，不干别的，垃圾东西
    }

}

void way2(int rawArr[],int *N){
    for (int i = 1;i < *N;i++){
        if ((rawArr[i-1] + rawArr[i]) % 2 == 0){
            insertElm(rawArr,(rawArr[i-1] + rawArr[i])/2,i,N);
            i++;
            *N = *N + 1;
        }
    }
}

void way3(int rawArr[], int l, int r) {
    while (l < r) {
        int temp = rawArr[l];
        rawArr[l] = rawArr[r];
        rawArr[r] = temp;
        l++;
        r--;
    }
}

int main(){
    int N,M;
    cin >> N >> M;
    int rawArr[100*N];
    for (int i = 0;i < N;i++){
        cin >> rawArr[i];
    }
    for (int i = 0;i < M;i++){
        int way;
        cin >> way;
        if (way == 1) {
            way1(rawArr,&N);
        }else if (way == 2) {
            way2(rawArr,&N);
        }else {
            int l,r;
            cin >> l >> r;
            way3(rawArr,l - 1,r - 1);
        }
    }
    for (int i = 0;i < N;i++) {
        if (i != 0) cout << " ";
        cout << rawArr[i];
    }
    return 0;
}