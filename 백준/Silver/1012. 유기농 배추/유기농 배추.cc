#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int T, M, N, K;
vector<vector<int>> v;
//queue <pair<int, int>> current;

void FindNum(int x, int y) {
	v[x][y] = 0;

	if (x - 1 >= 0 && v[x - 1][y] == 1) FindNum(x - 1, y);
	if (x + 1 < M && v[x + 1][y] == 1) FindNum(x + 1, y);
	if (y - 1 >= 0 && v[x][y - 1] == 1)FindNum(x, y - 1);
	if (y + 1 < N && v[x][y + 1] == 1) FindNum(x, y + 1);
}


int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int x, y, num = 0;

	cin >> T;
	for (int i = 0; i < T; i++) {
		num = 0;
		cin >> M >> N >> K;
		v.assign(M, vector<int>(N, 0));

		for (int j = 0; j < K; j++) {
			cin >> x >> y;
			v[x][y] = 1;
		}

		for (int j = 0; j < M; j++) {
			for (int k = 0; k < N; k++) {
				if (v[j][k] == 1) {
					FindNum(j, k); num++;
				}
			}
		}

		cout << num << "\n";
	}
	return 0;
}