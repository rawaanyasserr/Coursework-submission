#include <iostream>
using namespace std;

void disksorting(char disks[], int n) {
    int moves = 0;
    for (int i = 0; i < n; ++i) {
        for (int i = 0; i < 2 * n - 1; ++i) {
            if (disks[i] == 'd' && disks[i + 1] == 'l') {
                swap(disks[i], disks[i + 1]);
                moves++;
            }
        }
    }

    cout << "Final ordering: ";
    for (int i = 0; i < 2 * n; ++i) {
        cout << disks[i] << " ";
    }
    cout << endl;
    cout << "Total moves: " << moves << endl;
}

int main() {
    int n = 3;
    char disks[] = { 'd', 'l', 'd', 'l', 'd', 'l' };

    cout << "Initial ordering: ";
    for (int i = 0; i < 2 * n; ++i) {
        cout << disks[i] << " ";
    }
    cout << endl;

    disksorting(disks, n);

    return 0;
}