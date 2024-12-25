#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;

    if (N >= 90) cout << "A";
    else if (N >= 80) cout << "B";
    else if (N >= 70) cout << "C";
    else if (N >= 60) cout << "D";
    else cout << "F";
    return 0;
}