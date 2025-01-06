#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    vector<bool> v(42, false);
    for (int i = 0, n1; i < 10; i++) {
        cin >> n1;
        v[n1 % 42] = true;
    }

    int sum = 0;
    for (int i = 0; i < 42; i++)
        if (v[i]) sum++;
    cout << sum;
    return 0;
}