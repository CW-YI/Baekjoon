#include <iostream>
using namespace std;

int ar[15][15] = { 0 };

int sum(int a, int b) {
	int sumNum = 0;

	for (int j = 1; j <= b; j++) {
		if (ar[a - 1][j] == 0) ar[a - 1][j] = sum(a - 1, j);
		sumNum += ar[a - 1][j];
	}
	ar[a][b] = sumNum;

	return sumNum;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	for (int i = 1; i < 15; i++) ar[0][i] = i;

	int N, a, b;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		cout << sum(a, b) << "\n";
	}
	return 0;
}