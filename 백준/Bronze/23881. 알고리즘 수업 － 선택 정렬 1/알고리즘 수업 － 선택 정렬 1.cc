#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int main(void) {
	int N, K;

	scanf("%d %d", &N, &K);
	int* ar = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++)
		scanf("%d", &ar[i]);

	int max;
	for (int i = N - 1; i > 0; i--) {
		max = i;
		for (int j = i - 1; j >= 0; j--)
			if (ar[max] < ar[j]) max = j;
			
		if (i == max) continue;

		int temp = ar[i];
		ar[i] = ar[max];
		ar[max] = temp;
		K--;

		if (K == 0) {
			printf("%d %d", ar[max], ar[i]);
			return 0;
		}
	}

	if (K > 0) printf("-1");
	return 0;
}