#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int dir[4][2] = { {-1, 0},{1, 0} ,{0, -1} ,{0, 1} };
int N, babySize = 2;
vector<vector<int>> v;

pair<pair<int, int>, int> FindNextPos(pair<int, int> cur) {
    vector<vector<bool>> visit(N, vector<bool>(N, false));
    queue<pair<pair<int, int>, int>> q;

    visit[cur.first][cur.second] = true;
    q.push({ cur, 0 });

    int minTime = -1;
    pair<int, int> resultPos;

    while (!q.empty()) {
        pair<int, int> curPos = q.front().first;
        int curTime = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            pair<int, int> nextPos = { curPos.first + dir[i][0], curPos.second + dir[i][1] };

            if (nextPos.first < 0 || nextPos.first >= N || nextPos.second < 0 || nextPos.second >= N) continue;
            if (visit[nextPos.first][nextPos.second]) continue;
            if (v[nextPos.first][nextPos.second] > babySize) continue;

            visit[nextPos.first][nextPos.second] = true;
            q.push({ nextPos, curTime + 1 });

            if (v[nextPos.first][nextPos.second] < babySize && v[nextPos.first][nextPos.second] > 0) {
                if (minTime == -1) { minTime = curTime + 1; resultPos = nextPos; }
                else if (minTime == curTime + 1) {
                    if (nextPos.first < resultPos.first) resultPos = nextPos;
                    else if (nextPos.first == resultPos.first)
                        if (nextPos.second < resultPos.second) resultPos = nextPos;
                }
                //else return { resultPos, minTime };
            }
        }
    }
    if (minTime != -1) return { resultPos, minTime };
    return { cur, -1 };
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int upgradeSize = 0, totalTime = 0;
    cin >> N;
    v.resize(N, vector<int>(N));

    pair<int, int> curPos;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> v[i][j];
            if (v[i][j] == 9) { curPos = { i, j }; v[i][j] = 0; }
        }
    }

    while (true) {
        pair<pair<int, int>, int> temp = FindNextPos(curPos);
        pair<int, int> nextPos = temp.first;
        int time = temp.second;

        if (time == -1) break; 

        totalTime += time;
        if (++upgradeSize == babySize) { upgradeSize = 0; babySize++; }

        curPos = nextPos;
        v[curPos.first][curPos.second] = 0;
    }

    cout << totalTime;
    return 0;
}