#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    bool alreadyred = true;
    int n, m;

    cin >> m >> n;
    vector<vector<int>> v(n, vector<int>(m, 0));
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
            if (v[i][j] == 1) q.push(make_pair(i, j));
        }
    }

    int day = 0;
    while (!q.empty()) {
        int count = q.size();

        //cout << "day : " << day << " size : " << q.size() << "\n";
        for (int i = 0; i < count; i++) {
            int x = q.front().first;
            int y = q.front().second;

            q.pop();

            if (x - 1 >= 0 && v[x - 1][y] == 0) {
                q.push(make_pair(x - 1, y));
                v[x - 1][y] = 1;
            }
            if (x + 1 < n && v[x + 1][y] == 0) {
                q.push(make_pair(x + 1, y));
                v[x + 1][y] = 1;
            }
            if (y - 1 >= 0 && v[x][y - 1] == 0) {
                q.push(make_pair(x, y - 1));
                v[x][y - 1] = 1;
            }
            if (y + 1 < m && v[x][y + 1] == 0) {
                q.push(make_pair(x, y + 1));
                v[x][y + 1] = 1;
            }
        }
        day++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == 0) {
                cout << -1;
                return 0;
            }
        }
    }
    cout << day - 1;
    return 0;
}