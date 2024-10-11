#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, K;

	cin >> N >> K;
	map<int, int, greater<int>> hm;
	vector<int> v(N, 0);

	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		hm.insert(make_pair(temp, i));
		v[i] = temp;
	}

	int index = N;
	for (const auto& pair : hm) {
		--index;
		if (pair.second == index) continue;

		hm[v[index]] = pair.second;
		swap(v[pair.second], v[index]);
		
		K--;

		if (K == 0) {
			cout << v[pair.second] << " " << v[index];
			return 0;
		}
	}

	cout << -1;
	return 0;
}