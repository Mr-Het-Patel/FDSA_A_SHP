#include <iostream>
using namespace std;

int main() {
    int table[10], n, id;
    for (int i = 0; i < 10; i++)
        table[i] = -1;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> id;
        int h1 = id % 10;
        int h2 = 7 - (id % 7);
        int placed = 0;

        for (int j = 0; j < 10; j++) {
            int slot = (h1 + j * h2) % 10;
            if (table[slot] == -1) {
                table[slot] = id;
                placed = 1;
                break;
            }
        }

        if (!placed)
            cout << "No slot available for " << id << "\n";
    }

    for (int i = 0; i < 10; i++)
        cout << i << ": " << table[i] << "\n";

    return 0;
}
