#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int maxNum = 0, maxIndex = -1;
    for (int i = 0, n1; i < 9; i++) {
        cin >> n1;
        if (n1 > maxNum) { maxNum = n1; maxIndex = i + 1; }
    }

    cout << maxNum << "\n" << maxIndex;
    return 0;
}