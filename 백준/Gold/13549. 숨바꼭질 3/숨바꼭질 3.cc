#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    queue<pair<int, int>> q;
    vector<int> dp(100001, 0);
    
    // 시작 타임을 1로
    dp[N] = 1;
    q.push(make_pair(N, 1));
    while (!q.empty()) {
        int num = q.front().first;
        int time = q.front().second;
        q.pop();

        //cout << "num : " << num << " time : " << time << "\n";

        if (num == K) {
            cout << time - 1;
            break;
        }

        if (num * 2 <= 100000 && dp[num * 2] == 0) {
            dp[num * 2] = time;
            q.push(make_pair(num * 2, time));
        }
        if (num - 1 >= 0 && dp[num - 1] == 0) {
            dp[num - 1] = time + 1;
            q.push(make_pair(num - 1, time + 1));
        }
        if (num + 1 <= 100000 && dp[num + 1] == 0) {
            dp[num + 1] = time + 1;
            q.push(make_pair(num + 1, time + 1));
        }
    }

    return 0;
}
