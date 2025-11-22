#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node(int x) {
        val = x;
        next = NULL;
    }
};

Node* getIntersectionNode(Node* A, Node* B) {
    Node* p = A;
    Node* q = B;

    while (p != q) {
        if (p == NULL) p = B;
        else p = p->next;

        if (q == NULL) q = A;
        else q = q->next;
    }

    return p;
}

int main() {
    
    Node* c1 = new Node(8);
    Node* c2 = new Node(10);
    Node* c3 = new Node(12);
    c1->next = c2;
    c2->next = c3;

    Node* a1 = new Node(3);
    Node* a2 = new Node(7);
    a1->next = a2;
    a2->next = c1;

    Node* b1 = new Node(99);
    Node* b2 = new Node(1);
    Node* b3 = new Node(5);
    b1->next = b2;
    b2->next = b3;
    b3->next = c1;

    Node* inter = getIntersectionNode(a1, b1);

    if (inter != NULL) {
        cout << "common point is at value " << inter->val << endl;
    } else {
        cout << "no intersection" << endl;
    }

    return 0;
}
