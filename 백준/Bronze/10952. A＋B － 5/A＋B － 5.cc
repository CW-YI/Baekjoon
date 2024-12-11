#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n1, n2;

    while (true) {
        cin >> n1 >> n2;
        if (n1 + n2 == 0) break;
        cout << n1 + n2 << "\n";
    }
    return 0;
}