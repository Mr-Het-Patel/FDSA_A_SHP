#include <iostream>
using namespace std;

int main() {
    int table[10], n, id;
    for (int i = 0; i < 10; i++)
        table[i] = -1;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> id;
        int slot = id % 10, tries = 0;

        while (table[slot] != -1 && tries < 10) {
            slot = (slot + 1) % 10;
            tries++;
        }

        if (tries == 10)
            cout << "Parking lot full for " << id << "\n";
        else
            table[slot] = id;
    }

    for (int i = 0; i < 10; i++)
        cout << i << ": " << table[i] << "\n";

    return 0;
}
