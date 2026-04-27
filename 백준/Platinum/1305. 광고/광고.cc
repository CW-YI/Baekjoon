#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int L;
    string s;
    cin >> L >> s;

    // KMP failure function 계산
    vector<int> fail(L, 0);
    for (int i = 1, j = 0; i < L; i++) {
        while (j > 0 && s[i] != s[j]) j = fail[j - 1];
        if (s[i] == s[j]) fail[i] = ++j;
    }

    // S의 최소 주기 = L - fail[L-1]
    // 전광판 문자열은 광고를 무한 반복한 것의 부분이므로
    // 최소 주기가 곧 가능한 가장 짧은 광고 길이
    cout << L - fail[L - 1] << "\n";

    return 0;
}