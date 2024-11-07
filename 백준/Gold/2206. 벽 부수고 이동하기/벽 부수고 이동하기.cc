#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;
const int di[4] = { -1, 1, 0, 0 };
const int dj[4] = { 0, 0, -1, 1 };

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int N, M, result = -1;
    cin >> N >> M;

    vector<vector<int>> v(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < M; j++)
            v[i][j] = line[j] - '0';
    }
        
    vector<vector<int>> visit(N, vector<int>(M, -1));
    vector<vector<int>> visit_wall(N, vector<int>(M, -1));
    queue<tuple<int, int, int, int>> q;

    q.push(make_tuple(0, 0, 0, 1));
    visit[0][0] = 1;

    while (!q.empty()) {
        auto [i, j, k, cnt] = q.front();
        q.pop();

        for (int d = 0; d < 4; d++) {
            int ni = i + di[d], nj = j + dj[d];

            if (ni >= 0 && nj >= 0 && ni < N && nj < M) {
                if (k + v[ni][nj] == 1 && visit_wall[ni][nj] == -1) { // 벽뚫
                    visit_wall[ni][nj] = cnt + 1;
                    q.push(make_tuple(ni, nj, 1, cnt + 1));
                }
                else if (k + v[ni][nj] == 0 && visit[ni][nj] == -1) { // 벽뚫X
                    visit[ni][nj] = cnt + 1;
                    q.push(make_tuple(ni, nj, 0, cnt + 1));
                }
            }
        }
    }

    if (visit[N - 1][M - 1] != -1 && visit_wall[N - 1][M - 1] != -1) result = min(visit[N - 1][M - 1], visit_wall[N - 1][M - 1]);
    else result = (visit[N - 1][M - 1] != -1 ? visit[N - 1][M - 1] : visit_wall[N - 1][M - 1]);

    cout << result;
    return 0;
}