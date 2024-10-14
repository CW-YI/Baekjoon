#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> B;

void insert_sort(vector<int>& A) {
	for (int i = 1; i < N; i++) {
		int loc = i - 1;
		int newItem = A[i];

		// 이 지점에서 A[i-1]까지 정렬 되어있는 상태
		while (0 <= loc && newItem < A[loc]) {
			A[loc + 1] = A[loc];

			if (A[loc + 1] == B[loc + 1]) {
				if (A == B) {
					cout << 1;
					exit(0);
				}
			}

			loc--;
		}

		if (loc + 1 != i) {
			A[loc + 1] = newItem;

			if (A[loc + 1] != B[loc + 1]) {
				cout << 0;
				exit(0);
			}
		}
	}
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;

	vector<int> A(N);
	for (int i = 0; i < N; i++) cin >> A[i];
	B.resize(N);
	for (int i = 0; i < N; i++) cin >> B[i];

	if (A == B) {
		cout << 1;
		return 0;
	}

	insert_sort(A);
	cout << 0;
	return 0;
}