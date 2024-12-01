#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
vector<pair<int, int>> emptySpace, virusList;
vector<vector<int>> v;
int N, M;

int findNum() {
    queue<pair<int, int>> q;
    vector<vector<int>> temp = v;
    for (const auto& virusPos : virusList)
        q.push(virusPos);

    while (!q.empty()) {
        auto [curX, curY] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nextX = curX + dir[i][0], nextY = curY + dir[i][1];

            if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= M) continue;
            if (temp[nextX][nextY] != 0) continue;

            temp[nextX][nextY] = 2;
            q.push({ nextX, nextY });
        }
    }

    int totalZero = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (temp[i][j] == 0) totalZero++;

    return totalZero;
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin >> N >> M;
    v.resize(N, vector<int>(M));
    

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> v[i][j];
            if (v[i][j] == 0) emptySpace.push_back({ i, j });
            if (v[i][j] == 2) virusList.push_back({ i, j });
        }
    }

    int maxNum = 0;
    int emptySize = emptySpace.size();
    for (int i = 0; i < emptySize; i++) {
        for (int j = i + 1; j < emptySize; j++) {
            for (int k = j + 1; k < emptySize; k++) {
                auto [x1, y1] = emptySpace[i];
                auto [x2, y2] = emptySpace[j];
                auto [x3, y3] = emptySpace[k];

                v[x1][y1] = v[x2][y2] = v[x3][y3] = 1;
                maxNum = max(maxNum, findNum());
                v[x1][y1] = v[x2][y2] = v[x3][y3] = 0;
            }
        }
    }

    cout << maxNum;
    return 0;
}