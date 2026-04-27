#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

const int MAXN = 1000001;

ll tree[4 * MAXN];  // 세그먼트 트리
ll lazy[4 * MAXN];  // 지연 전파 배열
int n, m, k;

void build(vector<ll>& arr, int node, int start, int end) {
    lazy[node] = 0;
    if (start == end) {
        tree[node] = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    build(arr, 2 * node, start, mid);
    build(arr, 2 * node + 1, mid + 1, end);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

// lazy 값을 자식 노드로 전파
void pushDown(int node, int start, int end) {
    if (lazy[node] == 0) return;
    int mid = (start + end) / 2;

    tree[2 * node] += lazy[node] * (ll)(mid - start + 1);
    tree[2 * node + 1] += lazy[node] * (ll)(end - mid);

    lazy[2 * node] += lazy[node];
    lazy[2 * node + 1] += lazy[node];

    lazy[node] = 0;
}

// [l, r] 구간에 val 더하기
void update(int node, int start, int end, int l, int r, ll val) {
    if (r < start || end < l) return;
    if (l <= start && end <= r) {
        tree[node] += val * (ll)(end - start + 1);
        lazy[node] += val;
        return;
    }
    pushDown(node, start, end);
    int mid = (start + end) / 2;
    update(2 * node, start, mid, l, r, val);
    update(2 * node + 1, mid + 1, end, l, r, val);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

// [l, r] 구간 합 쿼리
ll query(int node, int start, int end, int l, int r) {
    if (r < start || end < l) return 0;
    if (l <= start && end <= r) return tree[node];
    pushDown(node, start, end);
    int mid = (start + end) / 2;
    return query(2 * node, start, mid, l, r)
        + query(2 * node + 1, mid + 1, end, l, r);
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> k;

    vector<ll> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];

    build(arr, 1, 1, n);

    int total = m + k;
    for (int i = 0; i < total; i++) {
        int a;
        cin >> a;
        if (a == 1) {
            int b, c;
            ll d;
            cin >> b >> c >> d;
            update(1, 1, n, b, c, d);
        }
        else {
            int b, c;
            cin >> b >> c;
            cout << query(1, 1, n, b, c) << "\n";
        }
    }

    return 0;
}