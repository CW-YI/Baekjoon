#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> map;
vector<int> visit;

void DFS(int node) {
    cout << node << " ";
    visit[node] = 0;

    sort(map[node].begin(), map[node].end());
    for (const int nextNode : map[node])
        if (visit[nextNode] == -1) DFS(nextNode);
}

void BFS(int startNode) {
    queue<int> q;
    q.push(startNode);
    visit[startNode] = 1;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for (const int nextNode : map[node]) {
            if (visit[nextNode] == 0) { q.push(nextNode); visit[nextNode] = 1; }
        }
    }
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, M, V;
    cin >> N >> M >> V;

    map.resize(N + 1);
    visit.resize(N + 1, -1);

    for (int i = 0, s, e; i < M; i++) {
        cin >> s >> e;
        map[s].push_back(e); map[e].push_back(s);
    }

    DFS(V); 
    cout << "\n";
    BFS(V);
    return 0;
}