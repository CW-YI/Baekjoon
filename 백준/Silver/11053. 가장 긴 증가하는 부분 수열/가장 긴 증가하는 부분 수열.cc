#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	int temp;
	vector<pair<int, int>> v;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		v.push_back(make_pair(temp, 0));
	}

	int count = 0, max = 0;
	v[0].second = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (v[i].first < v[j].first && v[i].second + 1 >= v[j].second) {
				v[j].second = v[i].second + 1;
				if (v[j].second > max) max = v[j].second;
			}
		}
	}

	cout << max + 1;

	return 0;
}