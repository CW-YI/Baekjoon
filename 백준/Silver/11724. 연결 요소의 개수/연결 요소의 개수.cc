#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;


int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    map<int, vector<int>> m;

    int N, M, n1, n2;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        cin >> n1 >> n2;
        m[n1].push_back(n2);
        m[n2].push_back(n1);
    }

    queue<int> q;
    vector<int> v(N + 1, 0);

    int num = 0;
    while (!m.empty()) {
        auto it = m.begin();
        q.push(it->first);

        while (!q.empty()) {
            v[q.front()] = 1;
            
            for (int i = 0; i < m[q.front()].size(); i++) {
                int temp = m[q.front()][i];

                if (v[temp] != 1) {
                    q.push(temp); v[temp] = 1;
                }
            }

            m.erase(q.front());
            q.pop();
        }
        num++;
    }
    
    for (int i = 1; i <= N; i++)
        if (v[i] == 0) num++;

    cout << num;
    return 0;
}
