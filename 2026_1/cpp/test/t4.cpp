#include <iostream>

class Example {
    int n;
    int *arr;
public:
    Example(int n, int *arr) {
        this->n = n;
        this->arr = new int[n];
        for (int i = 0; i < n; i++) {
            this->arr[i] = arr[i];
        }
    }

    Example(Example & e) {
        this->n = e.n;
        int *t = new int[e.n];
        for (int i = 0; i < n; i++) {
            t[i] = e.arr[i];
        }
        this->arr = t;
    }

    ~Example() {
        delete[] arr;
    }
};