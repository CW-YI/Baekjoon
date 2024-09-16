#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning(disable:4996)
using namespace std;

int* ar;
int N, M;

int findNum(int num) {
	int start = 0, end = N - 1, mid, count = 0, temp;

	while (start <= end) {
		mid= (start + end) / 2;

		if (num == ar[mid]) {
			temp = lower_bound(ar, ar + mid, num) - ar;
			count += mid - temp;
			temp = upper_bound(ar + mid, ar + N, num) - ar;
			count += temp - mid;
			return count;
		}
		else if (num < ar[mid]) end = mid - 1;
		else start = mid + 1;
	}
	return count;
}

int main(void) {
	int temp;

	scanf("%d", &N);
	ar = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++) scanf("%d", &ar[i]);

	sort(ar, ar + N);

	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &temp);
		printf("%d ", findNum(temp));
	}

	return 0;
}