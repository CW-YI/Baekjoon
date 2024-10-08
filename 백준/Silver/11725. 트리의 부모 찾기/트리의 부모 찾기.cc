#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	int n1, n2;
	map<int, vector<int>> tree;
	tree[1].push_back(0);

	for (int i = 0; i < N - 1; i++) {
		cin >> n1 >> n2;

		tree[n1].push_back(n2);
		tree[n2].push_back(n1);
	}

	queue<int> q;
	vector<int> parent(N + 1, 0);

	parent[1] = 1;
	q.push(1);
	while (!q.empty()) {
		int front = q.front();
		q.pop();

		int size = tree[front].size();

		for (int i = 0; i < size; i++) {
			int temp = tree[front][i];

			if (parent[temp] == 0) q.push(temp);
			else parent[front] = temp;
		}
	}

	for (int i = 2; i <= N; i++)
		cout << parent[i] << "\n";

	return 0;
}