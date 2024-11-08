#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;
const int INF = 1e9;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
   
    int N, M, A, B;
    cin >> N >> M;
    vector<vector<pair<int, int>>> v(N + 1);

    int s, e, w;
    for (int i = 0; i < M; i++) {
        cin >> s >> e >> w;
        v[s].emplace_back(make_pair(e, w));
    }
    cin >> A >> B;

    vector<int> visit(N + 1, INF);
    priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

    visit[A] = 0;
    q.push(make_pair(0, A));
    while (!q.empty()) {
        int node = q.top().second, weight = q.top().first;
        q.pop();

        if (weight > visit[node]) continue;

        for (const auto& pair : v[node]) {
            if (visit[pair.first] <= pair.second + weight) continue;
            visit[pair.first] = pair.second + weight;
            q.push(make_pair(pair.second + weight, pair.first));
        }
    }

    cout << visit[B];
    return 0;
}