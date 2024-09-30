#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int sizeNum = 0;
vector<int> v;

void DownHeap(int n) {
	if (n * 2 > sizeNum) return;

	int min = n;
	if (v[n] > v[n * 2]) min = n * 2;
	if (sizeNum >= n * 2 + 1 && v[min] > v[n * 2 + 1]) min = n * 2 + 1;

	if (min == n) return;

	swap(v[min], v[n]);

	DownHeap(min);
}

void UpHeap(int n) {
	if (n == 1 || v[n] >= v[n / 2]) return;

	swap(v[n], v[n / 2]);

	UpHeap(n / 2);
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, temp;
	cin >> N;

	v.assign(N + 1, 0);

	for (int i = 0; i < N; i++) {
		cin >> temp;
		if (temp == 0) {
			if (sizeNum == 0) {
				cout << 0 << "\n";
				continue;
			}

			cout << v[1] << "\n";
			v[1] = v[sizeNum--];
			DownHeap(1);
		}
		else {
			v[++sizeNum] = temp;
			UpHeap(sizeNum);
		}
	}

	return 0;
}