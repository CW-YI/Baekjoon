#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> v;
vector<int> dp;
vector<bool> visit;

int DFS(int node) {
    visit[node] = true;
    int num = 1;

    for (const int next : v[node])
        if (!visit[next]) num += DFS(next);

    return dp[node] = num;
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, R, Q;
    cin >> N >> R >> Q;

    v.resize(N + 1); dp.resize(N + 1, -1); visit.resize(N + 1, false);

    for (int i = 0, n1, n2; i < N - 1; i++) {
        cin >> n1 >> n2;
        v[n1].push_back(n2); v[n2].push_back(n1);
    }

    DFS(R);

    for (int i = 0, n; i < Q; i++) {
        cin >> n;
        cout << dp[n] << "\n";
    }

    return 0;
}