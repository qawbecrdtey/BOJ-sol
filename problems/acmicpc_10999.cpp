#include <iostream>
#include <utility>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
ll init(pll *t, ll const *a, int tidx, int l, int r) {
    if(l == r) {
        t[tidx] = make_pair(a[l], 0);
        return a[l];
    }
    auto const m = (l + r) / 2;
    auto const x = init(t, a, tidx * 2, l, m);
    auto const y = init(t, a, tidx * 2 + 1, m + 1, r);
    t[tidx] = make_pair(x + y, 0);
    return t[tidx].first;
}
ll update(pll *t, ll *a, int tidx, int start, int end, ll val, int l, int r) {
    if(r < start || end < l) return t[tidx].first + t[tidx].second * (r - l + 1);
    if(start <= l && r <= end) {
        t[tidx].second += val;
        return t[tidx].first + t[tidx].second * (r - l + 1);
    }
    auto const m = (l + r) / 2;
    if(t[tidx].second) {
        t[tidx * 2].second += t[tidx].second;
        t[tidx * 2 + 1].second += t[tidx].second;
        t[tidx].second = 0;
    }
    auto const x = update(t, a, tidx * 2, start, end, val, l, m);
    auto const y = update(t, a, tidx * 2 + 1, start, end, val, m + 1, r);
    return t[tidx].first = x + y;
}
ll sum(pll *t, ll *a, int tidx, int start, int end, int l, int r) {
    if(r < start || end < l) return 0;
    if(l == r) {
        t[tidx].first += t[tidx].second;
        t[tidx].second = 0;
        return t[tidx].first;
    }
    if(start <= l && r <= end) return t[tidx].first + t[tidx].second * (r - l + 1);
    auto const m = (l + r) / 2;
    if(t[tidx].second) {
        t[tidx * 2].second += t[tidx].second;
        t[tidx * 2 + 1].second += t[tidx].second;
        t[tidx].first += t[tidx].second * (r - l + 1);
        t[tidx].second = 0;
    }
    auto const x = sum(t, a, tidx * 2, start, end, l, m);
    auto const y = sum(t, a, tidx * 2 + 1, start, end, m + 1, r);
    return x + y;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    auto a = new ll[n + 1];
    auto t = new pll[n * 4]();
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    init(t, a, 1, 1, n);
    m += k;
    while(m--) {
        int w, x, y;
        cin >> w >> x >> y;
        if(w == 1) {
            ll z;
            cin >> z;
            update(t, a, 1, x, y, z, 1, n);
        }
        else {
            cout << sum(t, a, 1, x, y, 1, n) << '\n';
        }
    }
    delete[] a;
    delete[] t;
}