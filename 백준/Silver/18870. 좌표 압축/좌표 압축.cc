#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;


int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, temp;
    cin >> N;
    vector<pair<int, int>> v;

    for (int i = 0; i < N; i++) {
        cin >> temp;
        v.push_back(make_pair(temp, i));
    }

    sort(v.begin(), v.end());

    vector<int> result(N, 0);
    int rank = 0;
    for (int i = 0; i < N; i++) {
        if (i > 0 && v[i].first != v[i - 1].first) rank++;
        //else if (i > 0) cout << "V[i], v[i-1] " << v[i].first << v[i - 1].first << endl;
        result[v[i].second] = rank;
   }

    for (int i = 0; i < N; i++)
        cout << result[i] << " ";

    return 0;
}
