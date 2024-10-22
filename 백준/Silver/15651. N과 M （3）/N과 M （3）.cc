#include <iostream>
#include <vector>
using namespace std;

int M;

void printNum(int end, vector<int> v, int index) {
	for (int i = 1; i <= end; i++) {
		v[index] = i;
		if (index + 1 < M) printNum(end, v, index + 1);

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
	printNum(N, v, 0);
		
	return 0;
}