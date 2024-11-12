#include <iostream>
#include <vector>

using namespace std;
int N;
const int INF = 1e9;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin >> N;

    int max_prev[3] = { 0, 0, 0 };
    int min_prev[3] = { 0, 0, 0 };

    int n1, n2, n3;
    for (int i = 0; i < N; i++) {
        int max_curr[3], min_curr[3];
        cin >> n1 >> n2 >> n3;

        max_curr[0] = n1 + max(max_prev[0], max_prev[1]);
        max_curr[1] = n2 + max(max_prev[0], max(max_prev[1], max_prev[2]));
        max_curr[2] = n3 + max(max_prev[1], max_prev[2]);

        min_curr[0] = n1 + min(min_prev[0], min_prev[1]);
        min_curr[1] = n2 + min(min_prev[0], min(min_prev[1], min_prev[2]));
        min_curr[2] = n3 + min(min_prev[1], min_prev[2]);

        for (int j = 0; j < 3; j++) {
            max_prev[j] = max_curr[j];
            min_prev[j] = min_curr[j];
        }
    }

    cout << max(max_prev[0], max(max_prev[1], max_prev[2])) << " " << min(min_prev[0], min(min_prev[1], min_prev[2]));
    return 0;
}