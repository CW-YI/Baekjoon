#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

const int INF = 1e9;
int N;

bool bellmanFord(vector<tuple<int, int, int>> edges) {
    vector<int> dist(N + 1, INF);
    
    dist[0] = 0;
    for (int i = 1; i <= N; i++)
        edges.emplace_back(0, i, 0);

    for (int i = 0; i < N; i++)
        for (auto [u, v, w] : edges)
            if (dist[u] != INF && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
    
    for (auto [u, v, w] : edges)
        if (dist[u] != INF && dist[u] + w < dist[v]) 
            return true;
    
    return false;
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int TC, M, W, S, E, T;
    cin >> TC;
    
    while (TC--) {
        cin >> N >> M >> W;
        vector<tuple<int, int, int>> edges;
        
        for (int m = 0; m < M; m++) {
            cin >> S >> E >> T;
            edges.emplace_back(S, E, T); 
            edges.emplace_back(E, S, T);
        }
        
        for (int w = 0; w < W; w++) {
            cin >> S >> E >> T;
            edges.emplace_back(S, E, -T);
        }
        
        if (bellmanFord(edges)) cout << "YES\n";
        else cout << "NO\n";
    }
    
    return 0;
}