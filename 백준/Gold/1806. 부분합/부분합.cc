#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    vector<int> v(N, 0);
    for (int i = 0; i < N; i++) cin >> v[i];

    int startIndex = 0, sum = 0, minLen = 100001;
    for (int i = 0; i < N; i++) {
        if (v[i] >= M) { minLen = 1; break; }
        sum += v[i];

        while (sum >= M && startIndex < i) {
            minLen = min(minLen, i - startIndex + 1);
            sum -= v[startIndex++];
        }
    }

    if (minLen == 100001) cout << 0;
    else cout << minLen;
    return 0;
}