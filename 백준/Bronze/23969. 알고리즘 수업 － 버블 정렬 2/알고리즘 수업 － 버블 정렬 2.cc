#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;

void bubble_sort(vector<int>& A) {
	for (int i = N - 1; i > 0; i--) {
		for (int j = 0; j <= i - 1; j++) {
			if (A[j] > A[j + 1]) {
				swap(A[j], A[j + 1]);
				K--;
				if (K <= 0) {
					for (int k = 0; k < N; k++) cout << A[k] << " ";
					exit(0);
				}
			}
		}
	}
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> K;

	vector<int> A(N);
	for (int i = 0; i < N; i++) cin >> A[i];

	bubble_sort(A);
	if (K > 0) cout << -1;
	return 0;
}