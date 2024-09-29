#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;


int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M, n1, n2, sum = 0;
	cin >> N >> M;

	vector<int> v(N + 1, 0);

	for (int i = 1; i <= N; i++) {
		cin >> v[i];
		v[i] += v[i - 1];
	}

	for (int i = 0; i < M; i++) {
		cin >> n1 >> n2;
		cout << v[n2] - v[n1 - 1] << "\n";
	}

	return 0;
}