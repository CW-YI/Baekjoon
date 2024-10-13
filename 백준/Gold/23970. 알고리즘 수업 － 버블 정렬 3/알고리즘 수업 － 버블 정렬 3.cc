#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> B;

void bubble_sort(vector<int>& A) {
	for (int i = N - 1; i > 0; i--) {
		for (int j = 0; j <= i - 1; j++) {
			if (A[j] > A[j + 1]) {
				swap(A[j], A[j + 1]);
				
				if (A[j] == B[j]) {
					if (A == B) {
						cout << 1;
						exit(0);
					}
				}
			}
		}
		if (A[i] != B[i]) {
			cout << 0;
			exit(0);
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

	bubble_sort(A);
	cout << 0;
	return 0;
}