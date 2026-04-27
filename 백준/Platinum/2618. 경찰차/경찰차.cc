#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;

int N, W;
int er[1001], ec[1001];
int memo[1001][1001];
bool visited[1001][1001];
int assign_arr[1001];

int pos1r(int i) { return i == 0 ? 1 : er[i]; }
int pos1c(int i) { return i == 0 ? 1 : ec[i]; }
int pos2r(int j) { return j == 0 ? N : er[j]; }
int pos2c(int j) { return j == 0 ? N : ec[j]; }

int getDist(int r1, int c1, int r2, int c2) {
    return abs(r1 - r2) + abs(c1 - c2);
}

int solve(int i, int j) {
    int nxt = (i > j ? i : j) + 1;
    if (nxt > W) return 0;
    if (visited[i][j]) return memo[i][j];
    visited[i][j] = true;

    int cost1 = getDist(pos1r(i), pos1c(i), er[nxt], ec[nxt]) + solve(nxt, j);
    int cost2 = getDist(pos2r(j), pos2c(j), er[nxt], ec[nxt]) + solve(i, nxt);

    return memo[i][j] = (cost1 < cost2 ? cost1 : cost2);
}

void traceback(int i, int j) {
    int nxt = (i > j ? i : j) + 1;
    if (nxt > W) return;

    int cost1 = getDist(pos1r(i), pos1c(i), er[nxt], ec[nxt]) + solve(nxt, j);
    int cost2 = getDist(pos2r(j), pos2c(j), er[nxt], ec[nxt]) + solve(i, nxt);

    if (cost1 <= cost2) {
        assign_arr[nxt] = 1;
        traceback(nxt, j);
    }
    else {
        assign_arr[nxt] = 2;
        traceback(i, nxt);
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> W;
    for (int i = 1; i <= W; i++) cin >> er[i] >> ec[i];

    memset(visited, false, sizeof(visited));

    cout << solve(0, 0) << "\n";
    traceback(0, 0);
    for (int i = 1; i <= W; i++) cout << assign_arr[i] << "\n";

    return 0;
}