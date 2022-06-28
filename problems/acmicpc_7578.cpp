#pragma GCC optimize("O2")
#include <iostream>
#include <unordered_map>
using namespace std;
using ll = long long;
void update(ll *t, int tidx, int idx, int val, int l, int r) {
    if(idx < l || r < idx) return;
    if(l == r) { t[tidx] = val; return; }
    auto const m = (l + r) >> 1;
    update(t, tidx << 1, idx, val, l, m);
    update(t, (tidx << 1) | 1, idx, val, m + 1, r);
    t[tidx] = t[tidx << 1] + t[(tidx << 1) | 1];
}
ll calc(ll const *t, int tidx, int start, int end, int l, int r) {
    if(end < l || r < start) return 0;
    if(start <= l && r <= end) return t[tidx];
    auto const m = (l + r) >> 1;
    auto const x = calc(t, tidx << 1, start, end, l, m);
    auto const y = calc(t, (tidx << 1) | 1, start, end, m + 1, r);
    return x + y;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    unordered_map<int, int> m;
    for(int i = 1; i <= n; i++) {
        int x; cin >> x; m[x] = i;
    } auto t = new ll[n << 2]();
    ll res = 0;
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        res += calc(t, 1, m[x], n, 1, n);
        update(t, 1, m[x], 1, 1, n);
    } cout << res;
}