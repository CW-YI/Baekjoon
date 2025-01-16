#include <iostream>
#include <vector>
using namespace std;
const int INF = 1e9;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, M, maxCost = 0;
    cin >> N >> M;

    vector<pair<int, int>> v(N);
    for (int i = 0; i < N; i++) cin >> v[i].first;
    for (int i = 0; i < N; i++) { cin >> v[i].second; maxCost += v[i].second; }

    vector<int> dp(maxCost + 1, 0);

    for (int i = 0; i < N; i++)
        for (int j = maxCost; j >= v[i].second; j--)
            dp[j] = max(dp[j], dp[j - v[i].second] + v[i].first);

    for (int i = 0; i <= maxCost; i++) {
        if (dp[i] >= M) { cout << i; break; }
    }

    return 0;
}