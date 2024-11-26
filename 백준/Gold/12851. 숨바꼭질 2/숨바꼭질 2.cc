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

    int way = 1, resultTime = -1;
    while (!q.empty()) {
        int num = q.front().first;
        int time = q.front().second;
        q.pop();

        if (num == K) {
            if (resultTime == -1) resultTime = time;
            else if (resultTime == time) way++;
            else break;
            continue;
            
        }

        if (num * 2 <= 100000 && (dp[num * 2] == 0 || dp[num * 2] == time + 1)) {
            dp[num * 2] = time + 1;
            q.push(make_pair(num * 2, time + 1));
        }

        if (num - 1 >= 0 && (dp[num - 1] == 0 || dp[num - 1] == time + 1)) {
            dp[num - 1] = time + 1;
            q.push(make_pair(num - 1, time + 1));
        }

        if (num + 1 <= 100000 && (dp[num + 1] == 0 || dp[num + 1] == time + 1)) {
            dp[num + 1] = time + 1;
            q.push(make_pair(num + 1, time + 1));
        }
    }

    cout << resultTime - 1 << "\n" << way;
    return 0;
}