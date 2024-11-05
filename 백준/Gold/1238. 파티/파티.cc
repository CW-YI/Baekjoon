#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;
vector<vector<pair<int, int>>> v;
int N;

vector<int> dijkstra(int num) {
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
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int M, X;
    cin >> N >> M >> X;

    v.resize(N + 1);
    int start, end, weight;
    for (int i = 0; i < M; i++) {
        cin >> start >> end >> weight;
        v[start].emplace_back(make_pair(end, weight));
    }

    vector<int> XToNode = dijkstra(X);
    vector<int> NodeToX(N + 1);
    for (int i = 1; i <= N; i++)
        NodeToX[i] = dijkstra(i)[X];

    NodeToX[X] = XToNode[X] = 0;
    int maxNum = 0;
    for (int i = 1; i <= N; i++)
        maxNum = max(maxNum, NodeToX[i] + XToNode[i]);

    cout << maxNum;
    return 0;
}