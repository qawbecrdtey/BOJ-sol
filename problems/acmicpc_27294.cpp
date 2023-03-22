#include <iostream>
using namespace std;
inline bool lunch(int t) { return 12 <= t && t <= 16; }
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t, s; cin >> t >> s;
    if(lunch(t) && !s) cout << 320;
    else cout << 280;
}