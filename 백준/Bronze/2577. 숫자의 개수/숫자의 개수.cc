#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int A, B, C;
    cin >> A >> B >> C;

    int sum = A * B * C;

    vector<int> v(10, 0);
    while (sum > 0) {
        v[sum % 10] += 1;
        sum /= 10;
    }

    for (const int n : v)
        cout << n << "\n";

    return 0;
}