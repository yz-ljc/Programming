#include <iostream>
#include <iomanip>
using namespace std;
// 循环队列的类型定义
const int QUEUESIZE = 100;
const int QINCREMENTSIZE = 10;
typedef int QElemType;

typedef struct {
    QElemType *elem;
    int front;
    int rear;
    int queuesize;
    int incrementsize;
} SqQueue;

// 循环队列基本操作的函数声明
bool InitQueue_Sq(SqQueue &Q, int maxsize = QUEUESIZE, int incresize = QINCREMENTSIZE);

bool DeQueue_Sq(SqQueue &Q, QElemType &e);

void EnQueue_Sq(SqQueue &Q, QElemType e);

void incrementQueuesize(SqQueue &Q);

bool QueueEmpty_Sq(SqQueue Q);

void GetHead_Sq(SqQueue Q, QElemType &e);

// 循环队列基本操作的函数定义
//构造一个空队列
bool InitQueue_Sq(SqQueue &Q, int maxsize, int incresize) {
    Q.elem = new QElemType[maxsize + 1];
    if (!Q.elem) {
        return false;
    }
    Q.queuesize = maxsize + 1;
    Q.incrementsize = incresize;
    Q.front = Q.rear = 0;
    return true;
}

//出队
bool DeQueue_Sq(SqQueue &Q, QElemType &e) {
    if (Q.front == Q.rear)
        return false;
    e = Q.elem[Q.front];
    Q.front = (Q.front + 1) % Q.queuesize;
    return true;
}

//取队首元素
void GetHead_Sq(SqQueue Q, QElemType &e) {
    e = Q.elem[Q.front];
}

//进队
void EnQueue_Sq(SqQueue &Q, QElemType e) {
    if ((Q.rear + 1) % Q.queuesize == Q.front)
        incrementQueuesize(Q);
    Q.elem[Q.rear] = e;
    Q.rear = (Q.rear + 1) % Q.queuesize;
}

//增加队列空间
void incrementQueuesize(SqQueue &Q) {
    QElemType *a = new QElemType[Q.queuesize + Q.incrementsize];
    for (int k = 0; k < Q.queuesize - 1; k++)
        a[k] = Q.elem[(Q.front + k) % Q.queuesize];
    delete []Q.elem;
    Q.elem = a;
    Q.front = 0;
    Q.rear = Q.queuesize - 1;
    Q.queuesize += Q.incrementsize;
}

//检验是否为空
bool QueueEmpty_Sq(SqQueue Q) {
    return Q.front == Q.rear ? true : false;
}

void Yanghui(int);

void Yanghui(int n) {
    SqQueue q;
    InitQueue_Sq(q);

    EnQueue_Sq(q, 1);

    for (int i = 0; i <= n; i++) {
        for (int k = 0; k < n - i; k++) {
            cout << "   ";
        }

        int x = 0, y;

        for (int j = 0; j <= i; j++) {
            DeQueue_Sq(q, y);
            cout << setw(3) << y;
            EnQueue_Sq(q, x + y);
            x = y;
        }

        EnQueue_Sq(q, 1);
        cout << endl;
    }

    delete[] q.elem;
}

int main() {
    int n;
    cout << "请输入杨辉三角的行数：" << endl;
    cin >> n;
    Yanghui(n);
    //    cout << "1";
    return 0;
}
