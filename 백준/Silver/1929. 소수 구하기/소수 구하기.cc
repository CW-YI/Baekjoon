#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    vector<bool> num(M + 1, true);
    num[1] = false;

    for (int i = 2; i <= M; i++) {
        for (int j = 2; i * j <= M; j++) {
            if (num[i * j]) num[i * j] = false;
        }
    }

    for (int i = N; i <= M; i++)
        if (num[i]) cout << i << "\n";

    return 0;
}