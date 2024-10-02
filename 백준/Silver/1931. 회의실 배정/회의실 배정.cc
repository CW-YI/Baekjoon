#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;


int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<pair<int, int>> v;
    int start, end;

    for (int i = 0; i < N; i++) {
        cin >> start >> end;
        v.push_back(make_pair(end, start));
    }

    sort(v.begin(), v.end());

    int lastTime = 0, count = 0;
    for (int i = 0; i < N; i++) {
        if (lastTime <= v[i].second) {
            count++;
            lastTime = v[i].first;
        }
    }

    cout << count;
    return 0;
}
