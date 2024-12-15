#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int N, M, order;
vector<vector<int>> v;
vector<int> incomingEdge;
vector<bool> visited;
stack<int> result;

void DFS(int curNode) {
    visited[curNode] = true;

    for (const auto& nextNode : v[curNode]) {
        incomingEdge[nextNode] -= 1;
        if (!visited[nextNode]) DFS(nextNode);
    }
    
    result.push(curNode);
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    v.resize(N + 1); incomingEdge.resize(N + 1, 0);
    visited.resize(N + 1, false);

    for (int i = 0, n1, n2; i < M; i++) {
        cin >> n1 >> n2;
        v[n1].push_back(n2);
        incomingEdge[n2] += 1;
    }

    order = N;
    for (int i = 1; i <= N; i++)
        if (incomingEdge[i] == 0 && !visited[i])
            DFS(i);
    
    while (!result.empty()) {
        cout << result.top() << " ";
        result.pop();
    }
    return 0;
}