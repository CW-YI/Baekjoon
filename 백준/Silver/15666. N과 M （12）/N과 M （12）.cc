#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> number;

void printNum(int end, vector<int> v, int startIndex, int index) {
	int prevNum = 0;
	for (int i = startIndex; i < end; i++) {
		if (prevNum == number[i]) continue;

		prevNum = number[i];
		v[index] = number[i];

		if (index + 1 < M) printNum(end, v, i, index + 1);

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

	for (int i = 0; i < N; i++) {
		cin >> temp;
		number.push_back(temp);
	}

	sort(number.begin(), number.end());
	vector<int> v(M, 0);

	printNum(N, v, 0, 0);
		
	return 0;
}