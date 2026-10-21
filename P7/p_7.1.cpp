#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter queue size: ";
    cin >> n;

    int q[100];
    int front = 0, rear = -1;
    int count = 0;

    int operations;
    cout << "Enter no. of operations: ";
    cin >> operations;

    for (int i = 0; i < operations; i++) {
        int choice, token;

        cout << "\n1. Join\n2. Serve\n";
        cin >> choice;

        if (choice == 1) {
            if (count == n) {
                cout << "Error: Queue is full\n";
            } 
            else {
                cout << "Enter token: ";
                cin >> token;

                rear = (rear + 1) % n;
                q[rear] = token;
                count++;

                cout << "Front token: " << q[front] << endl;
            }
        }
        else if (choice == 2) {
            if (count == 0) {
                cout << "Error: Queue is empty\n";
            } 
            else {
                front = (front + 1) % n;
                count--;

                if (count == 0)
                    cout << "Queue is empty\n";
                else
                    cout << "Front token: " << q[front] << endl;
            }
        }
    }

    return 0;
}
