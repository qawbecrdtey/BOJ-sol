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
int kth(int *t, int tidx, int k, int l, int r) {
    t[tidx]--;
    if(l == r) return l;
    auto const m = (l + r) >> 1;
    if(t[tidx << 1] < k) return kth(t, (tidx << 1) | 1, k - t[tidx << 1], m + 1, r);
    return kth(t, tidx << 1, k, l, m);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n; cin >> n;
    auto t = new int[n * 4];
    init(t, 1, 1, n);
    auto a = new int[n];
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        int k = kth(t, 1, x + 1, 1, n);
        a[k - 1] = i + 1;
    }
    for(int i = 0; i < n; i++) cout << a[i] << ' ';
}