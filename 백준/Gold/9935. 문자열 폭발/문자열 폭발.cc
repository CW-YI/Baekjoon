#include <iostream>
#include <string>

using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    string str, boom, result = "";
    cin >> str >> boom;
    int Blen = boom.length();

    for (char ch : str) {
        result += ch;
        if (result.size() >= Blen && result.substr(result.size() - Blen) == boom)
            result.erase(result.size() - Blen);
    }

    if (result.empty()) cout << "FRULA";
    else cout << result;

    return 0;
}