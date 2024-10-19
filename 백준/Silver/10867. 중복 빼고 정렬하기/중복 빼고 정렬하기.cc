#include <iostream>
#include <set>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, num;
    cin >> N;

    set<int> s;
    for (int i = 0; i < N; i++) {
        cin >> num;
        s.insert(num);
    }

    for (const auto& value : s) cout << value << " ";

    return 0;
}
