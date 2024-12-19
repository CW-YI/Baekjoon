#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;
const int INF = 1e9;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> node(N + 1);
    vector<pair<int, tuple<int, int, int>>> edge;
    for (int i = 0, s, e, w; i < M; i++) {
        cin >> s >> e >> w;
        edge.push_back({ 1, make_tuple(s, e, w) });
        node[s].push_back(i); node[e].push_back(i); // 간선 인덱스
    }

    priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    vector<int> visit(N + 1, INF);
    q.push({ 0, 1 }); visit[1] = 0;

    while (!q.empty()) {
        auto [curW, curNode] = q.top();
        q.pop();
        for (const auto& index : node[curNode]) {
            if (edge[index].first == 0) continue;
            auto [s, e, w] = edge[index].second;
            int opp = (s == curNode) ? e : s;

            if (w < visit[opp]) {
                visit[opp] = w; q.push({w, opp});
                edge[index].first = 0;
            }
        }
    }
    int sum = 0;
    for (int i = 1; i <= N; i++)
        sum += visit[i];
    cout << sum;
    return 0;
}