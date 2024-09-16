#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#pragma warning(disable:4996)

bool compare(string a, string b) {
	if (a.size() == b.size()) return a < b;
	return a.size() < b.size();
}

int main(void) {
	vector<string> v;
	int N;
	string temp;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> temp;
		auto it = find(v.begin(), v.end(), temp);
		if (it == v.end()) v.push_back(temp);
	}

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < v.size(); i++) cout << v[i] << endl;

	return 0;
}