#include <iostream>
using namespace std;
using ld = long double;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n; ld s{}, m = 10000000000L, M{}; while(n--) {
        ld x, y; cin >> x >> y; x /= y; s += x; m = min(m, x); M = max(M, x);
    } cout.precision(12); cout << fixed << m << ' ' << M << ' ' << s;
}