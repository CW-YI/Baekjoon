#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> works[1001];  // works[i]: i번 직원이 할 수 있는 일 목록
int matched[1001];         // matched[j]: j번 일을 담당하는 직원 번호
bool visited[1001];        // 현재 탐색에서 방문한 일 번호

// 직원 u가 일을 배정받을 수 있는지 DFS
bool dfs(int u) {
    for (int job : works[u]) {
        if (visited[job]) continue;
        visited[job] = true;

        // job이 아직 배정 안 됐거나,
        // 기존 담당자가 다른 일로 옮길 수 있으면
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
            works[i].push_back(job);
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        fill(visited + 1, visited + m + 1, false);
        if (dfs(i)) ans++;
    }

    cout << ans << "\n";

    return 0;
}