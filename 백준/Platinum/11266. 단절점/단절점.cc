#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int V, E;
vector<int> graph[10001];
int disc[10001];   // DFS 방문 순서
int low[10001];    // 해당 노드에서 갈 수 있는 가장 작은 disc 값
bool isAP[10001];  // 단절점 여부
int timer = 0;

void dfs(int u, int parent) {
    disc[u] = low[u] = ++timer;
    int childCnt = 0;  // DFS 트리에서 u의 자식 수

    for (int v : graph[u]) {
        if (v == parent) continue;  // 부모 간선은 무시

        if (disc[v] == 0) {
            // 아직 방문 안 한 정점 → 트리 간선
            childCnt++;
            dfs(v, u);
            low[u] = min(low[u], low[v]);

            // 단절점 판별
            // 1) 루트 노드: 자식이 2개 이상이면 단절점
            // 2) 일반 노드: low[v] >= disc[u] 이면 단절점
            if (parent == -1 && childCnt >= 2) isAP[u] = true;
            if (parent != -1 && low[v] >= disc[u]) isAP[u] = true;
        }
        else {
            // 이미 방문한 정점 → 역방향 간선
            low[u] = min(low[u], disc[v]);
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    // 비연결 그래프일 수 있으므로 모든 정점에서 DFS
    for (int i = 1; i <= V; i++) {
        if (disc[i] == 0) dfs(i, -1);
    }

    vector<int> result;
    for (int i = 1; i <= V; i++) {
        if (isAP[i]) result.push_back(i);
    }

    sort(result.begin(), result.end());

    cout << result.size() << "\n";
    for (int v : result) cout << v << " ";
    cout << "\n";

    return 0;
}