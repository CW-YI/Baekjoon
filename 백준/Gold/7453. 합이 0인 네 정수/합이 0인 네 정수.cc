#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> A(N), B(N), C(N), D(N);

    for (int i = 0; i < N; i++)
        cin >> A[i] >> B[i] >> C[i] >> D[i];

    sort(A.begin(), A.end()); sort(B.begin(), B.end());
    sort(C.begin(), C.end()); sort(D.begin(), D.end());

    vector<int> AB, CD;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            AB.push_back(A[i] + B[j]);
            CD.push_back(C[i] + D[j]);
        }
    }

    sort(AB.begin(), AB.end()); sort(CD.begin(), CD.end());

    long long result = 0;
    int left = 0, right = CD.size() - 1;
    while (left < AB.size() - 1 && right >= 0) {
        long long sum = AB[left] + CD[right];

        if (sum == 0) {
            long long countAB = 1, countCD = 1;

            while (left + 1 < AB.size() && AB[left] == AB[left + 1]) { countAB++; left++; }
            while (right - 1 >= 0 && CD[right] == CD[right - 1]) { countCD++; right--; }

            result += countAB * countCD;
            left++; right--;
        }
        else if (sum < 0) left++;
        else right--;
    }

    cout << result;
    return 0;
}