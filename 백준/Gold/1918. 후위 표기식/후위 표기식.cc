#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int priorityNum(char ch) {
    if (ch == '+' || ch == '-') return 1;
    else if (ch == '*' || ch == '/') return 2;
    else return 0;
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    string input;
    cin >> input;

    stack<char> s;
    for (const auto& ch : input) {
        int num = priorityNum(ch);
        if (ch == '(') {
            s.push(ch);
            continue;
        }
        else if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                cout << s.top();
                s.pop();
            }
            s.pop();
            continue;
        }

        if (num == 0) cout << ch;
        else {
            if (s.empty() || priorityNum(s.top()) < num) s.push(ch);
            else {
                while (!s.empty() && priorityNum(s.top()) >= num) {
                    cout << s.top();
                    s.pop();
                }
                s.push(ch);
            }
        }
    }

    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }

    return 0;
}