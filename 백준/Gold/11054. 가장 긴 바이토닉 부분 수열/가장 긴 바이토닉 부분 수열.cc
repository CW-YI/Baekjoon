#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> v(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];

    vector<int> dp_inc(N, 1), dp_dec(N, 1);

    for (int i = 1; i < N; i++)
        for (int j = 0; j < i; j++)
            if (v[j] < v[i]) dp_inc[i] = max(dp_inc[i], dp_inc[j] + 1);

    for (int i = N - 2; i >= 0; i--)
        for (int j = N - 1; j > i; j--) 
            if (v[j] < v[i]) dp_dec[i] = max(dp_dec[i], dp_dec[j] + 1);

    int max_length = 0;
    for (int i = 0; i < N; i++)
        max_length = max(max_length, dp_inc[i] + dp_dec[i] - 1);

    cout << max_length;
    return 0;
}