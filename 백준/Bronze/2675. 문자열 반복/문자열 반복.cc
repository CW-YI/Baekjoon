#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, M;
    string input;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> M >> input;
        for (int j = 0; j < input.size(); j++)
            for (int k = 0; k < M; k++)
                cout << input[j];
        cout << "\n";
    }
    return 0;
}