#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    string input;
    for (int i = 0; i < N; i++) {
        cin >> input;

        int sum = 0, num = 1;
        for (const char ch : input)
            if (ch == 'O') sum += num++;
            else num = 1;

        cout << sum << "\n";
    }

    return 0;
}