#include <iostream>
#include <map>
#include <vector>
using namespace std;

map<int, vector<int>> tree;
map<int, int> w;
int maxWeight = 0;

void makeTree() {
    int N;
    cin >> N;

    w[1] = 0;

    int node, child, weight;
    while (true) {
        cin >> node >> child >> weight;
        if (cin.eof()) break;
        tree[node].push_back(child);
        w[child] = weight;
    }
}

int findMaxWeight(int node) {
    if (tree[node].empty()) return 0;

    int max = 0, subMax = 0, temp;
    for (int i = 0; i < tree[node].size(); i++) {
        temp = findMaxWeight(tree[node][i]) + w[tree[node][i]];
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
    findMaxWeight(1);
    cout << maxWeight;

    return 0;
}
