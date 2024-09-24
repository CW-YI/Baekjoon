#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, temp;
	cin >> N;

	int ar[10001] = { 0 };

	for (int i = 0; i < N; i++) {
		cin >> temp;
		ar[temp] ++;
	}

	for (int i = 1; i <= 10000; i++) {
		for (int j = 0; j < ar[i]; j++) cout << i << "\n";
	}
	return 0;
}