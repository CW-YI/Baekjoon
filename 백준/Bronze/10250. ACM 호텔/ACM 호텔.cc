#include <iostream>
using namespace std;

int main() {
    int T; 
    cin >> T;

    for (int i = 0; i < T; i++) {
        int H, W, N;
        cin >> H >> W >> N;

        int floor = (N - 1) % H + 1;
        int num = (N - 1) / H + 1;

        cout << floor;
        if (num < 10) cout << "0";
        cout << num << endl;
    }

    return 0;
}