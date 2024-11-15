#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;

    vector<vector<int>> party(M), people(N + 1); 
    vector<bool> visitParty(M, 0), visitPeople(N + 1, 0);
    queue<int>q;

    int num, temp;
    cin >> num;
    for (int i = 0; i < num; i++) {
        cin >> temp; q.push(temp);
        visitPeople[temp] = true;
    }

    for (int i = 0; i < M; i++) {
        cin >> num;
        for (int j = 0; j < num; j++) {
            cin >> temp;
            party[i].emplace_back(temp);
            people[temp].emplace_back(i);
        }
    }

    while (!q.empty()) {
        int curP = q.front();
        q.pop();

        for (const auto& pt : people[curP]) {
            if (visitParty[pt]) continue;
            visitParty[pt] = true;

            for (const auto& pp : party[pt]) {
                if (visitPeople[pp]) continue;
                visitPeople[pp] = true;
                q.push(pp);
            }
        }
    }

    int result = 0;
    for (const auto& pt : visitParty)
        if (!pt) result++;
    cout << result;

    return 0;
}