#include <iostream>
#include <vector>

using namespace std;
vector<int> v, hasTeam;
pair<bool, int> MatchTeam(int curNum) {
    hasTeam[curNum] = 2; // 팀 매칭 확인 중
    
    int nextNum = v[curNum];
    pair<bool, int> returnNum = { false, -1 };
    if (hasTeam[nextNum] == 0) returnNum = MatchTeam(v[curNum]);
    else if (hasTeam[nextNum] == 2) returnNum = { true, nextNum };

    if (returnNum.first) hasTeam[curNum] = 1;
    else hasTeam[curNum] = -1;

    if (returnNum.second == curNum) returnNum.first = false;

    return returnNum;
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    for (int i = 0, M; i < N; i++) {
        cin >> M;
        v.resize(M + 1, 0); hasTeam.resize(M + 1, 0);
        for (int j = 1; j <= M; j++) {
            cin >> v[j];
            if (v[j] == j) hasTeam[j] = 1;
        }

        for (int j = 1; j <= M; j++)
            if (hasTeam[j] == 0) MatchTeam(j);

        int num = 0;
        for (int j = 1; j <= M; j++)
            if (hasTeam[j] <= 0) num++;

        cout << num << "\n";
        v.clear(); hasTeam.clear();
    }

    return 0;
}