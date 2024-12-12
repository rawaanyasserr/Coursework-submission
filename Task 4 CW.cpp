#include <iostream>
using namespace std;

void restrictedtowerofhanoi(int n, char source, char auxiliary, char destination, int& moveCount)
{
    if (n == 1) {
        cout << "Move disk " << n
            << " from rod " << source
            << " to " << auxiliary
            << " and then to " << destination << endl;
        moveCount += 2;
        return;
    }
    restrictedtowerofhanoi(n - 1, source, auxiliary, destination, moveCount);

    cout << "Move disk " << n << " from rod " << source << " to " << auxiliary << endl;
    moveCount++;

    restrictedtowerofhanoi(n - 1, destination, auxiliary, source, moveCount);
    cout << "Move disk " << n << " from rod " << auxiliary << " to " << destination << endl;
    moveCount++;

    restrictedtowerofhanoi(n - 1, source, auxiliary, destination, moveCount);
}

int main()
{
    int n;
    int moveCount = 0;
    cout << "Enter the number of disks: ";
    cin >> n;

    restrictedtowerofhanoi(n, 'A', 'B', 'C', moveCount);
    cout << "Total number of moves: " << moveCount << endl;

    return 0;
}
