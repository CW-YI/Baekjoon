#include <iostream>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	double A, B;
	cin >> A >> B;
	cout.precision(10);
	cout << A / B;

	return 0;
}