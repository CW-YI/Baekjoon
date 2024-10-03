#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> input;
vector<vector<int>> result;
int N, M;

void PrintVector() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) cout << result[i][j] << " ";
        cout << "\n";
    }
}

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;

    input.assign(N, vector<int>(M, 0));
    result.assign(N, vector<int>(M, -1));
    //PrintVector();

    pair<int, int> startPos;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> input[i][j];
            if (input[i][j] == 2) startPos = make_pair(i, j);
            else if (input[i][j] == 0) result[i][j] = 0;
        }
    }
    //PrintVector();

    queue<pair<int, int>> q;
    q.push(startPos);

    int distance = 0;
    result[startPos.first][startPos.second] = distance;

    while (!q.empty()) {
        int i = q.front().first;
        int j = q.front().second;
        distance = result[i][j];

        q.pop();

        if (i - 1 >= 0 && result[i - 1][j] == -1) {
            result[i - 1][j] = distance + 1;
            q.push(make_pair(i - 1, j));
        }
        if (i + 1 < N && result[i + 1][j] == -1) {
            result[i + 1][j] = distance + 1;
            q.push(make_pair(i + 1, j));
        }
        if (j - 1 >= 0 && result[i][j - 1] == -1) {
            result[i][j - 1] = distance + 1;
            q.push(make_pair(i, j - 1));
        }
        if (j + 1 < M && result[i][j + 1] == -1) {
            result[i][j + 1] = distance + 1;
            q.push(make_pair(i, j + 1));
        }
    }

    PrintVector();
    return 0;
}
