#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;

void insert_sort(vector<int>& A) {
	for (int i = 1; i < N; i++) {
		int loc = i - 1;
		int newItem = A[i];

		// 이 지점에서 A[i-1]까지 정렬 되어있는 상태
		while (0 <= loc && newItem < A[loc]) {
			A[loc + 1] = A[loc];
			loc--;
			K--;
			if (K <= 0) {
				for (int j = 0; j < N; j++) cout << A[j] << " ";
				exit(0);
			}
		}

		if (loc + 1 != i) {
			A[loc + 1] = newItem;
			K--;
			if (K <= 0) {
				for (int j = 0; j < N; j++) cout << A[j] << " ";
				exit(0);
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

	insert_sort(A);
	if (K > 0) cout << -1;
	return 0;
}