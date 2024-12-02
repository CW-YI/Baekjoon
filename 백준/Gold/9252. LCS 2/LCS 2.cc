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
            if (A[i - 1] == B[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                
        }
    }
    
    string result = "";
    int i = Asize, j = Bsize;
    while (i > 0 && j > 0) {
        if (A[i - 1] == B[j - 1]) { result = A[i - 1] + result; i--; j--; }
        else if (dp[i - 1][j] > dp[i][j - 1]) i--;
        else j--;
    }

    if (result.empty()) cout << "0";
    else cout << result.size() << "\n" << result;
    return 0;
}