#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    string N;
    while (true) {
        cin >> N;
        if (N == "0") break;

        int len = N.length();
        bool isP = true;
        for (int i = 0; i < len / 2 && isP; i++)
            if (N[i] != N[len - i - 1]) isP = false;
        isP ? cout << "yes\n" : cout << "no\n";
    }
    return 0;
}