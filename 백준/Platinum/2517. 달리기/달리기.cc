#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int tree[2000001];
int SIZE;

// 세그먼트 트리: 점 업데이트
void update(int i, int val) {
    for (i += SIZE; i >= 1; i >>= 1)
        tree[i] += val;
}

// 세그먼트 트리: [l, r] 구간 합 쿼리
int query(int l, int r) {
    int res = 0;
    for (l += SIZE, r += SIZE + 1; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res += tree[l++];
        if (r & 1) res += tree[--r];
    }
    return res;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    // 좌표 압축
    vector<int> sorted_a = a;
    sort(sorted_a.begin(), sorted_a.end());
    // 중복 없으므로 unique 생략 가능, 보험 차원에서 처리
    sorted_a.erase(unique(sorted_a.begin(), sorted_a.end()), sorted_a.end());
    int m = sorted_a.size();

    // rank[i]: a[i]의 압축된 인덱스 (0-indexed)
    vector<int> rank_val(n);
    for (int i = 0; i < n; i++) {
        rank_val[i] = lower_bound(sorted_a.begin(), sorted_a.end(), a[i])
                      - sorted_a.begin();
    }

    // SIZE: m 이상인 2의 거듭제곱
    SIZE = 1;
    while (SIZE < m) SIZE <<= 1;

    // 앞에서부터 처리
    for (int i = 0; i < n; i++) {
        int r = rank_val[i];  // 현재 선수의 압축 인덱스

        // 앞에 있는 선수 중 나보다 실력이 작은 수
        // = 압축 인덱스 [0, r-1] 구간 합
        int cnt_less = (r > 0) ? query(0, r - 1) : 0;

        // 최선 등수 = (앞에 있는 선수 수 - 앞지를 수 있는 수) + 1
        //           = (i - cnt_less) + 1
        cout << (i - cnt_less) + 1 << "\n";

        // 현재 선수를 세그먼트 트리에 삽입
        update(r, 1);
    }

    return 0;
}