#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int Max = 100001;
int visit[Max] = { 0 };

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int startPos = 0, endPos = 0;
	cin >> startPos >> endPos;
;
	int pos = startPos;

	queue<int> q;
	q.push(startPos);
	visit[startPos] = 1;

	while (!q.empty()) {
		int pos = q.front();
		q.pop();

		if (pos == endPos) {
			cout << visit[pos] - 1;
			break;
		}

		if (pos * 2 < Max && visit[pos * 2] == 0) {
			visit[pos * 2] = visit[pos] + 1;
			q.push(pos * 2);
		}
		if (pos + 1 < Max && visit[pos + 1] == 0) {
			visit[pos + 1] = visit[pos] + 1;
			q.push(pos + 1);
		}
		if (pos - 1 >= 0 && visit[pos - 1] == 0) {
			visit[pos - 1] = visit[pos] + 1;
			q.push(pos - 1);
		}
	}

	return 0;
}