#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, r, c;
    cin >> N;
    cin >> r >> c;

    int long long sizeNum = 1 << N;
    int x = 0, y = 0, result = 0;

    while (sizeNum > 1) {
        sizeNum /= 2;
        int num = sizeNum * sizeNum;

        if (r < x + sizeNum && c >= y + sizeNum) {
            result += num;
            y += sizeNum;
        }
        else if (r >= x + sizeNum && c < y + sizeNum) {
            result += num * 2;
            x += sizeNum;
        }
        else if (r >= x + sizeNum && c >= y + sizeNum) {
            result += num * 3;
            x += sizeNum; y += sizeNum;
        }
    }

    cout << result;
    return 0;
}
