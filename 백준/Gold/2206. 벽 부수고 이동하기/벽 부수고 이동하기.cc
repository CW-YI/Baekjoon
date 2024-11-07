#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int N, M;
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

        if (i - 1 >= 0 ) { // 상
            if (k == 0 && visit_wall[i - 1][j] == -1 && v[i - 1][j] == 1) { // 이번 차례에 벽뚫
                visit_wall[i - 1][j] = cnt + 1;
                q.push(make_tuple(i - 1, j, 1, cnt + 1));
            }
            else if (k == 0 && visit[i - 1][j] == -1 && v[i - 1][j] == 0) { // 벽뚫 한 적X
                visit[i - 1][j] = cnt + 1;
                q.push(make_tuple(i - 1, j, 0, cnt + 1));
            }
            else if (k == 1 && visit_wall[i - 1][j] == -1 && v[i - 1][j] == 0) { // 벽뚫 이미 함
                visit_wall[i - 1][j] = cnt + 1;
                q.push(make_tuple(i - 1, j, 1, cnt + 1));
            }
        }
        if (i + 1 < N) { // 하
            if (k == 0 && visit_wall[i + 1][j] == -1 && v[i + 1][j] == 1) {
                visit_wall[i + 1][j] = cnt + 1;
                q.push(make_tuple(i + 1, j, 1, cnt + 1));
            }
            else if (k == 0 && visit[i + 1][j] == -1 && v[i + 1][j] == 0) {
                visit[i + 1][j] = cnt + 1;
                q.push(make_tuple(i + 1, j, 0, cnt + 1));
            }
            else if (k == 1 && visit_wall[i + 1][j] == -1 && v[i + 1][j] == 0) {
                visit_wall[i + 1][j] = cnt + 1;
                q.push(make_tuple(i + 1, j, 1, cnt + 1));
            }
        }
        if (j - 1 >= 0) { // 좌
            if (k == 0 && visit_wall[i][j - 1] == -1 && v[i][j - 1] == 1) {
                visit_wall[i][j - 1] = cnt + 1;
                q.push(make_tuple(i, j - 1, 1, cnt + 1));
            }
            else if (k == 0 && visit[i][j - 1] == -1 && v[i][j - 1] == 0) {
                visit[i][j - 1] = cnt + 1;
                q.push(make_tuple(i, j - 1, 0, cnt + 1));
            }
            else if (k == 1 && visit_wall[i][j - 1] == -1 && v[i][j - 1] == 0) {
                visit_wall[i][j - 1] = cnt + 1;
                q.push(make_tuple(i, j - 1, 1, cnt + 1));
            }
        }
        if (j + 1 < M) { // 우
            if (k == 0 && visit_wall[i][j + 1] == -1 && v[i][j + 1] == 1) {
                visit_wall[i][j + 1] = cnt + 1;
                q.push(make_tuple(i, j + 1, 1, cnt + 1));
            }
            else if (k == 0 && visit[i][j + 1] == -1 && v[i][j + 1] == 0) {
                visit[i][j + 1] = cnt + 1;
                q.push(make_tuple(i, j + 1, 0, cnt + 1));
            }
            else if (k == 1 && visit_wall[i][j + 1] == -1 && v[i][j + 1] == 0) {
                visit_wall[i][j + 1] = cnt + 1;
                q.push(make_tuple(i, j + 1, 1, cnt + 1));
            }
        }
    }

    int result = -1;
    if (visit[N - 1][M - 1] != -1 && visit_wall[N - 1][M - 1] != -1) result = min(visit[N - 1][M - 1], visit_wall[N - 1][M - 1]);
    else if (visit[N - 1][M - 1] == -1) result = visit_wall[N - 1][M - 1];
    else if (visit_wall[N - 1][M - 1] == -1) result = visit[N - 1][M - 1];

    cout << result;

    return 0;
}