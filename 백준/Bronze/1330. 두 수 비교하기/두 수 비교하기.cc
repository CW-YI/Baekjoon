#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;

    if (N > M) cout << ">";
    else if (N < M) cout << "<";
    else cout << "==";

    return 0;
}