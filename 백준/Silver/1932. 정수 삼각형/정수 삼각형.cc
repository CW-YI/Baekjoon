#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<int>> v, w;

int findMax(int i, int j) {
    if (w[i][j] != -1) return w[i][j];
    if (i == N - 1) return v[i][j];

    int left = 0, right = 0;
    left = findMax(i + 1, j);
    right = findMax(i + 1, j + 1);
    
    w[i][j] = (left >= right ? left : right) + v[i][j];

    return w[i][j];
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false); 

    cin >> N;
    v.resize(N, vector<int>(N, 0));
    w.resize(N, vector<int>(N, -1));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < i + 1; j++)
            cin >> v[i][j];
   
    cout << findMax(0, 0);
    return 0;
}
