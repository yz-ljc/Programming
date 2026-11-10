#include <iostream>
#include <iomanip>
using namespace std;

typedef int QElemType;
typedef struct LNode {
    QElemType e;
    struct LNode * next;
} LNode;

typedef struct LinkQueue {
    LNode * front;
    LNode * rear;
} LinkQueue;

bool InitQueue_L(LinkQueue & q);
void EnQueue_L(LinkQueue &q, QElemType e);
void DeQueue_L(LinkQueue &q, QElemType &e);
void DestroyQueue_L(LinkQueue &q);
int QueueLength_L(LinkQueue q);
void QueueTraverse_L(LinkQueue q, void (*visit)(QElemType));

int QueueLength_L(LinkQueue q) {
    int i = 0;
    LNode * p = q.front->next;
    while (p) {
        i++;
        p = p->next;
    }
    
    return i;
}

void QueueTraverse_L(LinkQueue q, void (*visit)(QElemType)) {
    
    LNode * p = q.front->next;
    while (p) {
        visit(p->e);
        p = p->next;
    }
}

bool InitQueue_L(LinkQueue &q) {
    
    q.front = q.rear = new LNode;
    if (q.front == NULL) return false;
    
    q.front->next = NULL;
    return true;
}

void EnQueue_L(LinkQueue &q, QElemType e) {
    
    LNode * s = new LNode;
    s->e = e;
    s->next = NULL;
    
    q.rear->next = s;
    q.rear = s;
}

void DeQueue_L(LinkQueue &q, QElemType &e) {
    if (q.rear == q.front) return;    
    
    LNode *s = q.front->next;
    q.front->next = s->next;
    
    e = s->e;
    
    if (s == q.rear) {
        q.rear = q.front;
    }
    
    delete s;
}

void DestroyQueue_L(LinkQueue &q) {

    while (q.front) {
        q.rear = q.front->next;
        delete q.front;
        q.front = q.rear;
    }
}


void DisplayQueue(LinkQueue Q);
void DisplayElem(QElemType e); 
int main()
{
    LinkQueue Q;
	QElemType e;
	int i;
	if (InitQueue_L(Q))
		cout << "初始化链队列成功" << endl;
	else {
		cout << "初始化链队列失败" << endl;
		return 1;
	}
	cout << "请输入5个入队元素：" << endl;
	for (i=0; i<5; i++) {
		cin >> e;
		EnQueue_L(Q, e);
	}
	DisplayQueue(Q);
	cout << "出队4个元素"<<endl;
	for (i=0; i<4; i++)
		DeQueue_L(Q, e);
	DisplayQueue(Q);
	cout << "请再输入1个入队元素：" << endl;
	cin >> e;
	EnQueue_L(Q, e);
	DisplayQueue(Q);
	cout << "出队1个元素"<<endl;
	DeQueue_L(Q, e);
	DisplayQueue(Q);
	cout << "出队1个元素"<<endl;
	DeQueue_L(Q, e);
	DisplayQueue(Q);
	DestroyQueue_L(Q);
	cout << "队列已销毁"<<endl;
	return 0;
}
void DisplayQueue(LinkQueue Q)
{
	int n = QueueLength_L(Q);
	cout << "队列长度为" << n << endl;
	if (n > 0) {
		cout << "队列中元素为：";
		QueueTraverse_L(Q, DisplayElem);
		cout << endl;
	}
}
void DisplayElem(QElemType e){
    cout << e << " ";
}