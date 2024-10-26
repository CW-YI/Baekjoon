#include <iostream>
using namespace std;

int A, B, C;

long long multi(int N) {
    if (N == 1) return A;

    long long num = multi(N / 2);
    num = (num * num) % C;
    if (N % 2) num = (num * A) % C;
    return num;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false); 

    cin >> A >> B >> C;

    cout << multi(B) % C;
    return 0;
}
