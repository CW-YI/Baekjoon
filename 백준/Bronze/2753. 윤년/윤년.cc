#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    if ((N % 4 == 0 && N % 100 != 0) || N % 400 == 0) cout << 1;
    else cout << 0;
    return 0;
}