#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;
int N, M;
int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0,1} }; // 상 하 좌 우
queue<tuple<vector<vector<char>>, int, pair<int, int>, pair<int, int>, pair<int, int>>> q;

pair<int, int> MoveBall(vector<vector<char>>& v, pair<int, int> pos, pair<int, int> nextDir) {
    while (pos.first + nextDir.first < N && pos.first + nextDir.first >= 0
        && pos.second + nextDir.second < M && pos.second + nextDir.second >= 0
        && v[pos.first + nextDir.first][pos.second + nextDir.second] == '.') {

            pos.first += nextDir.first; pos.second += nextDir.second;
    }

    if (pos.first + nextDir.first < N && pos.first + nextDir.first >= 0
        && pos.second + nextDir.second < M && pos.second + nextDir.second >= 0
        && v[pos.first + nextDir.first][pos.second + nextDir.second] == 'O') 
        return { -1, -1 };

    return pos;
}

bool CheckBall(vector<vector<char>> curV, bool R_first, pair<int, int> R_pos, pair<int, int> B_pos, pair<int, int> nextDir, int count) {
    bool R_ok = false, B_ok = false;

    if (R_first) { // 빨간공 먼저
        curV[R_pos.first][R_pos.second] = '.';
        R_pos = MoveBall(curV, R_pos, nextDir);

        if (R_pos == make_pair(-1, -1)) R_ok = true;
        else curV[R_pos.first][R_pos.second] = 'R';
    }

    curV[B_pos.first][B_pos.second] = '.'; // 파란 공
    B_pos = MoveBall(curV, B_pos, nextDir);

    if (B_pos == make_pair(-1, -1)) B_ok = true;
    else curV[B_pos.first][B_pos.second] = 'B';

    if (!B_ok && !R_first) { // 빨간공 나중
        curV[R_pos.first][R_pos.second] = '.';
        R_pos = MoveBall(curV, R_pos, nextDir);

        if (R_pos == make_pair(-1, -1)) R_ok = true;
        else curV[R_pos.first][R_pos.second] = 'R';
    }

    // print
    /*for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << curV[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "-------------------------\n";*/

    // 공이 빠졌는지 확인
    if (B_ok) return false;
    else if (R_ok) return true;
    else q.push({ curV, count + 1 , R_pos, B_pos, nextDir});

    return false;
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;

    vector<vector<char>> v(N, vector<char>(M));
    pair<int, int> R_pos, B_pos;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> v[i][j];
            if (v[i][j] == 'R') R_pos = { i, j };
            else if (v[i][j] == 'B') B_pos = { i, j };
        }
    }

    // v, count, R_pos, B_pos
    q.push({ v, 1,  R_pos, B_pos , {-1, -1} });

    while (!q.empty()) {
        auto [curV, count, R_pos, B_pos, prevDir] = q.front();
        q.pop();

        if (count > 10) break;
        
        for (int i = 0; i < 4; i++) {
            pair<int, int> nextDir = { dir[i][0], dir[i][1] };
            if (prevDir.first * (-1) == nextDir.first && prevDir.second * (-1) == nextDir.second) continue;

            bool R_first = true;

            /*if (i == 0) cout << "상\n";
            else if (i == 1) cout << "하\n";
            else if (i == 2) cout << "좌\n";
            else cout << "우\n";*/

            if ((i == 0 && R_pos.second == B_pos.second && B_pos.first < R_pos.first)
                || (i == 1 && R_pos.second == B_pos.second && B_pos.first > R_pos.first)
                || (i == 2 && R_pos.first == B_pos.first && B_pos.second < R_pos.second)
                || (i == 3 && R_pos.first == B_pos.first && B_pos.second > R_pos.second))
                    R_first = false; // 파란공 먼저
            
            if (CheckBall(curV, R_first, R_pos, B_pos, nextDir, count)) { cout << count; return 0; }
        }
    }
    
    cout << -1;
    return 0;
}