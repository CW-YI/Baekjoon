#include <iostream>
#include <map>
#include <vector>
using namespace std;

map<int, vector<pair<int, int>>> tree;
int maxWeight = 0;

void makeTree() {
    int N;
    cin >> N;
;
    int node, child, weight;
    for (int i = 0; i < N; i++) {
        cin >> node;

        while (true) {
            cin >> child;
            if (child == -1) break;
            cin >> weight;

            tree[node].push_back(make_pair(child, weight));
        }
    }
}

int findMaxWeight(int node, int parent) {
    if (tree[node].empty()) return 0;

    int max = 0, subMax = 0, temp;
    for (int i = 0; i < tree[node].size(); i++) {
        int child = tree[node][i].first;
        if (child == parent) continue;

        temp = findMaxWeight(child, node) + tree[node][i].second;
        if (temp >= max) {
            subMax = max;
            max = temp;
        }
        else if (temp > subMax) subMax = temp;
    } 
    if (maxWeight < max + subMax) maxWeight = max + subMax;

    return max;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false); 

    makeTree();
    findMaxWeight(1, -1);
    cout << maxWeight;

    return 0;
}
