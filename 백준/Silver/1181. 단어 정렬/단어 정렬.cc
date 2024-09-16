#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
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
		v.push_back(temp);
	}

	set<string> s(v.begin(), v.end());
	v.assign(s.begin(), s.end());

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < v.size(); i++) cout << v[i] << endl;

	return 0;
}