#include <stdio.h>
#include <utility>
using namespace std;
int init(pair<int, int> *t, int const *a, int tidx, int l, int r) {
    if(l == r) {
        t[tidx] = make_pair(a[l], 0);
        return a[l];
    }
    auto const m = (l + r) / 2;
    auto const x = init(t, a, tidx * 2, l, m);
    auto const y = init(t, a, tidx * 2 + 1, m + 1, r);
    t[tidx] = make_pair(x ^ y, 0);
    return t[tidx].first;
}
int update(pair<int, int> *t, int tidx, int start, int end, int val, int l, int r) {
    if(end < l || r < start) return t[tidx].first ^ (((r - l) & 1) ? 0 : t[tidx].second);
    if(start <= l && r <= end) {
        t[tidx].second ^= val;
        return t[tidx].first ^ (((r - l) & 1) ? 0 : t[tidx].second);
    }
    auto const m = (l + r) / 2;
    t[tidx * 2].second ^= t[tidx].second;
    t[tidx * 2 + 1].second ^= t[tidx].second;
    t[tidx].second = 0;
    auto const x = update(t, tidx * 2, start, end, val, l, m);
    auto const y = update(t, tidx * 2 + 1, start, end, val, m + 1, r);
    return t[tidx].first = x ^ y;
}
int val(pair<int, int> *t, int tidx, int idx, int l, int r) {
    if(idx < l || idx > r) return 0;
    if(l == r) {
        t[tidx].first ^= t[tidx].second;
        t[tidx].second = 0;
        return t[tidx].first;
    }
    auto const m = (l + r) / 2;
    auto const x = val(t, tidx * 2, idx, l, m);
    auto const y = val(t, tidx * 2 + 1, idx, m + 1, r);
    return x ^ y ^ t[tidx].second;
}
int main() {
    int n;
    scanf("%d", &n);
    auto a = new int[n + 1];
    auto t = new pair<int, int>[n * 4]();
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    init(t, a, 1, 1, n);
    int m;
    scanf("%d", &m);
    while(m--) {
        int w, x;
        scanf("%d%d", &w, &x);
        if(w == 1) {
            int y, z;
            scanf("%d%d", &y, &z);
            update(t, 1, x + 1, y + 1, z, 1, n);
        }
        else {
            printf("%d\n", val(t, 1, x + 1, 1, n));
        }
    }
}