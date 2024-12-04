#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> v(N, 0);

    for (int i = 0; i < N; i++) cin >> v[i];

    long long int minNum = 3e9;
    int i = 0, j = N - 1;
    int n1 = v[i], n2 = v[j];
    while (i < j) {
        int temp = v[i] + v[j];
        if (abs(temp) < abs(minNum)) { minNum = temp; n1 = v[i], n2 = v[j]; }

        if (temp < 0) i++;
        else if (temp > 0) j--;
        else break;
    }
    cout << n1 << " " << n2;
    return 0;
}