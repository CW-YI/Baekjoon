#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false); 

    int N, K, w, v;
    cin >> N >> K;

    vector<int> dp(K + 1, 0);

    for (int i = 0; i < N; i++) {
        cin >> w >> v; 

        for (int j = K; j >= w; j--)
            dp[j] = max(dp[j], dp[j - w] + v);  // 무게 j에서의 최대 가치
    }

    cout << dp[K];
    return 0;
}
