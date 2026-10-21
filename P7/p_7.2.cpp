#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    Node* front = NULL;
    Node* rear = NULL;

    int operations;
    cout << "Enter number of operations: ";
    cin >> operations;

    for (int i = 0; i < operations; i++) {
        int choice, patient;

        cout << "\n1. Arrive\n2. Attend\n";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter patient number: ";
            cin >> patient;

            Node* newNode = new Node;
            newNode->data = patient;
            newNode->next = NULL;

            if (rear == NULL) {
                front = rear = newNode;
            } 
            else {
                rear->next = newNode;
                rear = newNode;
            }

            cout << "Front patient: " << front->data << endl;
        }
        else if (choice == 2) {
            if (front == NULL) {
                cout << "Error: Queue is empty\n";
            } 
            else {
                Node* temp = front;
                front = front->next;

                delete temp;

                if (front == NULL)
                    rear = NULL;

                if (front != NULL)
                    cout << "Front patient: " << front->data << endl;
                else
                    cout << "Queue is empty\n";
            }
        }
    }

    return 0;
}
