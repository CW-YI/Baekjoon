#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, sum = 0;
    string input;
    cin >> N >> input;

    for (int i = 0; i < N; i++)
        sum += input[i] - '0';
    cout << sum;
    return 0;
}