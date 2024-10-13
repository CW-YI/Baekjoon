#include <iostream>
using namespace std;

int N, K;

void printArray(int* A) {
	for (int i = 0; i < N; i++) cout << A[i] << " ";
}

int merge(int* A, int start, int mid, int end) {
	int i = start, j = mid + 1, t = 0, size = end - start + 1;
	int* temp = (int*)malloc(sizeof(int) * size);

	while (i <= mid && j <= end) {
		if (A[i] <= A[j]) temp[t++] = A[i++];
		else temp[t++] = A[j++];
	}

	while (i <= mid) temp[t++] = A[i++];
	while (j <= end) temp[t++] = A[j++];

	for (int i = 0; i <= end - start; i++) {
		A[i + start] = temp[i];
		K--;

		if (K <= 0) {
			printArray(A);
			return 0;
		}
	}

	free(temp);
	return 1;
}

int merge_sort(int* A, int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		if (!merge_sort(A, start, mid)) return 0;
		if (!merge_sort(A, mid + 1, end)) return 0;
		if (!merge(A, start, mid, end)) return 0;
	}
	return 1;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> K;

	int* A = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++) cin >> A[i];

	if (merge_sort(A, 0, N - 1)) cout << -1;

	free(A);
	return 0;
}