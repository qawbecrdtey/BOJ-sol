#include <iostream>
using namespace std;
void init(int *t, int tidx, int l, int r) {
    if(l == r) {
        t[tidx] = 1;
        return;
    }
    auto const m = (l + r) >> 1;
    init(t, tidx << 1, l, m);
    init(t, (tidx << 1) | 1, m + 1, r);
    t[tidx] = t[tidx << 1] + t[(tidx << 1) | 1];
}
void update(int *t, int tidx, int idx, int val, int l, int r) {
    if(idx < l || r < idx) return;
    if(l == r) {
        t[tidx] = val;
        return;
    }
    auto const m = (l + r) >> 1;
    update(t, tidx << 1, idx, val, l, m);
    update(t, (tidx << 1) | 1, idx, val, m + 1, r);
    t[tidx] = t[tidx << 1] + t[(tidx << 1) | 1];
}
int sum(int const *t, int tidx, int start, int end, int l, int r) {
    if(end < l || r < start) return 0;
    if(start <= l && r <= end) return t[tidx];
    auto const m = (l + r) >> 1;
    auto const x = sum(t, tidx << 1, start, end, l, m);
    auto const y = sum(t, (tidx << 1) | 1, start, end, m + 1, r);
    return x + y;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto a = new int[n + 1];
    auto idx = new int[n + 1];
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        idx[a[i]] = i; // a[idx[x]] = x, 1 <= x <= n
    }
    auto t = new int[n << 2];
    init(t, 1, 1, n);
    for(int i = 1; i <= n; i++) {
        if(i & 1) {
            update(t, 1, idx[(i + 1) >> 1], 0, 1, n);
            cout << sum(t, 1, 1, idx[(i + 1) >> 1], 1, n) << '\n';
        }
        else {
            update(t, 1, idx[n - ((i - 1) >> 1)], 0, 1, n);
            cout << sum(t, 1, idx[n - ((i - 1) >> 1)], n, 1, n) << '\n';
        }
    }
}