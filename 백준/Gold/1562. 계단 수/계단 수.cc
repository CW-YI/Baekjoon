#include <iostream>
#include <vector>
using namespace std;
vector<vector<vector<int>>> v;
const int INF = 1e9;
int N;

int func(int num, int i, int b) {
    if (v[num][i][b] != -1) return v[num][i][b];
    b |= (1 << num);

    if (i == N - 1 && b == 1023) return v[num][i][b] = 1;
    else if (i == N - 1) return v[num][i][b] = 0;

    int n1 = 0, n2 = 0;
    if (num > 0) n1 = func(num - 1, i + 1, b);
    if (num < 9) n2 = func(num + 1, i + 1, b);
    
    return v[num][i][b] = (n1 + n2) % INF;
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;
    v.resize(10, vector<vector<int>>(N, vector<int>(1024, -1)));

    int sum = 0;
    for (int i = 1; i <= 9; i++)
        sum = (sum + func(i, 0, 0)) % INF;

    cout << sum;
    return 0;
}