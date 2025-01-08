#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    int N1 = N, M1 = M - 45;
    if (M1 < 0) N1 = ((N1 - 1) + 24) % 24;
    M1 = (M1 + 60) % 60;
    cout << N1 << " " << M1;
    return 0;
}