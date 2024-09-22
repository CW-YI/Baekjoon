#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int forOne(int num) {
	if (num == 1) return 0;
	if (v[num] != -1) return v[num];

	//cout << num << "\n";
	int in1, in2, in3, in4;
	in1 = in2 = in3 = in4 = INT16_MAX;

	if (num % 3 == 0) in1 = 1 + forOne(num / 3);
	if (num % 2 == 0) in2 = 1 + forOne(num / 2);
	in3 = 1 + forOne(num - 1);

	v[num] = min(min(in1, in2), in3);

	return v[num];
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, num = 1;

	cin >> N;

	v.assign(N + 1, -1);
	cout << forOne(N);
	
	return 0;
}