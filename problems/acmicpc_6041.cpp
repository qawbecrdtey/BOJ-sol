#include <array>
#include <iostream>
#include <set>
using namespace std;
inline int digit(int a, int n) {
    while(n) a /= 10, n--; return a % 10;
}
inline int strike(int a, int b) {
    return (digit(a, 0) == digit(b, 0)) + (digit(a, 1) == digit(b, 1)) + (digit(a, 2) == digit(b, 2)) + (digit(a, 3) == digit(b, 3));
}
inline int ball(int a, int b) {
    bool used_g[4]{}, used[4]{}; int cnt = 0;
    for(int i = 0; i < 4; i++) {
        if(digit(a, i) == digit(b, i)) used_g[i] = true;
    }
    for(int i = 0; i < 4; i++) {
        if(used_g[i]) continue;
        for(int j = 0; j < 4; j++) {
            if(i == j) continue;
            if(used[j] || used_g[j]) continue;
            if(digit(a, i) == digit(b, j)) {
                used[j] = true;
                cnt++;
                break;
            }
        }
    } return cnt;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    set<int> s;
    for(int i = 1000; i < 10000; i++) s.insert(i);
    int t; cin >> t; while(t--) {
        int x, y, z; cin >> x >> y >> z;
        for(auto it = s.begin(); it != s.end();) {
            if(!(strike(*it, x) == y && ball(*it, x) == z)) {
                it = s.erase(it);
            }
            else ++it;
        }
    }
    if(!s.empty()) cout << *s.begin();
    else cout << "NONE";
}