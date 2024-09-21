#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main(void) {
	int N, n, num = 0;
	bool current = true, error = false;
	string func, input;

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	deque<int> d;

	cin >> N;
	for (int i = 0; i < N; i++) {
		current = true; error = false;
		cin >> func; cin >> n; cin >> input; 

		for (int j = 0; j < input.length(); j++) {
			if (isdigit(input[j])) num = num * 10 + input[j] - '0';
			else {
				if (num != 0) d.push_back(num);
				num = 0;
			}
		}

		for (int j = 0; j < func.length(); j++) {
			if (func[j] == 'R') current = !current;
			else if (func[j] == 'D') {
				if (d.empty()) {
					error = true; break;
				}

				if (current) d.pop_front();
				else d.pop_back();
			}
		}

		//cout << "current : " << current <<"\n";

		if (!error) {
			cout << "[";
			if (!d.empty() && current) {
				for (auto e = d.begin(); e < d.end(); ++e) {
					cout << *e;
					if (e != d.end() - 1) cout << ',';
				}
				//cout << d.front();
			}
			else if (!d.empty()) {
				for (auto e = d.end() - 1; e > d.begin(); --e) {
					cout << *e;
					if (e != d.begin()) cout << ',';
				}
				cout << d.front();
			}
			cout << "]\n";
		}
		else cout << "error\n";

		d.clear();
	}

	return 0;
}