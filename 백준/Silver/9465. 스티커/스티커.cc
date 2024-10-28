#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v, dp;
int N;

int FindSticker(int j, int previ) {
    if (j >= N) return 0;
    if (dp[previ][j] != -1) return dp[previ][j];

    // 현재 열에서
    int n1 = 0, n2 = 0, n3 = 0;
    // 첫번째 행을 선택한 경우
    if (previ != 0) n1 = v[0][j] + FindSticker(j + 1, 0);
    // 두번째 행을 선택한 경우
    if (previ != 1) n2 = v[1][j] + FindSticker(j + 1, 1);
    // 행을 선택하지 않는 경우
    if (previ != 2) n3 = FindSticker(j + 1, 2);
   
    int maxNum = max(n1, max(n2, n3));
    dp[previ][j] = maxNum;

    return maxNum;
}

void GetSticker() {
    cin >> N;

    v.clear(); dp.clear();
    v.resize(2, vector<int>(N, 0));
    dp.resize(3, vector<int>(N, -1));

    for (int i = 0; i <= 1; i++)
        for (int j = 0; j < N; j++)
            cin >> v[i][j];

    cout << FindSticker(0, 2) << "\n";
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false); 

    int M;
    cin >> M;
    for (int i = 0; i < M; i++)
        GetSticker();
    
    return 0;
}
