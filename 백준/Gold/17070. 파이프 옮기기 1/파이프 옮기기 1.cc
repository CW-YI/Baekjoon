#include <iostream>
#include <vector>

using namespace std;

vector<vector<vector<int>>> dp;
vector<vector<int>> v;
int N;

int findSolution(int x, int y, int way) {
    if (x == N - 1 && y == N - 1) return 1; 
    if (dp[x][y][way] != -1) return dp[x][y][way];

    int n1 = 0, n2 = 0, n3 = 0;
    if (way != 1 && y + 1 < N && v[x][y + 1] == 0)
        n1 = findSolution(x, y + 1, 0);
    if (way != 0 && x + 1 < N && v[x + 1][y] == 0)
        n2 = findSolution(x + 1, y, 1);
    if (x + 1 < N && y + 1 < N && v[x + 1][y] == 0 && v[x][y + 1] == 0 && v[x + 1][y + 1] == 0)
        n3 = findSolution(x + 1, y + 1, 2);

    return dp[x][y][way] = n1 + n2 + n3;
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;

    v.resize(N, vector<int>(N));
    dp.resize(N, vector<vector<int>>(N, vector<int>(3, -1)));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> v[i][j];

    cout << findSolution(0, 1, 0);
    return 0;
}