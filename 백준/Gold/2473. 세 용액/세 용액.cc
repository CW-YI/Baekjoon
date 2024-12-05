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
    sort(v.begin(), v.end());

    long long int minNum = 3e9;
    int n1 = 0, n2 = 0, n3 = 0;

    for (int i = 0; i < N - 2; i++) {
        int left = i + 1, right = N - 1;

        while (left < right) {
            long long sum = (long long)v[i] + v[left] + v[right];

            if (abs(sum) < abs(minNum)) {
                minNum = sum;
                n1 = v[i]; n2 = v[left]; n3 = v[right];
            }

            if (sum < 0) left++;
            else if (sum > 0) right--;
            else {
                cout << n1 << " " << n2 << " " << n3;
                return 0;
            }
        } 
    }

    cout << n1 << " " << n2 << " " << n3;
    return 0;
}