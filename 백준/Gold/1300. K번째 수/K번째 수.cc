#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;

	int left = 1, right = K, mid, count = 0;

	while (left < right) {
		mid = (left + right) / 2;

		count = 0;
		for (int i = 1; i <= N; i++) 
			count += min(mid / i, N);

		if (count >= K) right = mid;
		else left = mid + 1;
	}

	cout << left;

	return 0;
}