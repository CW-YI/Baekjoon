#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<vector<int>> house;
vector<vector<int>> dp;
int N;

int FindMinCost(int i, int prevIndex) {
    if (i == N) return 0;
    if (i != 0 && dp[i][prevIndex] != -1) return dp[i][prevIndex];

    int sum1 = house[i][0], sum2 = house[i][1], sum3 = house[i][2];
    if (prevIndex != 0) sum1 = house[i][0] + FindMinCost(i + 1, 0); // 1, 2
    if (prevIndex != 1) sum2 = house[i][1] + FindMinCost(i + 1, 1); // 0, 2
    if (prevIndex != 2) sum3 = house[i][2] + FindMinCost(i + 1, 2); // 0, 1

    int minNum = -1;
    if (prevIndex == 0) minNum = min(sum2, sum3);
    else if (prevIndex == 1) minNum = min(sum1, sum3);
    else if (prevIndex == 2) minNum = min(sum2, sum1);
    else minNum = min(sum1, min(sum2, sum3));

    if (i != 0) dp[i][prevIndex] = minNum;

    return minNum;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false); 

    cin >> N;
  
    house.resize(N, vector<int>(3));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < 3; j++)
            cin >> house[i][j];
     
    dp.resize(N, vector<int>(3, -1));

    cout << FindMinCost(0, -1);

    return 0;
}
