#include <iostream>
using namespace std;

int A, B;

int findAtoB() {
    int num = 1;
    while (B > 0) {
        if (B == A) return num;

        if (B % 10 == 1) B /= 10;
        else if (B % 2 == 0) B /= 2;
        else return -1;
        num++;
    }
    return -1;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false); 

    cin >> A >> B;
    cout << findAtoB();
    return 0;
}
