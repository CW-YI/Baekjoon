#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
int N, M;

int findNum(vector<vector<int>> v, queue<pair<int, int>> q) {
    while (!q.empty()) {
        auto [curX, curY] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nextX = curX + dir[i][0], nextY = curY + dir[i][1];

            if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= M) continue;
            if (v[nextX][nextY] != 0) continue;

            v[nextX][nextY] = 2;
            q.push({ nextX, nextY });
        }
    }

    int totalZero = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (v[i][j] == 0) totalZero++;

    return totalZero;
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin >> N >> M;

    vector<vector<int>> v(N, vector<int>(M));
    queue<pair<int, int>> q;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> v[i][j];
            if (v[i][j] == 2) q.push({ i, j });
        }
    }

    int maxNum = 0;
    for (int x1 = 0; x1 < N; x1++) {
        for (int y1 = 0; y1 < M; y1++) {
            if (v[x1][y1] != 0) continue;

            for (int x2 = 0; x2 < N; x2++) {
                for (int y2 = 0; y2 < M; y2++) {
                    if (v[x2][y2] != 0) continue;
                    if (x1 == x2 && y1 == y2) continue;

                    for (int x3 = 0; x3 < N; x3++) {
                        for (int y3 = 0; y3 < M; y3++) {
                            if (v[x3][y3] != 0) continue;
                            if (x3 == x2 && y3 == y2) continue;
                            if (x3 == x1 && y3 == y1) continue;

                            v[x1][y1] = v[x2][y2] = v[x3][y3] = 1;
                            maxNum = max(maxNum, findNum(v, q));
                            v[x1][y1] = v[x2][y2] = v[x3][y3] = 0;
                        }
                    }
                }
            }
        }
    }

    cout << maxNum;
    return 0;
}