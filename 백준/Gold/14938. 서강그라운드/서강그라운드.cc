#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int const INF = 1e9;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, M, R;
    cin >> N >> M >> R;

    vector<pair<int, vector<pair<int, int>>>> v(N + 1);

    for (int i = 1; i <= N; i++)
        cin >> v[i].first;

    for (int i = 0, s, e, w; i < R; i++) {
        cin >> s >> e >> w;
        v[s].second.push_back({ e, w });
        v[e].second.push_back({ s, w });
    }

    int maxNum = 0;
    for (int i = 1; i <= N; i++) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        vector<int> visit(N + 1, INF);

        q.push({ i, 0 });
        visit[i] = v[i].first;

        while (!q.empty()) {
            auto [curNode, curDist] = q.top();
            q.pop();

            if (visit[curNode] < curDist) continue;

            for (const auto& [nextNode, nextWeight] : v[curNode].second) {
                int nextDist = curDist + nextWeight;
                if (nextDist > M) continue;
                if (visit[nextNode] < nextDist) continue;

                q.push({ nextNode, nextDist });
                visit[nextNode] = nextDist;
            }
        }

        int totalNum = 0;
        for (int j = 1; j <= N; j++)
            if (visit[j] != INF) totalNum += v[j].first;

        maxNum = max(maxNum, totalNum);
    }

    cout << maxNum;
    return 0;
}