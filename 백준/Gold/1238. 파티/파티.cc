#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;
int N;

vector<int> dijkstra(int num, vector<vector<pair<int, int>>> v) {
    vector<int> dist(N + 1, INF);
    priority_queue < pair<int, int>, vector<pair<int, int>>, greater < pair<int, int>>> q;

    q.push(make_pair(0, num));

    while (!q.empty()) {
        int node = q.top().second;
        int w = q.top().first;

        q.pop();

        for (const auto& pair : v[node]) {
            int nextNode = pair.first;
            int nextW = pair.second;

            if (dist[nextNode] > nextW + w) {
                dist[nextNode] = nextW + w;
                q.push(make_pair(nextW + w, nextNode));
            }
        }
    }
    return dist;
}

int main(void) {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int M, X;
    cin >> N >> M >> X;

    vector<vector<pair<int, int>>> v, rv;
    v.resize(N + 1); rv.resize(N + 1);

    int start, end, weight;
    for (int i = 0; i < M; i++) {
        cin >> start >> end >> weight;
        v[start].emplace_back(make_pair(end, weight));
        rv[end].emplace_back(make_pair(start, weight));
    }

    vector<int> XToNode = dijkstra(X, v);
    vector<int> NodeToX = dijkstra(X, rv);

    NodeToX[X] = XToNode[X] = 0;
    int maxNum = 0;
    for (int i = 1; i <= N; i++)
        maxNum = max(maxNum, NodeToX[i] + XToNode[i]);

    cout << maxNum;
    return 0;
}