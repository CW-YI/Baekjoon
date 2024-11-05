#include <iostream>
#include <vector>
#include <queue>
#include <vector>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, M, X;
    cin >> N >> M >> X;

    vector<vector<int>> v(N + 1, vector<int>(N + 1, -1));
    int start, end, weight;
    for (int i = 0; i < M; i++) {
        cin >> start >> end >> weight;
        v[start][end] = weight;
    }

    vector<vector<int>> visit(N + 1, vector<int>(N + 1, -1));
    priority_queue < pair<int, int>, vector<pair<int, int>>, greater < pair<int, int>>> q;

    for (int i = 1; i <= N; i++) {
        q.push(make_pair(0, i));

        while (!q.empty()) {
            int node = q.top().second;
            int w = q.top().first;

            q.pop();

            for (int j = 1; j <= N; j++) {
                int nextW = v[node][j];
                if (v[node][j] == -1 || (visit[i][j] != -1 && visit[i][j] < w + nextW))
                    continue;
                visit[i][j] = w + nextW;
                q.push(make_pair(w + nextW, j));
            }
        }
    }

    int max = 0;
    for (int i = 1; i <= N; i++) {
        if (i == X) continue;
        int num = visit[i][X] + visit[X][i];
        if (max < num) max = num;
    }

    cout << max;
    return 0;
}