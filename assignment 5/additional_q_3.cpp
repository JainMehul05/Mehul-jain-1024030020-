#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

void removeLoop(ListNode* head) {
    if (head == NULL || head->next == NULL) return;

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;
    }

    if (slow != fast) return;
    slow = head;
    if (slow == fast) {
        while (fast->next != slow) {
            fast = fast->next;
        }
        fast->next = NULL;
        return;
    }
    while (slow->next != fast->next) {
        slow = slow->next;
        fast = fast->next;
    }
    fast->next = NULL;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    head->next->next->next->next->next = head->next->next;

    removeLoop(head);

    ListNode* temp = head;
    cout << "list after removing loop: ";
    int count = 0;
    while (temp != NULL && count < 20) {  
        cout << temp->val << " ";
        temp = temp->next;
        count++;
    }
    cout << endl;

    return 0;
}
