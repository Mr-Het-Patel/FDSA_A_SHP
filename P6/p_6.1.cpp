#include <iostream>
#include <string>
#include <stack>

using namespace std;

class TrayStack {
private:
    stack<string> trays;
    int capacity;

public:
    TrayStack(int n) {
        capacity = n;
    }

    void placeTray(string trayID) {
        if (trays.size() == capacity) {
            cout << "Error: Stack is full" << endl;
            return;
        }
        trays.push(trayID);
        cout << trays.top() << endl;
    }

    void takeTray() {
        if (trays.empty()) {
            cout << "Error: Stack is empty" << endl;
            return;
        }
        trays.pop();
        if (trays.empty()) {
            cout << "Empty" << endl;
        } else {
            cout << trays.top() << endl;
        }
    }
};

int main() {
    TrayStack counter(3);

    counter.placeTray("Tray1");
    counter.placeTray("Tray2");
    counter.placeTray("Tray3");
    counter.placeTray("Tray4");

    counter.takeTray();
    counter.takeTray();
    counter.takeTray();
    counter.takeTray();

    return 0;
}
