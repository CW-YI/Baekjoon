#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, M; // N -> 늘려야하는 고객 수, M -> 입력
    cin >> N >> M;

    vector<vector<int>> v(M, vector<int>(2, 0)); // Mx2 벡터
    vector<int> dp(1100, 1e9); // dp 벡터(i번째 배열은 고객 수 i명의 최솟값)

    for (int i = 0; i < M; i++) {
        cin >> v[i][0] >> v[i][1]; // 돈, 고객 수
        if (dp[v[i][1]] > v[i][0]) dp[v[i][1]] = v[i][0]; // 주어진 값
    }


    int min = 1e9;
    for (int i = 1; i < 1100; i++) {
        // i번째 배열에 대한 최솟값 찾기

        for (int j = 1; j < i; j++) {

            if (dp[i] > dp[j] + dp[i - j])  
                dp[i] = dp[j] + dp[i - j];
            //cout << "i : "<<i<< " dp[i] : " << dp[i] << " dp[j] : " << dp[j] << " dp[i-j] : " << dp[i - j] << "dp[i] :" <<dp[j]+dp[i-j] <<"\n";
        }

        if (i >= N && dp[i] < min) min = dp[i]; // 최솟값 갱신
    }

    cout << min;

    return 0;
}