#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

// 노드당 크기: 26*4 + 4 + 1 = 109 bytes
// 1,000,001 * 109 ≈ 109MB → 192MB 이내 ✓
const int MAXNODE = 1000001;

struct TrieNode {
    int  children[26];
    int  wordCnt;  // 이 노드를 지나는 단어 수
    bool isEnd;    // 단어의 끝 여부
} pool[MAXNODE];

int poolIdx;

int newNode() {
    memset(pool[poolIdx].children, -1, sizeof(pool[poolIdx].children));
    pool[poolIdx].wordCnt = 0;
    pool[poolIdx].isEnd   = false;
    return poolIdx++;
}

void insert(int root, const string& word) {
    int cur = root;
    pool[cur].wordCnt++;
    for (char ch : word) {
        int c = ch - 'a';
        if (pool[cur].children[c] == -1) {
            pool[cur].children[c] = newNode();
        }
        cur = pool[cur].children[c];
        pool[cur].wordCnt++;
    }
    pool[cur].isEnd = true;
}

// 자식 수를 직접 셈 (childCnt 필드 제거 대신)
int countChildren(int cur) {
    int cnt = 0;
    for (int c = 0; c < 26; c++)
        if (pool[cur].children[c] != -1) cnt++;
    return cnt;
}

// 버튼 클릭 횟수 총합
long long dfs(int cur, bool mustPress) {
    long long total = 0;
    if (mustPress) total += pool[cur].wordCnt;

    for (int c = 0; c < 26; c++) {
        int next = pool[cur].children[c];
        if (next == -1) continue;

        // 다음 글자에서 버튼을 눌러야 하는 조건:
        // 1) 현재 노드 자식이 2개 이상 (분기)
        // 2) 현재 노드가 단어의 끝 (여기서 멈출 수 있음)
        bool nextPress = (countChildren(cur) >= 2) || pool[cur].isEnd;
        total += dfs(next, nextPress);
    }
    return total;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cout << fixed;
    cout.precision(2);

    int n;
    while (cin >> n) {
        poolIdx = 0;
        int root = newNode();

        vector<string> words(n);
        for (int i = 0; i < n; i++) {
            cin >> words[i];
            insert(root, words[i]);
        }

        long long total = 0;
        for (int c = 0; c < 26; c++) {
            int child = pool[root].children[c];
            if (child == -1) continue;
            total += dfs(child, true);  // 첫 글자는 항상 버튼 필요
        }

        cout << (double)total / n << "\n";
    }

    return 0;
}