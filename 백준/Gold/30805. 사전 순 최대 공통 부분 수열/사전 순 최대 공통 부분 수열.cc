#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;
vector<pair<int, int>> A, B;
int N, M;

bool compare(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

void MaxLength() {
    int aIndex = 0, bIndex = 0, a = 0, b = 0;
    vector<int> v;

    while (a < N && b < M) {
        if (A[a].first == B[b].first) {
            if (A[a].second < aIndex) { a++; continue; }
            if (B[b].second < bIndex) { b++; continue; }
            
            aIndex = A[a].second; bIndex = B[b].second;
            v.push_back(A[a].first); a++; b++;
        }
        else if (A[a].first > B[b].first) a++;
        else b++;
    }

    cout << v.size() << "\n";
    for (const auto& num : v)
        cout << num << " ";
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;
    for (int i = 0, temp; i < N; i++) {
        cin >> temp;
        A.push_back({ temp, i });
    }

    cin >> M;
    for (int i = 0, temp; i < M; i++) {
        cin >> temp;
        B.push_back({ temp, i });
    }

    sort(A.begin(), A.end(), compare);
    sort(B.begin(), B.end(), compare);

    MaxLength();
    return 0;
}