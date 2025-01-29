#include <iostream>
#include <vector>
#include <queue>
#include <cctype>
using namespace std;

int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, M, R;
    cin >> R;

    for (int r = 0; r < R; r++) {
        cin >> N >> M;
        int total = 0;

        vector<vector<pair<char, bool>>> v(N, vector<pair<char, bool>>(M, { '.', false }));
        vector<pair<bool, bool>> doorNkey(26, { false, false });
        vector<vector<pair<int, int>>> doorPos(26);

        queue<pair<int, int>> mainQ;

        char temp;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> temp;
                v[i][j] = { temp, false };

                // 벽이 아닐 경우 탐색 큐에 삽입
                if ((i == 0 || j == 0 || i == N - 1 || j == M - 1) && v[i][j].first != '*') 
                    mainQ.push({ i,j });
            }
        }

        string inputKey;
        cin >> inputKey;

        if (inputKey != "0") {
            for (const char ch : inputKey) // 가지고 있는 열쇠 저장
                doorNkey[ch - 'a'].second = true;
        }

        while (!mainQ.empty()) {
            while (!mainQ.empty()) {
                auto [curX, curY] = mainQ.front();
                char curCh = v[curX][curY].first;
                mainQ.pop();

                //cout << curX << " " << curY << " : " << curCh << " \n";

                if (v[curX][curY].second) continue;

                if (isupper(curCh)) { // 대문자일 경우
                    char ch = tolower(curCh);
                    if (doorNkey[ch - 'a'].second) v[curX][curY] = { '.', true }; // 열쇠가 존재
                    else {
                        doorNkey[curCh - 'A'].first = true; // 입구 발견
                        doorPos[curCh - 'A'].push_back({ curX, curY }); // 좌표 저장
                    }
                }
                else if (islower(curCh)) { // 소문자일 경우
                    doorNkey[curCh - 'a'].second = true;
                    v[curX][curY] = { '.', true };
                }
                else if (curCh == '$') { // 문서일 경우
                    total += 1;
                    v[curX][curY] = { '.', true };
                }
                else v[curX][curY].second = true;

                if (v[curX][curY].second) { // 해당 위치를 탐색한게 맞는 경우, 탐색을 계속 시도
                    for (int i = 0; i < 4; i++) {
                        int nextX = curX + dir[i][0];
                        int nextY = curY + dir[i][1];

                        if (nextX >= N || nextX < 0 || nextY >= M || nextY < 0) continue;

                        //cout << "next : " << nextX << " " << nextY << " : " << v[nextX][nextY].first << "\n";
                        if (!v[nextX][nextY].second && v[nextX][nextY].first != '*')
                            mainQ.push({ nextX, nextY });
                    }
                }
            }

            for (int i = 0; i < 26; i++) // 만약 문과 열쇠가 둘 다 true일 경우
                if (doorNkey[i].first && doorNkey[i].second)
                    for (const auto [x, y] : doorPos[i]) // 해당 문 위치를 탐색 큐에 삽입
                        if (!v[x][y].second) mainQ.push({ x, y });
        }

        cout << total << "\n";
    }

    return 0;
}