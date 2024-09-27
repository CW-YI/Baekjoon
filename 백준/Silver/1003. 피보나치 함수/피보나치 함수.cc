#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v;

pair<int, int> fibonacci(int n) {
    if (v[n].first != 0 || v[n].second != 0) return v[n];

    if (n == 0) return v[0] = make_pair(1, 0);
    else if (n == 1) return v[1] = make_pair(0, 1);

    pair<int, int> p1 = fibonacci(n - 1);
    pair<int, int> p2  = fibonacci(n - 2);
    
    return v[n] = make_pair(p1.first + p2.first, p1.second + p2.second);
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int N, num;
    cin >> N, num;

    v.resize(41, make_pair(0, 0));

    for (int i = 0; i < N; i++) {
        cin >> num;
        fibonacci(num);
        cout << v[num].first << " " << v[num].second << "\n";
    }

	return 0;
}