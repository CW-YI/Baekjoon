#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, M;
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++)  cin >> v[i];
    
    vector<vector<bool>> pal(N, vector<bool>(N, false));
    for (int i = 0; i < N; i++) pal[i][i] = true;
    for (int i = 0; i < N - 1; i++)
        if (v[i] == v[i + 1]) pal[i][i + 1] = true;
    for (int l = 3; l <= N; l++) {
        for (int i = 0; i <= N - l; i++) {
            int j = i + l - 1;
            if (v[i] == v[j] && pal[i + 1][j - 1]) pal[i][j] = true;
        }
    }

    cin >> M;
    for (int j = 0, s, e; j < M; j++) {
        cin >> s >> e;
        cout << pal[s - 1][e - 1] << "\n";
    }
    return 0;
}