#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int N, M;
vector<vector<int>> v;
vector<int> incomingEdge;
vector<int> visitState; // 0미방문 1방문중 2방문완료
stack<int> result;
bool hasCycle = false;

void DFS(int curNode) {
    visitState[curNode] = 1;

    for (const auto& nextNode : v[curNode]) {
        incomingEdge[nextNode] -= 1;
        if (visitState[nextNode] == 0) DFS(nextNode);
        else if (visitState[nextNode] == 1) hasCycle = true;
    }

    visitState[curNode] = 2;
    result.push(curNode);
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    v.resize(N + 1); incomingEdge.resize(N + 1, 0);
    visitState.resize(N + 1, false);

    for (int i = 0, n1; i < M; i++) {
        cin >> n1;
        for (int j = 0, n2, prevN2 = 0; j < n1; j++) {
            cin >> n2;
            if (j != 0) {
                v[prevN2].push_back(n2);
                incomingEdge[n2] += 1;
            }
            prevN2 = n2;
        }
    }

    bool isStart = false;
    for (int i = 1; i <= N; i++)
        if (incomingEdge[i] == 0 && visitState[i] == 0)
            { DFS(i); isStart = true; }

    if (hasCycle || !isStart) { cout << 0; return 0; }

    while (!result.empty()) {
        cout << result.top() << "\n";
        result.pop();
    }
    return 0;
}