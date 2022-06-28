#include <iostream>
using namespace std;
void init(int *t, int const *a, int tidx, int l, int r) {
    if(l == r) {
        t[tidx] = a[l];
        return;
    }
    int const m = (l + r) >> 1;
    init(t, a, tidx << 1, l, m);
    init(t, a, (tidx << 1) | 1, m + 1, r);
    int const x = t[tidx << 1];
    int const y = t[(tidx << 1) | 1];
    t[tidx] = x > y ? x : y;
}
int calc(int const *t, int tidx, int start, int end, int l, int r) {
    if(end < l || r < start) return 0;
    if(start <= l && r <= end) return t[tidx];
    int const m = (l + r) >> 1;
    int const x = calc(t, tidx << 1, start, end, l, m);
    int const y = calc(t, (tidx << 1) | 1, start, end, m + 1, r);
    return x > y ? x : y;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    auto a = new int[n + 1];
    auto t = new int[n << 2];
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    } init(t, a, 1, 1, n); delete[] a;
    for(int i = m; i <= n - m + 1; i++) {
        cout << calc(t, 1, i - m + 1, i + m - 1, 1, n) << ' ';
    }
}