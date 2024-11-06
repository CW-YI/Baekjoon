#include <iostream>
#include <vector>

using namespace std;

vector<vector<long long int>> fibonacci(2, vector<long long int>(2, 1));

vector<vector<long long int>> FindNum(long long int n) {
    if (n <= 1) return fibonacci;

    vector<vector<long long int>> num = FindNum(n / 2);
    vector<vector<long long int>> result(2, vector<long long int>(2, 0));

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                result[i][j] = (result[i][j] + (num[i][k] * num[k][j]) % 1000000007) % 1000000007;

    
    if (n % 2) {
        vector<vector<long long int>> total(2, vector<long long int>(2, 0));
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                for (int k = 0; k < 2; k++)
                    total[i][j] = (total[i][j] + (result[i][k] * fibonacci[k][j]) % 1000000007) % 1000000007;
        result = total;
    }

    //cout << "n: " << n << " " << result[0][0] << " \n";
    return result;
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    long long int n;
    cin >> n;

    fibonacci[1][1] = 0;
    cout << FindNum(n - 1)[0][0];
    return 0;
}