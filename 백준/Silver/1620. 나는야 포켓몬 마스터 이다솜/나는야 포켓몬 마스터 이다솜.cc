#include <iostream>
#include <map>
#include <cctype>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	map<string, int> name;
	map<int, string> index;
	int N, M, t;
	cin >> N >> M;

	string temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		name.insert({ temp, i + 1 });
		index.insert({ i + 1, temp });
	}

	for (int i = 0; i < M; i++) {
		cin >> temp;
		if (isdigit(temp[0])) cout << index[stoi(temp)] << "\n";
		else cout << name[temp] << "\n";
	}
	return 0;
}