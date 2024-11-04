#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 1e9;

int main() {
    int n, m;
    cin >> n >> m;

    int v[101][101];
    fill(&v[0][0], &v[100][100], INF);

    int a, b, c;
    for (int i = 1; i <= n; i++)
        v[i][i] = 0;

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        v[a][b] = min(v[a][b], c);
    }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                v[i][j] = min(v[i][j], v[i][k] + v[k][j]);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (v[i][j] == INF) cout << "0 ";
            else cout << v[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}