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

Node* reverseK(Node* head, int k) {
    Node* curr = head;
    int count = 0;  

    while (curr != NULL && count < k) {
        curr = curr->next;
        count++;
    }
                             

    curr = head;
    Node* prev = NULL;
    Node* next = NULL;
    count = 0;

    while (curr != NULL && count < k) {
        next = curr->next;                 
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    head->next = reverseK(curr, k);  
    return prev; 
}

int main() {
    Node* h1 = new Node(1);
    h1->next = new Node(2);
    h1->next->next = new Node(3);
    h1->next->next->next = new Node(4);
    h1->next->next->next->next = new Node(5);
    h1->next->next->next->next->next = new Node(6);
    h1->next->next->next->next->next->next = new Node(7);
    int k = 3;

    Node* newHead = reverseK(h1, k);

    cout << "list after reversing " << ": ";
    Node* temp = newHead;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}