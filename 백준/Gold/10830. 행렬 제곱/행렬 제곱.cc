#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> v;
int N;

vector<vector<int>> multi(vector<vector<int>> temp) {
    vector<vector<int>> newV(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                newV[i][j] += (temp[i][k] * temp[k][j]) % 1000;
                newV[i][j] %= 1000;
            }
        }
    }

    return newV;
}

vector<vector<int>> matrix(long long int n) {
    if (n == 1) return v;

    vector<vector<int>> temp = matrix(n / 2);
    temp = multi(temp);

    if (n % 2) {
        vector<vector<int>> newV(N, vector<int>(N, 0));

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < N; k++) {
                    newV[i][j] += (temp[i][k] * v[k][j]) % 1000;
                    newV[i][j] %= 1000;
                }
            }
        }
        temp = newV;
    }
    return temp;
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    long long int M;
    int inputN;
    cin >> N >> M;

    v.resize(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> inputN;
            v[i][j] = inputN % 1000;
        }
    }

    vector<vector<int>> temp = matrix(M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << temp[i][j] << " ";
        cout << "\n";
    }
    return 0;
}