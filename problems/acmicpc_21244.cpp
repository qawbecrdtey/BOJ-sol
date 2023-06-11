#include <iostream>
#include <string>
using namespace std;
void init(int *t, int const *a, int tidx, int l, int r) {
    if(l == r) {
        t[tidx] = l;
        return;
    }
    auto const m = (l + r) >> 1;
    init(t, a, tidx << 1, l, m);
    init(t, a, (tidx << 1) | 1, m + 1, r);
    t[tidx] = (a[t[tidx << 1]] <= a[t[(tidx << 1) | 1]] ? t[tidx << 1] : t[(tidx << 1) | 1]);
}
int mini(int const *t, int const *a, int tidx, int start, int end, int l, int r) {
    if(r < start || end < l) return 0;
    if(start <= l && r <= end) return t[tidx];
    auto const m = (l + r) >> 1;
    auto const x = mini(t, a, tidx << 1, start, end, l, m);
    auto const y = mini(t, a, (tidx << 1) | 1, start, end, m + 1, r);
    if(!x) return y;
    if(!y) return x;
    return a[x] <= a[y] ? x : y;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string s; int k; cin >> s >> k;
    int n = (int)s.size();
    auto a = new int[n + 1];
    for(int i = 1; i <= n; i++) a[i] = (unsigned char)(s[i - 1]);
    auto t = new int[n << 2];
    init(t, a, 1, 1, n);
    int lo = 0;
    for(int i = n - k + 1; i <= n; i++) {
        int idx = mini(t, a, 1, lo, i, 1, n);
        cout << s[idx - 1];
        lo = idx + 1;
    }
}