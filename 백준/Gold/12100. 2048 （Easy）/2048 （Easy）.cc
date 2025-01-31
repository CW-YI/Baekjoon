#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> v;
int N;

void MovingBlock(int dir) {
    vector<vector<int>> resultV(N, vector<int>(N, 0));
    vector<vector<bool>> merged(N, vector<bool>(N, false));

    bool updown = (dir < 2); 

    for (int outer = 0; outer < N; outer++) {
        int target = (dir % 2 == 0) ? 0 : N - 1;

        for (int inner = (dir % 2 == 0) ? 0 : N - 1; (dir % 2 == 0) ? inner < N : inner >= 0; inner += (dir % 2 == 0) ? 1 : -1) {
            int i = updown ? inner : outer, j = updown ? outer : inner;

            if (v[i][j] == 0) continue;
            int num = v[i][j]; v[i][j] = 0;

            int nextX = updown ? target : outer, nextY = updown ? outer : target;

            if (resultV[nextX][nextY] == num && !merged[nextX][nextY]) {
                resultV[nextX][nextY] *= 2; merged[nextX][nextY] = true;
            }
            else {
                if (resultV[nextX][nextY] != 0) target += (dir % 2 == 0) ? 1 : -1;
                resultV[updown ? target : outer][updown ? outer : target] = num;
            }
        }
    }

    v = resultV;
}

int FindMaxNum() {
    int maxNum = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            maxNum = max(maxNum, v[i][j]);

    return maxNum;
}

int Two0Four8(int count) {
    if (count == 5) return FindMaxNum();

    vector<vector<int>> curV = v;

    int maxNum = 0;
    for (int i = 0; i < 4; i++) {
        MovingBlock(i);
        maxNum = max(Two0Four8(count + 1), maxNum);
        v = curV;
    }

    return maxNum;
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;

    v.resize(N, vector<int>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> v[i][j];


    cout << Two0Four8(0);
    return 0;
}