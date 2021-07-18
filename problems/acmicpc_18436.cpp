#include <stdio.h>
int init(int *t, int const *a, int tidx, int l, int r) {
    if(l == r) return t[tidx] = (a[l] & 1);
    auto const m = (l + r) / 2;
    auto const x = init(t, a, tidx * 2, l, m);
    auto const y = init(t, a, tidx * 2 + 1, m + 1, r);
    return t[tidx] = x + y;
}
int update(int *t, int tidx, int idx, int val, int l, int r) {
    if(idx < l || r < idx) return t[tidx];
    if(l == r) return t[tidx] = (val & 1);
    auto const m = (l + r) / 2;
    auto const x = update(t, tidx * 2, idx, val, l, m);
    auto const y = update(t, tidx * 2 + 1, idx, val, m + 1, r);
    return t[tidx] = x + y;
}
int odd(int *t, int tidx, int start, int end, int l, int r) {
    if(end < l || r < start) return 0;
    if(start <= l && r <= end) return t[tidx];
    auto const m = (l + r) / 2;
    auto const x = odd(t, tidx * 2, start, end, l, m);
    auto const y = odd(t, tidx * 2 + 1, start, end, m + 1, r);
    return x + y;
}
int main() {
    int n;
    scanf("%d", &n);
    auto a = new int[n + 1];
    auto t = new int[n * 4]();
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    init(t, a, 1, 1, n);
    int m;
    scanf("%d", &m);
    while(m--) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        if(x == 1) {
            update(t, 1, y, z, 1, n);
        }
        else if(x == 2) {
            printf("%d\n", z - y + 1 - odd(t, 1, y, z, 1, n));
        }
        else {
            printf("%d\n", odd(t, 1, y, z, 1, n));
        }
    }
}