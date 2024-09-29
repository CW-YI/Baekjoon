#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;


int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	map<int, vector<int>> graph;
	
	int num, temp, n1, n2;
	cin >> num >> temp;

	for (int i = 0; i < temp; i++) {
		cin >> n1 >> n2;
		graph[n1].push_back(n2);
		graph[n2].push_back(n1);
	}

	queue<int> q;
	vector<int> v(num + 1, 0);
	q.push(1);

	temp = 0;

	while (!q.empty()) {
		v[q.front()] = 1;

		for (int i = 0; i < graph[q.front()].size(); i++)
			if (v[graph[q.front()][i]] == 0) {
				q.push(graph[q.front()][i]);
				v[graph[q.front()][i]] = 1;
			}

		 temp++;
		q.pop();
	}

	cout << temp - 1;
	return 0;
}