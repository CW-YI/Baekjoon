#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    vector<int> num(N);
    for (int i = 0; i < N; i++)
        cin >> num[i];

    int gap = M, sum = 0, resultSum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
                sum = num[i] + num[j] + num[k];

                if (sum > M) continue;
                else if (sum == M) { cout << M; return 0; }
                else if (M - sum < gap) {
                    gap = M - sum;
                    resultSum = sum;
                }
            }
        }
    }

    cout << resultSum;
    return 0;
}