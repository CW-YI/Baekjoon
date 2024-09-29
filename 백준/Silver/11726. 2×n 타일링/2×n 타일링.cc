#include <iostream>
#include <vector>
using namespace std;


int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> v(N + 1, 0);

	v[1] = 1; v[2] = 2;

	for (int i = 3; i <= N; i++) 
		v[i] = (v[i - 1] + v[i - 2]) % 10007;

	cout << v[N];

	return 0;
}