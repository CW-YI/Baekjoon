#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;

	cin >> N;
	map<int, int, greater<int>> hm;
	vector<int> v(N, 0);
	vector<int> B(N, 0);

	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		hm.insert(make_pair(temp, i));
		v[i] = temp;
	}

	for (int i = 0; i < N; i++) 
		cin >> B[i];
		

	int index = N;
	if (v == B) {
		cout << 1;
		return 0;
	}

	for (const auto& pair : hm) {
		--index;
		if (pair.second != index) {
			hm[v[index]] = pair.second;
			swap(v[pair.second], v[index]);
		}

		if (v[index] != B[index]) break;
		if (v == B) {
			cout << 1;
			return 0;
		}
	}

	cout << 0;
	return 0;
}