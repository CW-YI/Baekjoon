#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> v(n + 1);
    int a, b, c;

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        v[a].push_back(make_pair(b, c));
    }

    vector<vector<int>> result(n + 1, vector<int>(n + 1, -1));
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

    for (int i = 1; i <= n; i++) {
        result[i][i] = 0;
        q.push(make_pair(0, i));

        while (!q.empty()) {
            int node = q.top().second;
            int weight = q.top().first;
            int size = v[node].size();

            q.pop();
            for (int j = 0; j < size; j++) {
                int nextNode = v[node][j].first;
                int nextWeight = v[node][j].second;

                if (result[i][nextNode] != -1 && result[i][nextNode] < weight + nextWeight) continue;
                result[i][nextNode] = weight + nextWeight;
                q.push(make_pair(weight + nextWeight, nextNode));
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (result[i][j] == -1) cout << "0 ";
            else cout << result[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}