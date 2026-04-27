#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int n, m;
ll bit[100001];  // 차분 배열의 BIT

// BIT 업데이트: i번 인덱스에 val 더하기
void update(int i, ll val) {
    for (; i <= n; i += i & (-i))
        bit[i] += val;
}

// BIT 구간합: 1 ~ i까지의 합 (차분 배열의 prefix sum)
ll query(int i) {
    ll sum = 0;
    for (; i > 0; i -= i & (-i))
        sum += bit[i];
    return sum;
}

// 구간 [l, r]에 val 더하기 → 차분 배열에서 점 업데이트 2번
void rangeUpdate(int l, int r, ll val) {
    update(l, val);
    update(r + 1, -val);
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;

    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    // 초기 수열을 차분 배열로 BIT에 반영
    for (int i = 1; i <= n; i++) {
        update(i, a[i]);
        update(i + 1, -a[i]);
    }

    cin >> m;
    while (m--) {
        int type;
        cin >> type;

        if (type == 1) {
            int i, j;
            ll k;
            cin >> i >> j >> k;
            rangeUpdate(i, j, k);
        } else {
            int x;
            cin >> x;
            // A[x] = 차분 배열의 prefix sum (1~x)
            cout << query(x) << "\n";
        }
    }

    return 0;
}