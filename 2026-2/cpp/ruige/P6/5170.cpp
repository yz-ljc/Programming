#include <iostream>
using namespace std;

typedef int QElemType;
typedef struct {
    QElemType * elms;
    int front;
    int rear;
    int size;
    int isize;
} SqQueue;

bool InitQueue_Sq(SqQueue & Q, int size, int isize) {
    Q.elms = new QElemType[size + 1];
    
    if (Q.elms == NULL) return false;
    
    Q.size = size;
    Q.isize = isize;
    Q.front = Q.rear = 0;
    return true;
}

int QueueLength_Sq(SqQueue Q) {
    return (Q.size + Q.rear - Q.front) % Q.size;
}

int DeQueue_Sq(SqQueue & Q, QElemType & e) {
    
    if (Q.rear == Q.front) return false;
    
    e = Q.elms[Q.front];
    
    Q.front = (Q.front + 1) % Q.size;
    return true;
}


int GetHeadElem_Sq(SqQueue Q) {
    return Q.elms[Q.front];
}

bool isFull(SqQueue Q) {
    return ((Q.rear + 1) % Q.size) == Q.front;
}

void iSize(SqQueue & Q) {
    QElemType * s = new QElemType[Q.size + Q.isize];
    
    for (int i = 0; i < Q.size; i++) {
        s[i] = Q.elms[i];
    }
    
    delete[] Q.elms;
    Q.elms = s;
    Q.rear = Q.size - 1;
    Q.size = Q.size + Q.isize;
    Q.front = 0;
}

void EnQueue_Sq(SqQueue & Q, QElemType e) {
    if (isFull(Q)) {
        iSize(Q);
    }
    
    Q.elms[Q.rear] = e;
    Q.rear = (Q.rear + 1) % Q.size;
}

void QueueTraverse_Sq(SqQueue Q, void (*visit)(QElemType)) {
    
    int len = QueueLength_Sq(Q);
    for (int i = 0; i < len; i++) {
        (*visit)(Q.elms[(Q.front + i) % Q.size]);
    }
}

bool QueueEmpty(SqQueue Q) {
    return Q.rear == Q.front;
}

void ClearQueue(SqQueue & Q) {
    Q.rear = Q.front = 0;
}

void DisplayElem(QElemType e) {
    cout << e << " ";
}

int main()
{
	SqQueue Q;
	QElemType e;
	int i;
	if (InitQueue_Sq(Q, 8, 2))
		cout << "初始化循环队列成功(8个元素空间)" << endl;
	else {
		cout << "初始化循环队列失败" << endl;
		return 1;
	}
	cout << "请输入10个入队元素：" << endl;
	for (i=0; i<10; i++) {
		cin >> e;
		EnQueue_Sq(Q, e);
	}
	cout << "队列长度为" << QueueLength_Sq(Q);
	cout << "队列中元素为：";
	QueueTraverse_Sq(Q, DisplayElem);
	cout << endl;
	cout << "出队5个元素"<<endl;
	for (i=0; i<5; i++)
		DeQueue_Sq(Q, e);
	cout << "队列长度为" << QueueLength_Sq(Q) << endl;
	cout << "队列中元素为：";
	QueueTraverse_Sq(Q, DisplayElem);
	cout << endl;
	cout << "请再输入6个入队元素：" << endl;
	for (i=0; i<6; i++) {
		cin >> e;
		EnQueue_Sq(Q, e);
	}
	cout << "队列长度为" << QueueLength_Sq(Q) << endl;
	cout << "队列中元素为：";
	QueueTraverse_Sq(Q, DisplayElem);
	cout << endl;
	ClearQueue(Q);
	if (QueueEmpty(Q))
		cout<<"队列已清空"<<endl;
    return 0;
}