#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> prefer[201];  // prefer[i]: i번 소가 원하는 축사 목록
int matched[201];          // matched[j]: j번 축사에 배정된 소 번호
bool visited[201];         // 현재 탐색에서 방문한 축사 번호

// 소 u가 축사를 배정받을 수 있는지 DFS
bool dfs(int u) {
    for (int barn : prefer[u]) {
        if (visited[barn]) continue;
        visited[barn] = true;

        // 축사가 비어있거나, 기존 소가 다른 축사로 옮길 수 있으면
        if (matched[barn] == 0 || dfs(matched[barn])) {
            matched[barn] = u;
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
        int s;
        cin >> s;
        for (int j = 0; j < s; j++) {
            int barn;
            cin >> barn;
            prefer[i].push_back(barn);
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