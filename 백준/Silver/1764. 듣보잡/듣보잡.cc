#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int N, M;
	string temp;
	vector<string>n, m;

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		n.push_back(temp);
	}
	for (int i = 0; i < M; i++) {
		cin >> temp;
		m.push_back(temp);
	}

	sort(n.begin(), n.end()); sort(m.begin(), m.end());

	vector<string> result(n.size() + m.size());
	auto result_end = set_intersection(n.begin(), n.end(), m.begin(), m.end(), result.begin());
	result.resize(result_end - result.begin());

	sort(result.begin(), result.end());
	
	int size = result.size();
	cout << size << "\n";
	for (int i = 0; i < size; i++) cout << result[i] << "\n";

	return 0;
}