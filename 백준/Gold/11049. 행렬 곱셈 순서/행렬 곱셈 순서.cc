#include <iostream>
#include <vector>

using namespace std;
vector<pair<int, int>> v;
vector<vector<int>> dp;
int N;
const int INF = 1e9;

int FindMin(int start, int end) {
    if (start == end) return 0;
    if (dp[start][end] != -1) return dp[start][end];
    
    int minSum = INF;
    for (int k = start; k < end; k++) {
        int sum = FindMin(start, k) + FindMin(k + 1, end) +
            v[start].first * v[k].second * v[end].second;

        minSum = min(sum, minSum);
    }

    dp[start][end] = minSum;
    return dp[start][end];
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;

    v.resize(N);
    dp.resize(N, vector<int>(N, -1));

    for (int i = 0, n1, n2; i < N; i++) {
        cin >> n1 >> n2;
        v[i] = { n1, n2 };
    }

    cout << FindMin(0, N - 1);
    return 0;
}