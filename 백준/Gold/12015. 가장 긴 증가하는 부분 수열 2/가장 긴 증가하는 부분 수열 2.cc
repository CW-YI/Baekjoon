#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> A(N), result;

    for (int i = 0; i < N; i++)
        cin >> A[i];

    for (int i = 0; i < N; i++) {
        auto it = lower_bound(result.begin(), result.end(), A[i]);
        int index = it - result.begin();

        if (it == result.end()) result.push_back(A[i]);
        else *it = A[i];
    }

    cout << result.size();
    return 0;
}