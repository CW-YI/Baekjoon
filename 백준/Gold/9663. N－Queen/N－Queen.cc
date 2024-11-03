#include <iostream>
#include <vector>
using namespace std;

int N;
vector<bool> colV, dialogL, dialogR;

int findNum(int row) {
    if (row == N) return 1;

    int sum = 0;
    for (int i = 0; i < N; i++) {
        if (colV[i] || dialogL[row - i + N - 1] || dialogR[row + i]) continue;

        colV[i] = dialogL[row - i + N - 1] = dialogR[row + i] = true;
        sum += findNum(row + 1);
        colV[i] = dialogL[row - i + N - 1] = dialogR[row + i] = false;
    }
    return sum;
}

int main() {
    cin >> N;

    colV.resize(N, false); dialogL.resize(2 * N, false); dialogR.resize(2 * N, false);
    cout << findNum(0);
    return 0;
}