#include <iostream>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

int N, M;
int ar[100000];

int FindNum(int num) {
	int start = 0, end = N - 1, mid = 0;
	
	while (start <= end) {
		mid = (start + end) / 2;

		if (num == ar[mid]) return 1;
		else if (num < ar[mid]) {
			end = mid - 1;
		}
		else start = mid + 1;
	}
	return 0;
}

int main(void) {
	int temp = 0;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &ar[i]);

	sort(ar, ar + N);

	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &temp);
		printf("%d\n", FindNum(temp));
	}

	return 0;
}