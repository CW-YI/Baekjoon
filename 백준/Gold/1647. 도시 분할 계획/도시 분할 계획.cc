#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;
vector<int> parentNode;

int CheckParent(int node) {
    if (parentNode[node] != node) return parentNode[node] = CheckParent(parentNode[node]);
    return node;
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, M; // 집의 개수, 길의 개수
    cin >> N >> M;

    vector<tuple<int, int, int>> edges;

    int A, B, C;
    for (int i = 0; i < M; i++) {
        cin >> A >> B >> C;
        edges.push_back({ C, A, B }); // 비용, 노드1, 노드2
    }

    sort(edges.begin(), edges.end());

    // MST로 만든 후에 가장 큰 간선 비용만 빼기

    int MST = 0, lastCost = 0, p1, p2;
    parentNode.resize(N + 1);
    for (int i = 1; i <= N; i++) parentNode[i] = i;

    for (auto& [cost, node1, node2] : edges) {
        p1 = CheckParent(node1); p2 = CheckParent(node2);

        if (p1 == p2) continue;
        parentNode[p2] = p1;

        MST += cost;
        lastCost = cost;
    }

    cout << MST - lastCost;
    return 0;
}