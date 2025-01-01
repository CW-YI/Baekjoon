#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int total = 0;
    string input;
    getline(cin, input);

    istringstream iss(input);
    string word;
    while (iss >> word) total++;

    cout << total;
    return 0;
}