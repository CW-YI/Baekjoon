#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int M;

void printNum(int start, int end, vector<int> v, vector<int> number, int index) {
	if (start > end) return;

	for (int i = start; i < end; i++) {
		if (index > 0 && v[index - 1] >= number[i]) continue;
		v[index] = number[i];
		swap(number[i], number[index]);

		if (index + 1 < M) printNum(start + 1, end, v, number, index + 1);

		if (index == M - 1) {
			for (int j = 0; j < M; j++) cout << v[j] << " ";
			cout << "\n";
		}
	}
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, temp;
	cin >> N >> M;

	vector<int> number;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		number.push_back(temp);
	}

	sort(number.begin(), number.end());
	vector<int> v(M, 0);

	printNum(0, N, v, number, 0);
		
	return 0;
}