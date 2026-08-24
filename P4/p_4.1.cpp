#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};


void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val;
        if (temp->next != nullptr) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    
    ListNode* y1 = new ListNode(10);
    ListNode* y2 = new ListNode(20);
    ListNode* y3 = new ListNode(30); 
    ListNode* y4 = new ListNode(40);
    ListNode* y5 = new ListNode(50);
    ListNode* y6 = new ListNode(60);

    y1->next = y2;
    y2->next = y4; 
    y4->next = y5;
    y5->next = y6;

    ListNode* head = y1;
    cout << "Original List: ";
    printList(head);

    
    ListNode* start = new ListNode(0);
    ListNode* mid = new ListNode(35);
    ListNode* end = new ListNode(70);

    
    start->next = head;
    head = start; 
    cout << "\nAfter Beginning Insertion: ";
    printList(head);

    
    ListNode* temp = head;
    while (temp->next != nullptr) { 
        temp = temp->next;
    }
    temp->next = end; 
    cout << "After Last Insertion: ";
    printList(head);

    ListNode* p = head;
    for (int i = 0; i < 2; i++) {
        if (p != nullptr) p = p->next;
    }
    mid->next = p->next;
    p->next = mid;
    cout << "After Mid Insertion: ";
    printList(head);


    return 0;
}
