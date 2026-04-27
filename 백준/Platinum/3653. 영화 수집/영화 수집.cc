#include <iostream>
#include <vector>
using namespace std;

// 세그먼트 트리 (구간 합)
struct SegTree {
    int size;
    vector<int> tree;

    void init(int n) {
        size = 1;
        while (size < n) size <<= 1;
        tree.assign(2 * size, 0);
    }

    void update(int i, int val) {
        i += size;
        tree[i] += val;
        for (i >>= 1; i >= 1; i >>= 1)
            tree[i] = tree[2*i] + tree[2*i+1];
    }

    // [l, r] 구간 합
    int query(int l, int r) {
        int res = 0;
        for (l += size, r += size + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res += tree[l++];
            if (r & 1) res += tree[--r];
        }
        return res;
    }
};

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;

        // 총 배열 크기: 앞 m칸(빈 공간) + 뒤 n칸(초기 DVD)
        int total = n + m;
        SegTree seg;
        seg.init(total);

        // pos[i]: i번 DVD의 현재 인덱스 (0-indexed)
        // 초기: 1번 DVD가 가장 위 → 인덱스 m, n번 DVD → 인덱스 m+n-1
        vector<int> pos(n + 1);
        for (int i = 1; i <= n; i++) {
            pos[i] = m + i - 1;
            seg.update(pos[i], 1);
        }

        int top = m - 1;  // 다음에 DVD를 놓을 위치 (앞쪽 빈 공간에서 역방향)

        for (int q = 0; q < m; q++) {
            int movie;
            cin >> movie;

            // movie 위에 있는 DVD 수 = [0, pos[movie]-1] 구간 합
            int above = (pos[movie] > 0) ? seg.query(0, pos[movie] - 1) : 0;
            cout << above;
            if (q < m - 1) cout << " ";

            // movie DVD 제거 후 맨 위(top)로 이동
            seg.update(pos[movie], -1);
            seg.update(top, 1);
            pos[movie] = top;
            top--;
        }
        cout << "\n";
    }

    return 0;
}