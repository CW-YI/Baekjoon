#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int N, M;
const int dir[4][2] = { {-1, 0}, {1,0}, {0, -1}, {0, 1} };
vector<vector<int>> v;

void outsideAir(pair<int, int> startPos) {
    queue<pair<int, int>> q;
    q.push(startPos);
    v[startPos.first][startPos.second] = -1;

    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nextX = x + dir[i][0], nextY = y + dir[i][1];
            if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < M) {
                if (v[nextX][nextY] == 0) {
                    v[nextX][nextY] = -1;
                    q.push(make_pair(nextX, nextY));
                }
            }
        }
    }
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    v.resize(N, vector<int>(M, 0));
    queue<pair<int, int>> cheese, q, nextcheese;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> v[i][j];
            if (v[i][j] == 1) cheese.push(make_pair(i, j));
        }
    }

    outsideAir(make_pair(0, 0));
    int time = 0;
    while (!cheese.empty()) {
        while (!cheese.empty()) {
            int x = cheese.front().first, y = cheese.front().second;
            int outAir = 0;
            cheese.pop();
            for (int i = 0; i < 4; i++) {
                int nextX = x + dir[i][0], nextY = y + dir[i][1];
                if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < M)
                    if (v[nextX][nextY] == -1) outAir++;
                if (outAir == 2) break;
            }

            if (outAir == 2) q.push(make_pair(x, y));
            else nextcheese.push(make_pair(x, y));
        }
        time++;
        cheese = nextcheese;
        while (!nextcheese.empty()) nextcheese.pop();
        while (!q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop(); v[x][y] = -1;
            for (int i = 0; i < 4; i++) {
                int nextX = x + dir[i][0], nextY = y + dir[i][1];
                if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < M)
                    if (v[nextX][nextY] == 0) outsideAir(make_pair(x, y));
            }
        }
    }

    cout << time;

    return 0;
}