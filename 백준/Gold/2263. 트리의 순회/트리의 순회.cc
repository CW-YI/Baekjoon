#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

int n;
int ino[100001];   // 인오더
int post[100001];  // 포스트오더
unordered_map<int,int> pos; // 값 → 인오더 인덱스

// 결과를 빠르게 출력하기 위한 버퍼
char buf[1200000];
int bufIdx = 0;

void writeInt(int x) {
    if (x == 0) { buf[bufIdx++] = '0'; return; }
    char tmp[10]; int len = 0;
    while (x > 0) { tmp[len++] = '0' + x % 10; x /= 10; }
    for (int i = len - 1; i >= 0; i--) buf[bufIdx++] = tmp[i];
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) { cin >> ino[i];  pos[ino[i]] = i; }
    for (int i = 0; i < n; i++)   cin >> post[i];

    // 스택에 (inL, inR, postL, postR) 저장
    // 프리오더: 루트 먼저 출력 → 왼쪽 → 오른쪽
    // 명시적 스택이므로 오른쪽을 먼저 push, 왼쪽을 나중에 push

    struct Range { int inL, inR, postL, postR; };
    stack<Range> st;
    st.push({0, n-1, 0, n-1});

    bool first = true;
    while (!st.empty()) {
        auto [inL, inR, postL, postR] = st.top();
        st.pop();

        if (inL > inR) continue;

        // 루트 = post[postR]
        int root = post[postR];
        int mid  = pos[root];       // 인오더에서 루트 위치
        int leftSize = mid - inL;   // 왼쪽 서브트리 크기

        // 프리오더 출력
        if (!first) buf[bufIdx++] = ' ';
        writeInt(root);
        first = false;

        // 오른쪽 서브트리를 먼저 push (나중에 처리)
        // 오른쪽: inorder [mid+1, inR], postorder [postL+leftSize, postR-1]
        st.push({mid+1, inR, postL+leftSize, postR-1});

        // 왼쪽 서브트리를 나중에 push (먼저 처리)
        // 왼쪽:  inorder [inL, mid-1],  postorder [postL, postL+leftSize-1]
        st.push({inL, mid-1, postL, postL+leftSize-1});
    }

    buf[bufIdx++] = '\n';
    fwrite(buf, 1, bufIdx, stdout);

    return 0;
}