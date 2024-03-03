#include <iostream>
using namespace std;
using ll = long long;
void init(ll *t, ll const *a, ll tidx, ll l, ll r) {
    if(l == r) {
        t[tidx] = a[l];
        return;
    }
    ll const m = (l + r) >> 1;
    init(t, a, tidx << 1, l, m);
    init(t, a, (tidx << 1) | 1, m + 1, r);
    t[tidx] = t[tidx << 1] + t[(tidx << 1) | 1];
}
void update(ll *t, ll tidx, ll idx, ll diff, ll l, ll r) {
    if(idx < l || r < idx) return;
    if(l == r) {
        t[tidx] += diff;
        return;
    }
    ll const m = (l + r) >> 1;
    update(t, tidx << 1, idx, diff, l, m);
    update(t, (tidx << 1) | 1, idx, diff, m + 1, r);
    t[tidx] = t[tidx << 1] + t[(tidx << 1) | 1];
}
ll sum(ll const *t, ll tidx, ll start, ll end, ll l, ll r) {
    if(r < start || end < l) return 0;
    if(start <= l && r <= end) return t[tidx];
    ll const m = (l + r) >> 1;
    ll const x = sum(t, tidx << 1, start, end, l, m);
    ll const y = sum(t, (tidx << 1) | 1, start, end, m + 1, r);
    return x + y;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto a = new ll[n + 1];
    for(int i = 1; i <= n; i++) cin >> a[i];
    auto t = new ll[n << 2]();
    init(t, a, 1, 1, n);
    int q; cin >> q; while(q--) {
        ll x, y; cin >> x >> y;
        switch(x) {
            case 1: {
                int z; cin >> z;
                update(t, 1, y, z, 1, n);
            } break;
            case 2: {
                ll l = 1, r = n + 1;
                ll res = n + 1;
                while(l < r) {
                    ll const m = (l + r) >> 1;
                    ll const val = sum(t, 1, 1, m, 1, n);
                    if(val == y) {
                        res = m;
                        break;
                    }
                    if(val < y) {
                        l = m + 1;
                        continue;
                    }
                    r = m;
                    res = m;
                }
                cout << res << '\n';
            } break;
            default: __builtin_unreachable();
        }
    }
}