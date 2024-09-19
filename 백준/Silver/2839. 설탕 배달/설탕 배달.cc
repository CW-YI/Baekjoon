#include <iostream>
using namespace std;

int FindNum(int N) {
	for (int x = N / 5; x >= 0; x--) {
		for (int y = 0; y <= N / 3; y++) {
			if (x * 5 + y * 3 == N) return x + y;
		}
	}
	return -1;
}

int main(void) {
	int N;

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;
	cout << FindNum(N);

	return 0;
}