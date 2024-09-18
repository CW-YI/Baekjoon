#include <iostream>
#include <stack>
using namespace std;

int main(void) {
	string input;
	stack<char> s;
	int num = 0;

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> input;
	for (int i = 0; i < input.length(); i++) {
		if (input[i] == '(' && input[i+1] == ')') {
			num += s.size();
			i++;
		}
		else if (input[i] == '(') s.push(input[i]);
		else {
			s.pop();
			num += 1;
		}
	}
	
	cout << num;

	return 0;
}