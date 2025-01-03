#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int sum = 0;
    for (int i = 0, n1; i < 5; i++) {
        cin >> n1;
        sum = (sum + (n1 * n1)) % 10;
    }

    cout << sum;
    return 0;
}