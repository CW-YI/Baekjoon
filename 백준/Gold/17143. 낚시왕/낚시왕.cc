#include <iostream>
#include <vector>
using namespace std;

int R, C, M;

struct Shark {
    int r, c, s, d, z;
    bool alive;
};

// 행 이동: 주기 2*(R-1), d=2(아래) 기준 p = r-1, d=1(위) 기준 p = 2*(R-1)-(r-1)
// 열 이동: 주기 2*(C-1), d=3(오른쪽) 기준 p = c-1, d=4(왼쪽) 기준 p = 2*(C-1)-(c-1)
void moveShark(Shark& sh) {
    if (sh.d == 1 || sh.d == 2) {
        int period = 2 * (R - 1);
        int p = (sh.d == 2) ? (sh.r - 1) : (period - (sh.r - 1));
        p = (p + sh.s % period) % period;
        if (p <= R - 1) { sh.r = p + 1; sh.d = 2; }
        else { sh.r = period - p + 1; sh.d = 1; }
    }
    else {
        int period = 2 * (C - 1);
        int p = (sh.d == 3) ? (sh.c - 1) : (period - (sh.c - 1));
        p = (p + sh.s % period) % period;
        if (p <= C - 1) { sh.c = p + 1; sh.d = 3; }
        else { sh.c = period - p + 1; sh.d = 4; }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> R >> C >> M;

    vector<Shark> sharks(M);
    for (int i = 0; i < M; i++) {
        cin >> sharks[i].r >> sharks[i].c
            >> sharks[i].s >> sharks[i].d >> sharks[i].z;
        sharks[i].alive = true;
    }

    int ans = 0;

    for (int col = 1; col <= C; col++) {
        // 1. 낚시왕 col열 이동 후 가장 위(r 최소) 상어 포획
        int topRow = R + 1, topIdx = -1;
        for (int i = 0; i < M; i++) {
            if (!sharks[i].alive || sharks[i].c != col) continue;
            if (sharks[i].r < topRow) {
                topRow = sharks[i].r;
                topIdx = i;
            }
        }
        if (topIdx != -1) {
            ans += sharks[topIdx].z;
            sharks[topIdx].alive = false;
        }

        // 2. 상어 이동
        for (int i = 0; i < M; i++) {
            if (sharks[i].alive) moveShark(sharks[i]);
        }

        // 3. 같은 칸 충돌: 크기 큰 상어가 나머지 잡아먹음
        // grid[r][c] = 해당 칸 최대 크기 상어 인덱스
        vector<vector<int>> grid(R + 1, vector<int>(C + 1, -1));
        for (int i = 0; i < M; i++) {
            if (!sharks[i].alive) continue;
            int r = sharks[i].r, c = sharks[i].c;
            if (grid[r][c] == -1) {
                grid[r][c] = i;
            }
            else {
                int j = grid[r][c];
                if (sharks[i].z > sharks[j].z) {
                    sharks[j].alive = false;
                    grid[r][c] = i;
                }
                else {
                    sharks[i].alive = false;
                }
            }
        }
    }

    cout << ans << "\n";
    return 0;
}