#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int INF = 1e9;
int N;
vector<vector<pair<int, int>>> v;

vector<int> dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    vector<int> visit(N + 1, INF);
    q.push(make_pair(0, start));
    visit[start] = 0;
    
    while (!q.empty()) {
        int node = q.top().second, weight = q.top().first;
        q.pop();

        if (visit[node] < weight) continue;
        for (const auto& pair : v[node]) {
            if (visit[pair.first] <= pair.second + weight) continue;
            visit[pair.first] = pair.second + weight;
            q.push(make_pair(pair.second + weight, pair.first));
        }
    }

    return visit;
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int E;
    cin >> N >> E;

    int s, e, w;
    v.resize(N + 1);
    for (int i = 0; i < E; i++) {
        cin >> s >> e >> w;
        v[s].emplace_back(make_pair(e, w));
        v[e].emplace_back(make_pair(s, w));
    }

    int v1, v2;
    cin >> v1 >> v2;
    vector<int> fromstart, fromv1, fromv2;
    fromstart = dijkstra(1); fromv1 = dijkstra(v1); fromv2 = dijkstra(v2);
    // 시작 -> v1 -> v2 -> end, 시작 -> v2 -> v1 -> end
    int result = -1, path1, path2;
    if (fromstart[v1] >= INF || fromv1[v2] >= INF || fromv2[N] >= INF) path1 = -1;
    else path1 = fromstart[v1] + fromv1[v2] + fromv2[N];

    if (fromstart[v2] >= INF || fromv2[v1] >= INF || fromv1[N] >= INF) path2 = -1;
    else path2 = fromstart[v2] + fromv2[v1] + fromv1[N];

    if (path1 != -1 && path2 != -1) cout << min(path1, path2);
    else if (path1 == -1) cout << path2;
    else if (path2 == -1) cout << path1;
    else cout << -1;
    
    return 0;
}