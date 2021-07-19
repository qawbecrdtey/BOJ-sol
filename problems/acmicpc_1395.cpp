#include <iostream>
#include <utility>
using namespace std;
int res(pair<int, bool> const &p, int n) {
    if(p.second) return n - p.first;
    return p.first;
}
int update(pair<int, bool> *t, int tidx, int start, int end, int l, int r) {
    if(end < l || r < start) return res(t[tidx], r - l + 1);
    if(start <= l && r <= end) {
        t[tidx].second = !t[tidx].second;
        return res(t[tidx], r - l + 1);
    }
    auto const m = (l + r) / 2;
    if(t[tidx].second) {
        t[tidx * 2].second = !t[tidx * 2].second;
        t[tidx * 2 + 1].second = !t[tidx * 2 + 1].second;
        t[tidx].second = false;
    }
    auto const x = update(t, tidx * 2, start, end, l, m);
    auto const y = update(t, tidx * 2 + 1, start, end, m + 1, r);
    return t[tidx].first = x + y;
}
int count(pair<int, bool> *t, int tidx, int start, int end, int l, int r) {
    if(end < l || r < start) return 0;
    if(start <= l && r <= end) return res(t[tidx], r - l + 1);
    auto const m = (l + r) / 2;
    if(t[tidx].second) {
        t[tidx * 2].second = !t[tidx * 2].second;
        t[tidx * 2 + 1].second = !t[tidx * 2 + 1].second;
        t[tidx].first = res(t[tidx * 2], m - l + 1) + res(t[tidx * 2 + 1], r - m);
        t[tidx].second = false;
    }
    auto const x = count(t, tidx * 2, start, end, l, m);
    auto const y = count(t, tidx * 2 + 1, start, end, m + 1, r);
    return x + y;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    auto t = new pair<int, bool>[n * 4]();
    while(m--) {
        int x, y, z;
        cin >> x >> y >> z;
        if(!x) {
            update(t, 1, y, z, 1, n);
        }
        else {
            cout << count(t, 1, y, z, 1, n) << '\n';
        }
    }
    delete[] t;
}