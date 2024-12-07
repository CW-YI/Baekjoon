#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> A(N);

    for (int i = 0; i < N; i++)
        cin >> A[i];

    vector<int> result, dp(N, -1), dpp(N, -1);

    for (int i = 0; i < N; i++) {
        auto it = lower_bound(result.begin(), result.end(), A[i]);
        int index = it - result.begin();

        if (it == result.end()) result.push_back(A[i]);
        else *it = A[i];

        dp[index] = i;
        if (index > 0) dpp[i] = dp[index - 1];
    }

    int maxLength = result.size();
    cout << maxLength << "\n";

    vector<int> r;
    int current = dp[maxLength - 1];

    while (current != -1) {
        r.push_back(A[current]);
        current = dpp[current];
    }

    reverse(r.begin(), r.end());
    for (const int& num : r)
        cout << num << " ";

    return 0;
}