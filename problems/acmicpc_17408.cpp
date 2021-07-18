#include <algorithm>
#include <stdio.h>
#include <utility>
#include <vector>
using namespace std;
pair<int, int> f(pair<int, int> const &a, pair<int, int> const &b) {
    if(a.second >= b.first) return a;
    if(b.second >= a.first) return b;
    auto const x = (a.first > b.first ? a.first : b.first);
    return make_pair(x, a.first + b.first - x);
}
void init(pair<int, int> *t, int const *a, int tidx, int l, int r) {
    if(l == r) {
        t[tidx] = make_pair(a[l], 0);
        return;
    }
    auto const m = (l + r) / 2;
    init(t, a, tidx * 2, l, m);
    init(t, a, tidx * 2 + 1, m + 1, r);
    t[tidx] = f(t[tidx * 2], t[tidx * 2 + 1]);
}
void update(pair<int, int> *t, int tidx, int idx, int val, int l, int r) {
    if(idx < l || idx > r) return;
    if(l == r) {
        t[tidx].first = val;
        return;
    }
    auto const m = (l + r) / 2;
    update(t, tidx * 2, idx, val, l, m);
    update(t, tidx * 2 + 1, idx, val, m + 1, r);
    t[tidx] = f(t[tidx * 2], t[tidx * 2 + 1]);
}
pair<int, int> max2(pair<int, int> *t, int tidx, int start, int end, int l, int r) {
    if(end < l || r < start) return make_pair(0, 0);
    if(start <= l && r <= end) return t[tidx];
    auto const m = (l + r) / 2;
    auto const x = max2(t, tidx * 2, start, end, l, m);
    auto const y = max2(t, tidx * 2 + 1, start, end, m + 1, r);
    return f(x, y);
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
    delete[] a;
    int m;
    scanf("%d", &m);
    while(m--) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        if(x == 1) {
            update(t, 1, y, z, 1, n);
        }
        else {
            auto const p = max2(t, 1, y, z, 1, n);
            printf("%d\n", p.first + p.second);
        }
    }
    delete[] t;
}