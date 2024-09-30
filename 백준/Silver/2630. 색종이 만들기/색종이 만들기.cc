#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> v;

pair<int, int> FindNum(int N, int x, int y) {
	if (N == 1 && v[x][y] == 0) return make_pair(0, 1);
	else if (N == 1) return make_pair(1, 0);

	bool finish = false;
	int temp = v[x][y];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (v[x + i][y + j] != temp) {
				finish = true;
				break;
			}
		}
		
		if (finish) break;
	}

	if (!finish && v[x][y] == 0) return make_pair(0, 1);
	else if (!finish && v[x][y] == 1) return make_pair(1, 0);

	pair<int, int> p1 = FindNum(N / 2, x, y);
	pair<int, int> p2 = FindNum(N / 2, x + N / 2, y);
	pair<int, int> p3 = FindNum(N / 2, x, y + N / 2);
	pair<int, int> p4 = FindNum(N / 2, x + N / 2, y + N / 2);

	return make_pair(p1.first + p2.first + p3.first + p4.first, p1.second + p2.second + p3.second + p4.second);
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, temp;
	cin >> N;

	v.assign(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> v[i][j];
		}
	}

	pair<int, int> p = FindNum(N, 0, 0);

	cout << p.second << "\n" << p.first;

	return 0;
}