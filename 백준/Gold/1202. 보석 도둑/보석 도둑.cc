#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> gem(N);
    vector<int> bag(M);

    for (int i = 0; i < N; i++) cin >> gem[i].first >> gem[i].second;
    for (int i = 0; i < M; i++) cin >> bag[i];

    sort(gem.begin(), gem.end());
    sort(bag.begin(), bag.end());

    priority_queue <int> q;
    long long total = 0;
    int index = 0;
    
    for (int i = 0; i < M; i++) {
        while (index < N && gem[index].first <= bag[i])
            q.push(gem[index++].second);

        if (!q.empty()) {
            total += q.top();
            q.pop();
        }
    }

    cout << total;
    return 0;
}