#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n; int res = 0, m = 0;
    while(n--) { int x; cin >> x; res += x; m = max(m, x); }
    cout << res - m;
}