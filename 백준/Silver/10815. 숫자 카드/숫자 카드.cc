#include <iostream>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

int main(void) {
	int N, M, * ar, temp;

	scanf("%d", &N);
	ar = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++) scanf("%d", &ar[i]);

	sort(ar, ar + N);

	scanf("%d", &M);

	for (int j = 0; j < M; j++) {
		scanf("%d", &temp);
		printf("%d ", binary_search(ar, ar + N, temp));
	}

	return 0;
}