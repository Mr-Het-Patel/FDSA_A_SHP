#include <iostream>
#include <string>

using namespace std;

struct Customer {
    int id;
    string name;
    string priority;
};

class SimpleQueue {
private:
    Customer arr[100]; 
    int capacity;
    int front;
    int rear;

public:
    SimpleQueue(int size) {
        capacity = size;
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return (rear == capacity - 1);
    }

    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    void enqueue(int id, string name, string priority) {
        if (isFull()) {
            cout << "Queue is Full! Cannot add customer.\n";
            return;
        }
        if (front == -1) {
            front = 0;
        }
        rear++;
        arr[rear].id = id;
        arr[rear].name = name;
        arr[rear].priority = priority;
        cout << "Customer added successfully at index " << rear << "\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty! No one to serve.\n";
            return;
        }
        cout << "Served: " << arr[front].name << " (ID: " << arr[front].id << ")\n";
        front++;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Next customer to serve: " << arr[front].name << " (ID: " << arr[front].id << ")\n";
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "\n--- Waiting Customers ---\n";
        for (int i = front; i <= rear; i++) {
            cout << "Index [" << i << "] -> ID: " << arr[i].id << ", Name: " << arr[i].name << ", Priority: " << arr[i].priority << "\n";
        }
    }

    void search(int searchId) {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        for (int i = front; i <= rear; i++) {
            if (arr[i].id == searchId) {
                cout << "Found! " << arr[i].name << " is at index [" << i << "]\n";
                return;
            }
        }
        cout << "Customer not found.\n";
    }

    int count() {
        if (isEmpty()) return 0;
        return (rear - front + 1);
    }
};

int main() {
    int size;
    cout << "Enter queue size: ";
    cin >> size;

    SimpleQueue q(size);
    int choice;

    do {
        cout << "\n1. Enqueue (Add)\n";
        cout << "2. Dequeue (Serve)\n";
        cout << "3. Peek\n";
        cout << "4. Display All\n";
        cout << "5. Search by ID\n";
        cout << "6. Count\n";
        cout << "7. Check Full/Empty\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int id;
                string name, priority;
                cout << "Enter Customer ID: ";
                cin >> id;
                cout << "Enter Customer Name: ";
                cin >> name;
                cout << "Enter Priority (High/Normal/Low): ";
                cin >> priority;
                q.enqueue(id, name, priority);
                break;
            }
            case 2:
                q.dequeue();
                break;
            case 3:
                q.peek();
                break;
            case 4:
                q.display();
                break;
            case 5: {
                int id;
                cout << "Enter ID to search: ";
                cin >> id;
                q.search(id);
                break;
            }
            case 6:
                cout << "Total waiting customers: " << q.count() << "\n";
                break;
            case 7:
                cout << "Is Full? " << (q.isFull() ? "Yes" : "No") << "\n";
                cout << "Is Empty? " << (q.isEmpty() ? "Yes" : "No") << "\n";
                break;
            case 8:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 8);

    return 0;
}
