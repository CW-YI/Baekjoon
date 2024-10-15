#include <iostream>
#include <map>
using namespace std;

map<char, pair<char, char>> m;

void postorder(char key) {
	if (m[key].first != '.') postorder(m[key].first);
	if (m[key].second != '.') postorder(m[key].second);
	cout << key;
}

void preorder(char key) {
	cout << key;
	if (m[key].first != '.') preorder(m[key].first);
	if (m[key].second != '.') preorder(m[key].second);
}

void inorder(char key) {
	if (m[key].first != '.') inorder(m[key].first);
	cout << key;
	if (m[key].second != '.') inorder(m[key].second);
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	char parent, left, right;
	for (int i = 0; i < N; i++) {
		cin >> parent >> left >> right;
		m[parent] = make_pair(left, right);
	}

	preorder('A');
	cout << "\n";
	inorder('A');
	cout << "\n";
	postorder('A');
	return 0;
}