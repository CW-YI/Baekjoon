#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<vector<int>> house;
vector<vector<int>> dp;
int N, firstColor;
const int INF = 1e9;

int FindMinCost(int i, int prevIndex) {
    if (i == N) return 0;
    if (dp[i][prevIndex] != -1) return dp[i][prevIndex];

    int sum1 = INF, sum2 = INF, sum3 = INF;
    if ((i != N - 1 && prevIndex != 0) || (i == N - 1 && firstColor != 0 && prevIndex != 0)) sum1 = house[i][0] + FindMinCost(i + 1, 0); // 1, 2
    if ((i != N - 1 && prevIndex != 1) || (i == N - 1 && firstColor != 1 && prevIndex != 1)) sum2 = house[i][1] + FindMinCost(i + 1, 1); // 0, 2
    if ((i != N - 1 && prevIndex != 2) || (i == N - 1 && firstColor != 2 && prevIndex != 2)) sum3 = house[i][2] + FindMinCost(i + 1, 2); // 0, 1

    int minNum = min(sum1, min(sum2, sum3));

    return dp[i][prevIndex] = minNum;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;

    house.resize(N, vector<int>(3));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < 3; j++)
            cin >> house[i][j];

    int result = INF;
    for (int i = 0; i < 3; i++) {
        dp.assign(N, vector<int>(3, -1));
        firstColor = i;
        result = min(result, house[0][i] + FindMinCost(1, i));
    }

    cout << result;

    return 0;
}