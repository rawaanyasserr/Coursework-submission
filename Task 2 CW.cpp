#include <iostream>
using namespace std;

void FakeCoin(int coin1, int coin2, int coin3) {
    if (coin1 == coin2) {
        cout << "The fake coin is coin 3; however, its weight in unknwon so it's unknown whether it's heavier or lighter." << endl;
    }
    else if (coin1 > coin2) {
        cout << "Coin 1 is heavier or Coin 2 is lighter." << endl;
    }
    else {
        cout << "Coin 2 is heavier or Coin 1 is lighter." << endl;
    }
}

int main() {
    int coin1 = 1;
    int coin2 = 1;
    int coin3 = 2;

    FakeCoin(coin1, coin2, coin3);
    return 0;
}
