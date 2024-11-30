#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;
int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0,1} };

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int R, C, T;
    cin >> R >> C >> T;

    vector<vector<int>> v(R, vector<int>(C));
    vector<vector<pair<int, int>>> airConditioner(R, vector<pair<int, int>>(C, { 0, 0 }));

    queue<pair<int, int>> q; // x, y, 미세먼지 양, time

    int airRow = 0, airCol = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> v[i][j];
            if (v[i][j] > 0) q.push({ i, j });
            else if (v[i][j] == -1) { 
                airRow = i; airCol = j;// airConditioner[i][j] = { 2, 2 };
            }
        }
    }

    for (int j = 0; j < C - 1; j++) { // 우
        airConditioner[airRow - 1][j] = { 0, 1 };
        airConditioner[airRow][j] = { 0, 1 };
    }

    for (int j = 1; j < C; j++) { // 좌
        airConditioner[0][j] = { 0, -1 };
        airConditioner[R - 1][j] = { 0, -1 };
    }

    for (int i = airRow; i < R; i++) {
        if (i != R - 1)  airConditioner[i][C - 1] = { 1, 0 };
        if (i != airRow) airConditioner[i][0] = { -1, 0 };
    }

    for (int i = 0; i < airRow; i++) {
        if (i != 0) airConditioner[i][C - 1] = { -1, 0 };
        if (i != airRow - 1) airConditioner[i][0] = { 1, 0 };
    }

    for (int t = 0; t < T; t++) {
        vector<vector<int>> temp(R, vector<int>(C, 0));

        while (!q.empty()) {
            int curX = q.front().first, curY = q.front().second;
            q.pop();

            int count = 0;
            for (int i = 0; i < 4; i++) {
                int nextX = curX + dir[i][0], nextY = curY + dir[i][1];

                if (nextX < 0 || nextX >= R || nextY < 0 || nextY >= C) continue;
                if (v[nextX][nextY] == -1) continue;
                count++;

                temp[nextX][nextY] += v[curX][curY] / 5;
            }
            v[curX][curY] -= (v[curX][curY] / 5) * count;
        }

        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                v[i][j] += temp[i][j]; 

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                int nextX = airConditioner[i][j].first + i;
                int nextY = airConditioner[i][j].second + j;
                if (v[i][j] == -1) {
                    temp[i][j] = -1; temp[nextX][nextY] = 0;
                    continue;
                }

                if (v[nextX][nextY] == -1) continue;
                temp[nextX][nextY] = v[i][j];

                if (v[i][j] > 0) q.push({ nextX, nextY });
            }
        }

        v = temp;
    }

    int totalSum = 0;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            if (v[i][j] > 0) totalSum += v[i][j];

    cout << totalSum;
    return 0;
}