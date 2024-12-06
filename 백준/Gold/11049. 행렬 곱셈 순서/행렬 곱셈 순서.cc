#include <iostream>
#include <vector>

using namespace std;
int N;
const int INF = 1e9;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;

    vector<pair<int, int>> v(N);
    vector<vector<int>> dp(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++)
        cin >> v[i].first >> v[i].second;

    for (int l = 2; l <= N; l++) {
        for (int s = 0; s + l - 1 < N; s++) {
            int e = s + l - 1;
            dp[s][e] = INF;

            for (int k = s; k < e; k++) {
                int sum = dp[s][k] + dp[k + 1][e] +
                    v[s].first * v[k].second * v[e].second;
                dp[s][e] = min(dp[s][e], sum);
            }
        }
    }

    cout << dp[0][N - 1];
    return 0;
}