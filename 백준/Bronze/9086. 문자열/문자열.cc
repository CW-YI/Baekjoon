#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    string input;
    for (int i = 0; i < N; i++) {
        cin >> input;
        cout << input[0] << input[input.length() - 1] << "\n";
    }
    return 0;
}