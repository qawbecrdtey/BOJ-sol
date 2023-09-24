#include <iostream>
#include <set>
using namespace std;
using ll = long long;
static constexpr ll M = 1000000007;
void update(ll *t, ll tidx, ll idx, ll val, ll l, ll r) {
    if(idx < l || r < idx) return;
    if(l == r) {
        t[tidx] = (t[tidx] + val) % M;
        return;
    }
    auto const m = (l + r) >> 1;
    update(t, tidx << 1, idx, val, l, m);
    update(t, (tidx << 1) | 1, idx, val, m + 1, r);
    t[tidx] = (t[tidx << 1] + t[(tidx << 1) | 1]) % M;
}
ll sum(ll const *t, ll tidx, ll start, ll end, ll l, ll r) {
    if(end < l || r < start) return 0;
    if(start <= l && r <= end) return t[tidx];
    auto const m = (l + r) >> 1;
    auto const x = sum(t, tidx << 1, start, end, l, m);
    auto const y = sum(t, (tidx << 1) | 1, start, end, m + 1, r);
    return (x + y) % M;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto a = new ll[n];
    auto t_cnt = new ll[800004]();
    auto t_sum = new ll[800004]();
    for(int i = 0; i < n; i++) { cin >> a[i]; a[i]++; }
    ll res = 1;
    update(t_cnt, 1, a[0], 1, 1, 200001);
    update(t_sum, 1, a[0], a[0], 1, 200001);
    ll acc_sum = a[0];
    for(int i = 1; i < n; i++) {
        ll lo_cnt = sum(t_cnt, 1, 1, a[i], 1, 200001);
        ll hi_cnt = i - lo_cnt;
        ll lo_sum = sum(t_sum, 1, 1, a[i], 1, 200001);
        ll hi_sum = ((acc_sum - lo_sum) % M + M) % M;
        ll val = (((lo_cnt * a[i] % M - lo_sum) % M + (hi_sum - hi_cnt * a[i] % M) % M) % M + M) % M;
        res = (res * val) % M;
        update(t_cnt, 1, a[i], 1, 1, 200001);
        update(t_sum, 1, a[i], a[i], 1, 200001);
        acc_sum = (acc_sum + a[i]) % M;
    } cout << res;
}