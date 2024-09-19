#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int N;
	string temp;

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;

	for (int i = 666; ; i++) {
		temp = to_string(i);
		if (temp.find("666") != -1) {
			N--;
			if (N <= 0) {
				cout << i;
				break;
			}
		}
	}
	return 0;
}