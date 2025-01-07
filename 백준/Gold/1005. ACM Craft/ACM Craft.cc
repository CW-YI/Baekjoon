#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int INF = 1e9;

void DAG() {
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> v(N + 1, make_pair(0, 0)); // 소요시간, 진입 간선 수

    for (int i = 1; i <= N; i++)
        cin >> v[i].first;

    vector<vector<int>> edge(N + 1);
    for (int i = 0, s, e; i < M; i++) {
        cin >> s >> e;
        edge[s].push_back(e);
        v[e].second++;
    }

    queue<pair<int, int>> q;
    vector<int> t(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        if (v[i].second == 0) { 
            t[i] = v[i].first;
            q.push({ i, t[i] });
        }
    }

    while (!q.empty()) {
        auto [curNode, dist] = q.front();
        q.pop();

        for (const int next : edge[curNode]) {
            v[next].second--;
            if (dist + v[next].first > t[next]) t[next] = dist + v[next].first;
            if (v[next].second == 0) q.push({ next, t[next] });
        }
    }

    cin >> M;
    cout << t[M] << "\n";
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int repeat;
    cin >> repeat;
    for (int i = 0; i < repeat; i++)
        DAG();

    return 0;
}