#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    string input;
    int N;

    cin >> input >> N;
    cout<< input[N - 1];
    return 0;
}