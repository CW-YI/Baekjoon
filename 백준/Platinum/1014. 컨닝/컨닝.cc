#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N, M;
char grid[10][11];
int matched[105];
bool visited[105];
vector<int> adj[105];

int id(int r, int c) { return r * 10 + c; }

bool dfs(int u) {
    for (int v : adj[u]) {
        if (visited[v]) continue;
        visited[v] = true;
        if (matched[v] == -1 || dfs(matched[v])) {
            matched[v] = u;
            return true;
        }
    }
    return false;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int C;
    cin >> C;

    // 충돌 방향: 좌우(같은행) + 대각선(위아래 모두)
    int dr[] = {0,  0, -1, -1,  1,  1};
    int dc[] = {-1, 1, -1,  1, -1,  1};

    while (C--) {
        cin >> N >> M;
        for (int i = 0; i < N; i++) cin >> grid[i];

        for (int i = 0; i < 100; i++) adj[i].clear();
        memset(matched, -1, sizeof(matched));

        int total = 0;

        // 짝수 열(0,2,4...) → 홀수 열(1,3,5...) 간선 구성
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < M; c++) {
                if (grid[r][c] == 'x') continue;
                total++;
                if (c % 2 != 0) continue; // 짝수 열만 출발점

                int u = id(r, c);
                for (int d = 0; d < 6; d++) {
                    int nr = r + dr[d], nc = c + dc[d];
                    if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
                    if (grid[nr][nc] == 'x') continue;
                    if (nc % 2 == 0) continue; // 홀수 열만 도착점
                    adj[u].push_back(id(nr, nc));
                }
            }
        }

        int matching = 0;
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < M; c += 2) { // 짝수 열만
                if (grid[r][c] == 'x') continue;
                fill(visited, visited + 100, false);
                if (dfs(id(r, c))) matching++;
            }
        }

        // 최대 독립 집합 = 전체 - 최대 매칭 (쾨니그 정리)
        cout << total - matching << "\n";
    }

    return 0;
}