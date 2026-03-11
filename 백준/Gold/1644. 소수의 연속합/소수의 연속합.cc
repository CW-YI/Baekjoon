#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    // N보다 작은 소수들 저장 -> 에라토스테네스의 체

    vector<bool> prime(N + 1, true);

    for (int i = 2; i <= sqrt(N); i++) {
        if (prime[i]) { // i가 소수이면 i의 배수를 없애기
            for (int j = 2; i * j <= N; j++) 
                prime[i * j] = false;
        }
    }

    vector<int> num;
    for (int i = 2; i <= N; i++)
        if (prime[i]) num.push_back(i);

    int left = 0, right = 0, sum = 0, cnt = 0; // 투포인터로 변경
    while (true) {
        if (sum >= N) {
            if (sum == N) cnt++;
            sum -= num[left++];
        }
        else if (right == num.size()) break;
        else sum += num[right++];
    }

    cout << cnt;
    return 0;
}