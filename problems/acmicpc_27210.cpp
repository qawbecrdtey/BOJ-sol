#include <iostream>
using namespace std;
void init(int *t, int const *a, int tidx, int l, int r) {
    if(l == r) {
        t[tidx] = l;
        return;
    }
    int const m = (l + r) >> 1;
    init(t, a, tidx << 1, l, m);
    init(t, a, (tidx << 1) | 1, m + 1, r);
    t[tidx] = (a[t[tidx << 1]] > a[t[(tidx << 1) | 1]]) ? t[tidx << 1] : t[(tidx << 1) | 1];
}
int maxidx(int const *t, int const *a, int tidx, int start, int end, int l, int r) {
    if(r < start || end < l) return 0;
    if(start <= l && r <= end) return t[tidx];
    int m = (l + r) >> 1;
    int const x = maxidx(t, a, tidx << 1, start, end, l, m);
    int const y = maxidx(t, a, (tidx << 1) | 1, start, end, m + 1, r);
    return (a[x] > a[y] ? x : y);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    int *a[2];
    a[0] = new int[n + 1];
    a[1] = new int[n + 1];
    a[0][0] = a[1][0] = 0;
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        a[0][i] = ((x == 1) << 1) - 1;
        a[1][i] = ((x != 1) << 1) - 1;
    }
    int res = 0;
    for(auto const A : a) {
        auto sum = new int[n + 1];
        sum[0] = 0;
        for(int i = 1; i <= n; i++) {
            sum[i] = A[i] + sum[i - 1];
        }
        auto t = new int[(n + 1) << 2];
        init(t, sum, 1, 1, n);
        for(int i = 0; i < n; i++) {
            int const j = maxidx(t, sum, 1, i + 1, n, 1, n);
            if(res < sum[j] - sum[i]) res = sum[j] - sum[i];
        }
        delete[] sum;
        delete[] t;
    } cout << res;
}