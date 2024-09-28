#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int FindNum(int num) {
	if (num < 1) return 0;

	if (num == 1) return 1;
	else if (num == 2) return 1 + FindNum(num - 1);
	else if (num == 3) return 1 + FindNum(num - 1) + FindNum(num - 2);

	if (num >= 4) return FindNum(num - 1) + FindNum(num - 2) + FindNum(num - 3);
}


int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, temp;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> temp;
		cout<< FindNum(temp) << "\n";
	}
	return 0;
}