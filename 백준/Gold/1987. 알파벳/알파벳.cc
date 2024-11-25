#include <iostream>
#include <vector>
#include <queue>
#include <bitset>

using namespace std;
int N, M;
vector<vector<char>> v;
int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

int bfs() {
    queue<pair<pair<int, int>, int >> q;
    q.push({ {0, 0}, 1 << (v[0][0] - 'A') });
    unsigned int depth = 1;
    int dep = 1;

    while (!q.empty()) {
        int x = q.front().first.first, y = q.front().first.second;
        int visit = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int dx = x + dir[i][0], dy = y + dir[i][1];
            if (dx < 0 || dx >= N || dy < 0 || dy >= M) continue;
            
            int index = v[dx][dy] - 'A';
            if ((visit & (1 << index)) == 0) {
                q.push({ {dx, dy}, visit | (1 << index) });

                #if defined(_MSC_VER)
                    depth = max(depth, __popcnt(visit | (1 << index)));
                #else
                    dep = max(dep, __builtin_popcount(visit | (1 << index)));
                #endif
            }
        }
    }
    #if defined(_MSC_VER)
        return depth;
    #else
        return dep;
    #endif
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin >> N >> M;
    v.resize(N, vector<char>(M));

    string input;
    for (int i = 0; i < N; i++) {
        cin >> input;
        for (int j = 0; j < M; j++)
            v[i][j] = input[j];
    }

    cout << bfs();
    return 0;
}