#include <iostream>
#include <utility>
using namespace std;
int init(pair<int, int> *t, int const *a, int tidx, int l, int r) {
    if(l == r) {
        t[tidx] = { a[l], 0 };
        return a[l];
    }
    auto const m = (l + r) / 2;
    auto const x = init(t, a, tidx * 2, l, m);
    auto const y = init(t, a, tidx * 2 + 1, m + 1, r);
    t[tidx] = { x ^ y, 0 };
    return x ^ y;
}
int calc(pair<int, int> const &p, int n) {
    return p.first ^ ((n & 1) ? p.second : 0);
}
int update(pair<int, int> *t, int tidx, int start, int end, int val, int l, int r) {
    if(r < start || end < l) return calc(t[tidx], r - l + 1);
    if(start <= l && r <= end) {
        t[tidx].second ^= val;
        return calc(t[tidx], r - l + 1);
    }
    auto const m = (l + r) / 2;
    if(t[tidx].second) {
        t[tidx * 2].second ^= t[tidx].second;
        t[tidx * 2 + 1].second ^= t[tidx].second;
        t[tidx].second = 0;
    }
    auto const x = update(t, tidx * 2, start, end, val, l, m);
    auto const y = update(t, tidx * 2 + 1, start, end, val, m + 1, r);
    return t[tidx].first = x ^ y;
}
int val(pair<int, int> *t, int tidx, int start, int end, int l, int r) {
    if(r < start || end < l) return 0;
    if(start <= l && r <= end) return calc(t[tidx], r - l + 1);
    auto const m = (l + r) / 2;
    if(t[tidx].second) {
        t[tidx * 2].second ^= t[tidx].second;
        t[tidx * 2 + 1].second ^= t[tidx].second;
        t[tidx].first = calc(t[tidx], r - l + 1);
        t[tidx].second = 0;
    }
    auto const x = val(t, tidx * 2, start, end, l, m);
    auto const y = val(t, tidx * 2 + 1, start, end, m + 1, r);
    return x ^ y;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    auto a = new int[n + 1];
    auto t = new pair<int, int>[n * 4];
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    init(t, a, 1, 1, n);
    delete[] a;
    int m;
    cin >> m;
    while(m--) {
        int w, x, y;
        cin >> w >> x >> y;
        if(w == 1) {
            int z;
            cin >> z;
            update(t, 1, x + 1, y + 1, z, 1, n);
        }
        else {
            cout << val(t, 1, x + 1, y + 1, 1, n) << '\n';
        }
    }
    delete[] t;
}