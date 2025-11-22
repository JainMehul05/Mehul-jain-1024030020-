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

Node* rotateLeft(Node* head, int k) {
    if (head == NULL || head->next == NULL) return head;

    int n = 1;
    Node* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
        n++;
    }

    k = k % n;   
    if (k == 0) return head;

    Node* kth = head;
    for (int i = 1; i < k; i++) {
        kth = kth->next;
    }

    Node* newHead = kth->next;

    tail->next = head;
    kth->next = NULL;

    return newHead;
}
int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);

    int k = 2;   
    

    Node* newHead = rotateLeft(head, k);


    cout << "list after rotating left by " << k << ": ";
    Node* temp = newHead;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}

