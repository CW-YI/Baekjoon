#include <iostream>
#include <vector>

using namespace std;
vector<int> parent;

int checkParent(int node) {
    if (parent[node] == node) return node; // 부모 노드가 자기 자신이면 반환
    return parent[node] = checkParent(parent[node]); // 경로 단축
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    // 연결된 각각의 노드들을 같은 set에 넣고, 각 parent를 저장

    parent.resize(N);
    for (int i = 0; i < N; i++) parent[i] = i;

    int n1, n2, Cycle = 0;
    for (int i = 0; i < M; i++) {
        cin >> n1 >> n2;
        int r1 = checkParent(n1), r2 = checkParent(n2); // 루트 찾기

        if (r1 == r2) {
            cout << i + 1;
            return 0;
        }
        else parent[r2] = r1;
    }

    cout << 0;
    return 0;
}