#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<int> v(21, 0);
	string str;
	int N, temp;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> str;
		if (str == "add") {
			cin >> temp; 
			v[temp] = 1;
		}
		else if (str == "remove") {
			cin >> temp;
			v[temp] = 0;
		}
		else if (str == "check") {
			cin >> temp;
			cout << v[temp] << "\n";
		}
		else if (str == "toggle") {
			cin >> temp;
			v[temp] ^= 1;
		}
		else if (str == "all") for (int j = 1; j <= 20; j++) v[j] = 1;
		else if (str == "empty") for (int j = 1; j <= 20; j++) v[j] = 0;
	}
	return 0;
}