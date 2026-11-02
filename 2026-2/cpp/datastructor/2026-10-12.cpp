#include <iostream>
using namespace std;

typedef struct Node {
    int d;
    struct Node * next;
} Node, * LNode;

int main() {
    Node * h = new Node;
    h -> next = nullptr;
    int a = 1;
    int b = 2;
    int c = 3;

    LNode l1 = new Node;
    l1 ->d = a;
    LNode l2 = new Node;
    l2->d = b;
    LNode l3 = new Node;
    l3->d = c;
    l1->next = l2;
    l2->next = l3;
    l3->next = l1;
    h->next = l1;

    // Node w = new Node;
    // w.d = 1;
    // w.d
    //
    cout << "h:       " << h << endl;
    cout << "l1:      " << l1 << endl;
    cout << "h->next: " << h->next << endl;
}