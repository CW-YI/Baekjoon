#include <iostream>
#include <vector>

using namespace std;
int N, M;
vector<vector<char>> v;
vector<bool> visit(26, false);
int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

int dp(int x, int y, int depth) {
    int num = depth;
    for (int d = 0; d < 4; d++) {
        int dx = x + dir[d][0], dy = y + dir[d][1];
        if (dx < 0 || dx >= N || dy < 0 || dy >= M) continue;

        if (!visit[v[dx][dy] - 'A']) {
            visit[v[dx][dy] - 'A'] = true;
            int temp = dp(dx, dy, depth + 1);
            num = max(num, temp);
            visit[v[dx][dy] - 'A'] = false;
        }
    }
    return num;
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

    visit[v[0][0] - 'A'] = true;
    cout << dp(0, 0, 1);
    return 0;
}