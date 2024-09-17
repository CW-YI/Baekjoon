#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

int main(void) {
	int temp, N, *ar;

	scanf("%d", &N);
	ar = (int*)malloc(sizeof(int) * (N * N + 1));
	ar[0] = 0;

	for (int i = 1; i < N * N + 1; i++) scanf("%d", &ar[i]);
	
	sort(ar + 1, ar + (N * N + 1));
	
	//for (int i = 0; i < N * N + 1; i++) printf("%d ", ar[i]);
	printf("%d", ar[N * N + 1 - N]);

	return 0;
}