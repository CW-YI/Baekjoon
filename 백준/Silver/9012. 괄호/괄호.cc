#include <iostream>
#include <stack>
using namespace std;

bool isVPS() {
	stack<char> s;
	string input;

	cin >> input;

	for (int i = 0; i < input.length(); i++) {
		if (input[i] == '(') s.push(input[i]);
		else if (input[i] == ')') {
			if (!s.empty()) s.pop();
			else return false;
		}
	}

	return s.empty();
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	for (int k = 0; k < N; k++) {
		if (isVPS()) cout << "YES\n";
		else cout << "NO\n";
	}
	
	return 0;
}