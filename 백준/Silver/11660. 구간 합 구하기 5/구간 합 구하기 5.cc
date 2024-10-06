#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	vector<vector<int>> v(N, vector<int>(N, 0));

	int temp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> temp;

			if (i - 1 >= 0) temp += v[i - 1][j];
			if (j - 1 >= 0) temp += v[i][j - 1];
			if (i - 1 >= 0 && j - 1 >= 0) temp -= v[i - 1][j - 1];

			v[i][j] = temp;
		}
	}

	int x1, y1, x2, y2;
	int sum = 0;
	for (int i = 0; i < M; i++) {
		cin >> x1 >> y1 >> x2 >> y2;

		int sum = v[x2 - 1][y2 - 1];
		
		if (x1 - 2 >= 0) sum -= v[x1 - 1 - 1][y2 - 1];
		if (y1 - 2 >= 0) sum -= v[x2 - 1][y1 - 1 - 1];
		if (x1 - 2 >= 0 && y1 - 2 >= 0) sum += v[x1 - 2][y1 - 2];

		cout << sum << "\n";
	}

	return 0;
}