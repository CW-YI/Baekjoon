#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int N, M;

long long SumHeight(int height) {
    long long sum = 0;
    for (int i = 0; i < N; i++)
        if (v[i] > height) sum += v[i] - height;

    return sum;
}

int binary() {
    int start = 0, end = v[N - 1];
    int result = 0;

    while (start <= end) {
        int mid = (start + end) / 2;
        long long total = SumHeight(mid);

        if (total >= M) {
            result = mid;
            start = mid + 1;
        }
        else end = mid - 1;
    }

    return result;
}

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;

    v.assign(N, 0);

    for (int i = 0; i < N; i++) cin >> v[i];

    sort(v.begin(), v.end());

    cout << binary() << "\n";
    return 0;
}
