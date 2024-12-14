#include <iostream>
#include <algorithm>
using namespace std;

bool IsRange(int a1, int a2, int b1, int b2) {
    return max(a1, b1) <= min(a2, b2);
}

int CCW(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3) {
    long long cross = 1LL * (p2.first - p1.first) * (p3.second - p1.second) -
        1LL * (p2.second - p1.second) * (p3.first - p1.first);
    if (cross > 0) return 1; 
    if (cross < 0) return -1;
    return 0;                
}

bool IsIntersect(pair<int, int> a1, pair<int, int> a2, pair<int, int> b1, pair<int, int> b2) {
    int ccw1 = CCW(a1, a2, b1) * CCW(a1, a2, b2);
    int ccw2 = CCW(b1, b2, a1) * CCW(b1, b2, a2);

    if (ccw1 == 0 && ccw2 == 0)
        return IsRange(min(a1.first, a2.first), max(a1.first, a2.first), min(b1.first, b2.first), max(b1.first, b2.first)) &&
            IsRange(min(a1.second, a2.second), max(a1.second, a2.second), min(b1.second, b2.second), max(b1.second, b2.second));
    return ccw1 <= 0 && ccw2 <= 0;
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    pair<int, int> p_x1, p_x2, p_y1, p_y2;
    cin >> p_x1.first >> p_x1.second >> p_x2.first >> p_x2.second;
    cin >> p_y1.first >> p_y1.second >> p_y2.first >> p_y2.second;

    if (IsIntersect(p_x1, p_x2, p_y1, p_y2)) cout << 1;
    else cout << 0;

    return 0;
}