#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int MAXN  = 100001;
const int LOG   = 17;      // 2^17 > 100,000
const int INF   = 1e9;

int n, k;
vector<pair<int,int>> graph[MAXN]; // {인접 노드, 간선 가중치}

int  depth[MAXN];
int  parent[MAXN][LOG]; // parent[v][k]: v의 2^k번째 조상
int  minW[MAXN][LOG];   // v에서 2^k번 올라가는 경로의 최솟값
int  maxW[MAXN][LOG];   // v에서 2^k번 올라가는 경로의 최댓값

// BFS로 depth, parent[v][0], minW[v][0], maxW[v][0] 초기화
void bfs(int root) {
    queue<int> q;
    vector<bool> visited(n + 1, false);

    depth[root]     = 0;
    parent[root][0] = root;
    minW[root][0]   = INF;
    maxW[root][0]   = 0;

    q.push(root);
    visited[root] = true;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto [v, w] : graph[u]) {
            if (visited[v]) continue;
            visited[v]  = true;
            depth[v]    = depth[u] + 1;
            parent[v][0] = u;
            minW[v][0]  = w;
            maxW[v][0]  = w;
            q.push(v);
        }
    }
}

// Sparse Table (DP) 채우기
void buildSparse() {
    for (int k = 1; k < LOG; k++) {
        for (int v = 1; v <= n; v++) {
            int mid = parent[v][k-1];
            parent[v][k] = parent[mid][k-1];
            minW[v][k]   = min(minW[v][k-1], minW[mid][k-1]);
            maxW[v][k]   = max(maxW[v][k-1], maxW[mid][k-1]);
        }
    }
}

// u~v 경로의 최솟값, 최댓값 반환
pair<int,int> query(int u, int v) {
    int resMin = INF, resMax = 0;

    // u를 더 깊은 노드로 고정
    if (depth[u] < depth[v]) swap(u, v);

    int diff = depth[u] - depth[v];

    // depth 맞추기
    for (int k = 0; k < LOG; k++) {
        if ((diff >> k) & 1) {
            resMin = min(resMin, minW[u][k]);
            resMax = max(resMax, maxW[u][k]);
            u = parent[u][k];
        }
    }

    if (u == v) return {resMin, resMax};

    // LCA 찾기
    for (int k = LOG - 1; k >= 0; k--) {
        if (parent[u][k] != parent[v][k]) {
            resMin = min({resMin, minW[u][k], minW[v][k]});
            resMax = max({resMax, maxW[u][k], maxW[v][k]});
            u = parent[u][k];
            v = parent[v][k];
        }
    }

    // 마지막 한 칸 (LCA 직전)
    resMin = min({resMin, minW[u][0], minW[v][0]});
    resMax = max({resMax, maxW[u][0], maxW[v][0]});

    return {resMin, resMax};
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    bfs(1);
    buildSparse();

    cin >> k;
    while (k--) {
        int d, e;
        cin >> d >> e;
        auto [mn, mx] = query(d, e);
        cout << mn << " " << mx << "\n";
    }

    return 0;
}