#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef long long ll;
typedef pair<ll, int> pli;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<pair<int, int>>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({ b, c });
    }

    // cnt[v]: v번 노드를 몇 번 꺼냈는지
    // k번 꺼낸 시점의 비용 = k번째 최단경로
    vector<int> cnt(n + 1, 0);

    // {비용, 노드}
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    pq.push({ 0, 1 });  // 시작점: 1번 도시, 비용 0

    // k번째 최단경로 저장
    vector<ll> ans(n + 1, -1);

    while (!pq.empty()) {
        auto [cost, v] = pq.top();
        pq.pop();

        cnt[v]++;

        // v를 k번째 꺼냈다면 → k번째 최단경로 확정
        if (cnt[v] == k) {
            ans[v] = cost;
        }

        // k번 초과 방문하면 더 볼 필요 없음
        if (cnt[v] > k) continue;

        for (auto [nxt, w] : graph[v]) {
            if (cnt[nxt] < k) {
                pq.push({ cost + w, nxt });
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}