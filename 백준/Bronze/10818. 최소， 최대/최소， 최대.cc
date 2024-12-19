#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, maxNum = -1e9, minNum = 1e9;
    cin >> N;
    for (int i = 0, n1; i < N; i++) {
        cin >> n1;
        maxNum = max(n1, maxNum);
        minNum = min(n1, minNum);
    }

    cout << minNum << " " << maxNum;
    return 0;
}