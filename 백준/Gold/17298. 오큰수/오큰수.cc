#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	stack<int> s;
	vector<int> v;
	int N, temp;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		v.push_back(temp);
	}

	for (int i = 0; i < N; i++) {
		while (!s.empty() && v[s.top()] < v[i]) {
			v[s.top()] = v[i];
			s.pop();
		}
		s.push(i);
	}

	while (!s.empty()) {
		v[s.top()] = -1;
		s.pop();
	}

	for (int i = 0; i < N; i++) cout << v[i] << " ";
	return 0;
}