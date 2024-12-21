#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    for (int i = 0, n; i < N; i++) {
        cin >> n;
        if (n < M) cout << n << " ";
    }
    return 0;
}