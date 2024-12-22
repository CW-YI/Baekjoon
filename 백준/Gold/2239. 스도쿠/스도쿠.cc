#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v(9, vector<int>(9, 0));
vector<pair<int, int>> zeroInput;
int inputSize = 0;

void printAnswer() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++)
            cout << v[i][j];
        cout << "\n";
    }
    exit(0);
}

bool checkSqaure(int x, int y, int num) {
    int findX = x / 3, findY = y / 3;
    for (int i = findX * 3; i < findX * 3 + 3; i++)
        for (int j = findY * 3; j < findY * 3 + 3; j++)
            if (v[i][j] == num) return false;
    return true;
}

bool checkRow(int x, int num) {
    for (int i = 0; i < 9; i++)
        if (v[x][i] == num) return false;
    return true;
}

bool checkCol(int y, int num) {
    for (int i = 0; i < 9; i++)
        if (v[i][y] == num) return false;
    return true;
}

void FindAnswer(int zeroIndex) {
    if (zeroIndex >= inputSize) return;

    auto [x, y] = zeroInput[zeroIndex];

    for (int i = 1; i <= 9; i++) {
        if (!checkSqaure(x, y, i) || !checkRow(x, i) || !checkCol(y, i)) continue;

        v[x][y] = i;
        if (zeroIndex == inputSize - 1) printAnswer();

        FindAnswer(zeroIndex + 1);
        v[x][y] = 0;
    }
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    string input;
    for (int i = 0; i < 9; i++) {
        cin >> input;
        int size = input.size();

        for (int j = 0; j < size; j++) {
            v[i][j] = input[j] - '0';
            if (v[i][j] == 0) zeroInput.push_back({ i, j });
        }
    }
    inputSize = zeroInput.size();
    FindAnswer(0);

    return 0;
}