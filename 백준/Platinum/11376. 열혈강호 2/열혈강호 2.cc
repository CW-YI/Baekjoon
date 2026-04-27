#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> works[2001];  // works[i], works[n+i]: i번 직원의 복사본 2개
int matched[1001];         // matched[j]: j번 일을 담당하는 노드 번호
bool visited[1001];

// 노드 u (직원 복사본)가 일을 배정받을 수 있는지 DFS
bool dfs(int u) {
    for (int job : works[u]) {
        if (visited[job]) continue;
        visited[job] = true;

        if (matched[job] == 0 || dfs(matched[job])) {
            matched[job] = u;
            return true;
        }
    }
    return false;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        int cnt;
        cin >> cnt;
        for (int j = 0; j < cnt; j++) {
            int job;
            cin >> job;
            works[i].push_back(job);       // 직원 i의 첫 번째 복사본
            works[n + i].push_back(job);   // 직원 i의 두 번째 복사본
        }
    }

    int ans = 0;

    // 직원 i의 복사본 1 (노드 i)
    for (int i = 1; i <= n; i++) {
        fill(visited + 1, visited + m + 1, false);
        if (dfs(i)) ans++;
    }

    // 직원 i의 복사본 2 (노드 n+i)
    for (int i = 1; i <= n; i++) {
        fill(visited + 1, visited + m + 1, false);
        if (dfs(n + i)) ans++;
    }

    cout << ans << "\n";

    return 0;
}