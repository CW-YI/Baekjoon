#include <iostream>
#include <vector>
using namespace std;

int M;

void printNum(int start, int end, vector<int> v, int index) {
	if (start > end) return;

	for (int i = start; i <= end; i++) {
		v[index] = i;
		if (index + 1 < M) printNum(i + 1, end, v, index + 1);

		if (index == M - 1) {
			for (int j = 0; j <= index; j++) cout << v[j] << " ";
			cout << "\n";
		}
	}
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N >> M;

	vector<int> v(M, 0);
	printNum(1, N, v, 0);
		
	return 0;
}