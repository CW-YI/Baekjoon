#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
vector<vector<char>> star;

void basic_star(int i, int j) { // 기준 위치는 제일 왼쪽 끝 아래
    for (int k = 0; k < 5; k++) star[i][j + k] = '*';
    star[i - 1][j + 1] = '*'; star[i - 1][j + 3] = '*';
    star[i - 2][j + 2] = '*';
}

void rBuildStar(int i, int j, int size) { // size는 0 - k
    if (size == 0) {
        basic_star(i, j);
        return;
    }
    int newSize = pow(2, size - 1) * 3;
    rBuildStar(i, j, size - 1);
    rBuildStar(i, j + newSize * 2, size - 1);
    rBuildStar(i - newSize, j + newSize, size - 1);
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    star.resize(N, vector<char>((N / 3) * 6, ' '));

    rBuildStar(N - 1, 0, log2(N / 3));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < (N / 3) * 6; j++)
            cout << star[i][j];
        cout << "\n";
    }
    return 0;
}