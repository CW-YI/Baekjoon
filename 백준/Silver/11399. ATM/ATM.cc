#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<int> v;

	int N, input, time = 0, result = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input;
		v.push_back(input);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < N; i++) {
		time += v[i];
		result += time;
	}

	cout << result;

	return 0;
}