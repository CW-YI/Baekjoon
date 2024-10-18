#include <iostream>
#include <queue>
#include <climits>
using namespace std;

queue<int> q;

void postorder(int min, int max) {
    if (q.empty() || q.front() < min || q.front() > max) return;

    int root = q.front();
    q.pop();

    postorder(min, root);
    postorder(root, max);

    cout << root << "\n";
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int num;
    while (cin >> num) q.push(num);

    postorder(-1, INT_MAX);

    return 0;
}
