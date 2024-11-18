#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int N;
    double n1, n2;
    cin >> N;

    vector<pair<double, double>> v(N);
    for (int i = 0; i < N; i++) {
        cin >> n1 >> n2;
        v[i] = { n1, n2 };
    }

    double pSum = 0, nSum = 0, sum = 0.0f;
    for (int i = 0; i < N - 1; i++) {
        pSum += v[i].second * v[i + 1].first;
        nSum += v[i].first * v[i + 1].second;
    }
    pSum += v[N - 1].second * v[0].first;
    nSum += v[N - 1].first * v[0].second;
    sum = abs(pSum - nSum) * (0.5f);

    cout << fixed;
    cout.precision(1);
    cout << sum;
    return 0;
}