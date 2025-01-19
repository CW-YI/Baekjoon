#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;
int N;
vector<vector<int>> map, dp;

int TSP(int visited, int curNode) {
    if (visited == (1 << N) - 1) return map[curNode][0] == 0 ? INF : map[curNode][0]; // 모든 지점 방문 완료

    if (dp[visited][curNode] != -1) return dp[visited][curNode]; // 이미 방문

    dp[visited][curNode] = INF;

    for (int nextNode = 0; nextNode < N; nextNode++) {
        if (visited & (1 << nextNode)) continue; // 이미 방문
        if (map[curNode][nextNode] == 0) continue; // 이동 불가

        dp[visited][curNode] = min(dp[visited][curNode], TSP(visited | (1 << nextNode), nextNode) + map[curNode][nextNode]);
    }

    return dp[visited][curNode];
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;
    map.resize(N, vector<int>(N)); dp.resize(1 << N, vector<int>(N, -1));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> map[i][j];

    cout << TSP(1, 0);
    return 0;
}