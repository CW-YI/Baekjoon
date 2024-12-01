#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
const int INF = 1e9;
vector<vector<int>> v;
int N, M;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;

    v.resize(N, vector<int>(N));
    vector<pair<int, int>> chicken, house;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> v[i][j];
            if (v[i][j] == 1) house.push_back({ i, j });
            if (v[i][j] == 2) chicken.push_back({ i, j });
        }
    }

    int houseSize = house.size(), chickenSize = chicken.size();
    vector<vector<int>> houseToChicken(houseSize, vector<int>(chickenSize, 0));

    for (int i = 0; i < houseSize; i++) {
        for (int j = 0; j < chickenSize; j++) {
            houseToChicken[i][j] = abs(house[i].first - chicken[j].first)
                + abs(house[i].second - chicken[j].second);
        }
    }

    int minCityDistance = INF;
    vector<int> combination(chickenSize, 1);
    fill(combination.begin(), combination.begin() + (chickenSize - M), 0);

    do {
        vector<int> selectedChickenIndexes;
        for (int i = 0; i < chickenSize; i++)
            if (combination[i] == 1) selectedChickenIndexes.push_back(i);

        int cityDistance = 0;
        for (int i = 0; i < houseSize; i++) {
            int minDistance = INF;
            for (int chickenIndex : selectedChickenIndexes)
                minDistance = min(minDistance, houseToChicken[i][chickenIndex]);
            cityDistance += minDistance;
        }

        minCityDistance = min(minCityDistance, cityDistance);

    } while (next_permutation(combination.begin(), combination.end()));

    cout << minCityDistance;
    return 0;
}