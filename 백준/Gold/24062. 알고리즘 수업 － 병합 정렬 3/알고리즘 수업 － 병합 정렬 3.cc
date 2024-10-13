#include <iostream>
#include <vector>
using namespace std;

vector<int> B;
int prevIndex = -1, N;

bool check(vector<int>& A) {
	for (int i = prevIndex; i < N; i++) {
		if (i == -1) i = 0;

		if (A[i] != B[i]) {
			prevIndex = i - 1;
			return false;
		}
	}

	return true;
}

void merge(vector<int>& A, int start, int mid, int end) {
	int i = start, j = mid + 1, t = 0, size = end - start + 1;
	vector<int> temp(end - start + 1);

	while (i <= mid && j <= end) {
		if (A[i] <= A[j]) temp[t++] = A[i++];
		else temp[t++] = A[j++];
	}

	while (i <= mid) temp[t++] = A[i++];
	while (j <= end) temp[t++] = A[j++];

	for (int i = 0; i <= end - start; i++) {
		if (A[i + start] != temp[i]) {
			if (start + i <= prevIndex) {
				cout << 0; exit(0);
			}

			A[i + start] = temp[i];

			if (check(A)) {
				cout << 1; exit(0);
			}
		}
	}
}

void merge_sort(vector<int>& A, int start, int end) {
	if (check(A)) {
		cout << 1; exit(0);
	}

	if (start < end) {
		int mid = (start + end) / 2;
		merge_sort(A, start, mid);
		merge_sort(A, mid + 1, end);
		merge(A, start, mid, end);
	}
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;

	vector<int> A(N, 0);
	for (int i = 0; i < N; i++) cin >> A[i];

	B.resize(N);
	for (int i = 0; i < N; i++) cin >> B[i];

	merge_sort(A, 0, N - 1);

	cout << 0;

	return 0;
}