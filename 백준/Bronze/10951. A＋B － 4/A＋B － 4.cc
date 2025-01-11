#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, M;
    while (true) {
        cin >> N >> M;
        if (cin.eof()) break;
        cout << N + M << "\n";
    }

    return 0;
}