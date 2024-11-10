#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
const int INF = 1e9;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int N, M, start, end;
    cin >> N >> M;

    int s, e, w;
    vector<vector<pair<int, int>>> v(N + 1);
    for (int i = 0; i < M; i++) {
        cin >> s >> e >> w;
        v[s].emplace_back(make_pair(e, w));
    }

    cin >> start >> end;

    vector<int> visit(N + 1, INF), path(N + 1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push(make_pair(0, start)); visit[start] = 0;
    while (!q.empty()) {
        int node = q.top().second, weight = q.top().first;
        q.pop();

        if (visit[node] < weight) continue;

        for (const auto& pair : v[node]) {
            if (visit[pair.first] <= weight + pair.second) continue; 
            path[pair.first] = node;

            visit[pair.first] = weight + pair.second;
            q.push(make_pair(weight + pair.second, pair.first));
        }
    }

    vector<int> result;
    int prevNode = end;
    while (prevNode != start) {
        result.emplace_back(prevNode);
        prevNode = path[prevNode];
    }
    result.emplace_back(start);
    cout << visit[end] << "\n" << result.size() << "\n";

    for (int i = result.size() - 1; i >= 0; i--)
        cout << result[i] << " ";

    return 0;
}