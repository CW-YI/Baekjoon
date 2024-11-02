#include <iostream>
#include <queue>
#include <vector>
#include <limits>
using namespace std;

int main() {
    int V, E, K;
    cin >> V >> E >> K;

    vector<vector<pair<int, int>>> graph(V + 1);

    int u, v, w;
    for (int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
    }

    const int maxNum = INT32_MAX; 

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    vector<int> visit(V + 1, maxNum);
    visit[K] = 0;
    q.push(make_pair(0, K));

    while (!q.empty()) {
        int curWeight = q.top().first;
        int curNode = q.top().second;
        q.pop();

        if (curWeight > visit[curNode]) continue; // 최단 거리보다 클 경우 무시

        for (const auto& edge : graph[curNode]) {
            int nextNode = edge.first; 
            int weight = edge.second; 

            if (visit[nextNode] > curWeight + weight) {
                visit[nextNode] = curWeight + weight;
                q.push(make_pair(visit[nextNode], nextNode));
            }
        }
    }

    for (int i = 1; i <= V; i++)
        if (visit[i] == maxNum) cout << "INF\n";
        else cout << visit[i] << "\n";

    return 0;
}