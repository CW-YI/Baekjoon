#include <iostream>
#include <stack>
using namespace std;

int main(void) {
	stack<int> s;
	int N, temp;

	cin >> N;

	string str;
	for (int i = 0; i < N; i++) {
		cin >> str;

		if (str == "push") {
			cin >> temp;
			s.push(temp);
		}
		else if (str == "pop") {
			if (!s.empty()) {
				cout << s.top() << endl;
				s.pop();
			}
			else cout << "-1" << endl;
		}
		else if (str == "size") cout << s.size() << endl;
		else if (str == "empty") printf("%d\n", s.empty());
		else if (str == "top") {
			if (!s.empty()) cout << s.top() << endl;
			else cout << "-1" << endl;
		}
	}

	return 0;
}