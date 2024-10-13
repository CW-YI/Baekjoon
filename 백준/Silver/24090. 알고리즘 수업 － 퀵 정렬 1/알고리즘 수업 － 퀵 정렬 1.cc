#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int K;

int partition(vector<int>& A, int start, int end) {
	int x = A[end], i = start - 1;

	for (int j = start; j < end; j++) {
		if (A[j] <= x) {
			K--;
			swap(A[++i], A[j]);

			if (K <= 0) {
				cout << A[i] << " " << A[j];
				exit(0);
			}
		}
	}
		
	if (i + 1 != end) {
		K--;
		swap(A[i + 1], A[end]);

		if (K <= 0) {
			cout << A[i + 1] << " " << A[end];
			exit(0);
		}
	}
	return i + 1;
}

void quick_sort(vector<int>& A, int start, int end) {
	if (start < end) {
		int mid = partition(A, start, end);
		quick_sort(A, start, mid - 1);
		quick_sort(A, mid + 1, end);
	}
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N >> K;

	vector<int> A(N);
	for (int i = 0; i < N; i++) cin >> A[i];

	quick_sort(A, 0, N - 1);
	if (K > 0) cout << -1;
	return 0;
}