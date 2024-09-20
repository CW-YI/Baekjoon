#include <iostream>
#include <set>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	set<int> s;
	set<int>::iterator iter;
	string str;
	int N, temp;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> str;
		if (str == "add") {
			cin >> temp; s.insert(temp);
		}
		else if (str == "remove") {
			cin >> temp;
			iter = s.find(temp);

			if (iter != s.end()) s.erase(temp);
		}
		else if (str == "check") {
			cin >> temp;
			iter = s.find(temp);

			if (iter != s.end()) cout << 1 << "\n";
			else cout << 0 << "\n";
		}
		else if (str == "toggle") {
			cin >> temp;
			iter = s.find(temp);

			if (iter != s.end()) s.erase(temp);
			else s.insert(temp);
		}
		else if (str == "all") {
			for (int j = 1; j <= 20; j++) s.insert(j);
		}
		else if (str == "empty") s.clear();
	}
	return 0;
}