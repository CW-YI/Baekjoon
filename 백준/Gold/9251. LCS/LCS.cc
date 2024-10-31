#include <iostream>
#include <vector>
using namespace std;

int main() {
    string A, B;
    cin >> A >> B;

    int Asize = A.size(), Bsize = B.size();
    vector<vector<int>> dp(Asize + 1, vector<int>(Bsize + 1, 0));

    for (int i = 1; i <= Asize; i++) {
        for (int j = 1; j <= Bsize; j++) {
            if (A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[Asize][Bsize];
    return 0;
}
