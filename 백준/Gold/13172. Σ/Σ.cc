#include <iostream>
#include <numeric>

using namespace std;
const int MOD = 1000000007;

long long modInverse(long long a, long long mod) {
    long long result = 1, power = mod - 2;
    while (power > 0) {
        if (power % 2 == 1) 
            result = (result * a) % mod;
        a = (a * a) % mod;
        power /= 2;
    }
    return result;
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    long long sum = 0;

    for (int i = 0; i < N; i++) {
        long long Ni, Si;
        cin >> Ni >> Si;

        long long invNi = modInverse(Ni, MOD);
        sum = (sum + Si * invNi % MOD) % MOD;
    }
    cout << sum;
    return 0;
}