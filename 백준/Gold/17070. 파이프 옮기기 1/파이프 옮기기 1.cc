#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> v;
int N;

int findSolution(pair<int, int> startPos, pair<int, int> endPos, int way) { // 가로 0 세로 1 대각선 2
    if (endPos == make_pair(N - 1, N - 1)) return 1;

    int n1 = 0, n2 = 0, n3 = 0;
    if (way != 1 && endPos.second + 1 < N && v[endPos.first][endPos.second + 1] == 0)
        n1 = findSolution(endPos, { endPos.first, endPos.second + 1 }, 0);
    if (way != 0 && endPos.first + 1 < N && v[endPos.first + 1][endPos.second] == 0)
        n2 = findSolution(endPos, { endPos.first + 1, endPos.second}, 1);
    if (endPos.first + 1 < N && endPos.second + 1 < N)
        if (v[endPos.first + 1][endPos.second] == 0 && v[endPos.first][endPos.second + 1] == 0 && v[endPos.first + 1][endPos.second + 1] == 0)
            n3 = findSolution(endPos, { endPos.first + 1, endPos.second + 1 }, 2);

    return n1 + n2 + n3;
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;

    v.resize(N, vector<int>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> v[i][j];

    cout << findSolution({ 0, 0 }, { 0, 1 }, 0);
    return 0;
}