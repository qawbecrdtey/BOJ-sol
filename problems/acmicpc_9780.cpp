#include <iostream>
using namespace std;
using ll = long long;
inline ll sum(ll const *a, int from, int to) {
    return a[to] - a[from - 1];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        int n, q; cin >> n >> q;
        auto a = new ll[n + 1]; a[0] = 0;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            a[i] += a[i - 1];
        }
        while(q--) {
            int x, y; cin >> x >> y;
            cout << sum(a, min(n, min(x, y)) + 1, min(n, max(x, y)) + 1) << '\n';
        } cout << '\n';
    }
}