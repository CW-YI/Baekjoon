#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    long long N, M;
    cin >> N >> M;
    cout << abs(N - M);

    return 0;
}