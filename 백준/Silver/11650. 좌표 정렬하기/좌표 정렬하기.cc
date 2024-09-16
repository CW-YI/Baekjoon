#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;
#pragma warning(disable:4996)

int main(void) {
	int N, n1, n2;

	scanf("%d", &N);
	
	vector<pair<int, int>> ar;
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &n1, &n2);
		ar.push_back(make_pair(n1, n2));
	}

	sort(ar.begin(), ar.end());

	for (int i = 0; i < N; i++) printf("%d %d\n", ar[i].first, ar[i].second);

	return 0;
}