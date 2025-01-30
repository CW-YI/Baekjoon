#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<pair<int, string>> v(N);

    for (int i = 0; i < N; i++)
        cin >> v[i].first >> v[i].second;

    stable_sort(v.begin(), v.end(), [](const pair<int, string>& a, const pair<int, string>& b) 
    { return a.first < b.first; });

    for (int i = 0; i < N; i++)
        cout << v[i].first << " " << v[i].second << "\n";

    return 0;
}