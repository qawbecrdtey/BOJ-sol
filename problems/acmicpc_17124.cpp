#include <algorithm>
#include <iostream>
#include <limits>
using namespace std;
using ll = long long;
ll choose(ll const a, ll const br, ll const bl) {
    ll const r = abs(br - a);
    ll const l = abs(bl - a);
    if(l <= r) return bl;
    return br;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        int n, m; cin >> n >> m;
        auto a = new ll[n];
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n);
        auto b = new ll[m + 1];
        for(int i = 0; i < m; i++) cin >> b[i];
        sort(b, b + m); b[m] = numeric_limits<ll>::max();
        int ai = 0, bi = 0;
        ll res = 0;
        while(ai < n) {
            while(bi < m && b[bi] <= a[ai]) {
                bi++;
            }
            res += (bi ? choose(a[ai], b[bi], b[bi - 1]) : b[0]);
            ai++;
        }
        cout << res << '\n';
        delete[] b;
        delete[] a;
    }
}
