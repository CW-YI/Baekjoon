#include <iostream>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

int main(void) {
	int ar[1000000] = { 0 }, N;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &ar[i]);

	sort(ar, ar + N);
	for (int i = 0; i < N; i++) printf("%d\n", ar[i]);

	return 0;
}