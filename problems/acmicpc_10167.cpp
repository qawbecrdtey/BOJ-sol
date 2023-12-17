#include <algorithm>
#include <iostream>
#include <limits>
using namespace std;
using ll = long long;
static constexpr ll M = static_cast<ll>(numeric_limits<int>::max()) << 23;
struct tree_node {
    ll left_max;
    ll right_max;
    ll total_max;
    ll sum;
};
void update(tree_node *t, int tidx, int idx, ll value, int l, int r) {
    if(idx < l || r < idx) return;
    if(l == r) {
        t[tidx].left_max = max(0LL, t[tidx].sum + value);
        t[tidx].right_max = max(0LL, t[tidx].sum + value);
        t[tidx].total_max = max(0LL, t[tidx].sum + value);
        t[tidx].sum += value;
        return;
    }
    auto const m = (l + r) >> 1;
    update(t, tidx << 1, idx, value, l, m);
    update(t, (tidx << 1) | 1, idx, value, m + 1, r);
    t[tidx].left_max = max(t[tidx << 1].left_max, t[tidx << 1].sum + t[(tidx << 1) | 1].left_max);
    t[tidx].right_max = max(t[(tidx << 1) | 1].right_max, t[(tidx << 1) | 1].sum + t[tidx << 1].right_max);
    t[tidx].total_max = max({t[tidx << 1].total_max, t[(tidx << 1) | 1].total_max, t[tidx << 1].right_max + t[(tidx << 1) | 1].left_max});
    t[tidx].sum = t[tidx << 1].sum + t[(tidx << 1) | 1].sum;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto a = new tuple<ll, ll, ll>[n];
    auto x = new ll[n];
    auto y = new ll[n];
    for(int i = 0; i < n; i++) {
        cin >> get<0>(a[i]) >> get<1>(a[i]) >> get<2>(a[i]);
        x[i] = get<0>(a[i]);
        y[i] = get<1>(a[i]);
    }
    sort(x, x + n);
    sort(y, y + n);
    auto const px = unique(x, x + n);
    auto const py = unique(y, y + n);
    sort(a, a + n, [](tuple<ll, ll, ll> const &a, tuple<ll, ll, ll> const &b) {
        return get<1>(a) < get<1>(b) || (get<1>(a) == get<1>(b) && get<0>(a) < get<0>(b));
    });
    auto const nx = px - x;
    auto const ny = py - y;
    auto t = new tree_node[nx << 2];
    ll res = -M;
    for(int y_lo = 0; y_lo < ny; y_lo++) {
        fill_n(t, nx << 2, tree_node{0, 0, 0, 0});
        auto idx = lower_bound(a, a + n, make_tuple<ll, ll, ll>(-M, forward<ll>(y[y_lo]), 0), [](tuple<ll, ll, ll> const &a, tuple<ll, ll, ll> const &b) {
            return get<1>(a) < get<1>(b) || (get<1>(a) == get<1>(b) && get<0>(a) < get<0>(b));
        }) - a;
        for(int y_hi = y_lo; y_hi < ny; y_hi++) {
            auto end_idx = idx;
            while(end_idx < n && get<1>(a[end_idx]) == get<1>(a[idx])) {
                update(t, 1, static_cast<int>(lower_bound(x, x + nx, get<0>(a[end_idx])) - x) + 1, get<2>(a[end_idx]), 1, static_cast<int>(nx));
                end_idx++;
            }
            res = max(res, t[1].total_max);
            idx = end_idx;
        }
    }
    cout << res;
}