#pragma GCC optimize("O3")
#include <unordered_set>
#include <algorithm>
#include <iostream>
using namespace std;
using ll = uint32_t;
inline ll dist2(pair<int, int> const &a, pair<int, int> const &b) {
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}
inline ll sqrt(ll n) {
    ll l = 0, r = n + 1, res = n + 1;
    while(l < r) {
        ll const m = (l + r) / 2;
        ll const x = m * m;
        if(x == n) return m;
        if(x > n) r = m;
        else res = m, l = m + 1;
    } return res;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        int n; cin >> n;
        auto a = new pair<int, int>[n];
        ll d = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i].first >> a[i].second;
        } sort(a, a + n);
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                ll const dd = dist2(a[i], a[j]);
                if(dd <= d) continue;
                int const x = a[j].second - a[i].second;
                int const y = a[i].first - a[j].first;
                if(binary_search(a, a + n, make_pair<int, int>(a[j].first + x, a[j].second + y)) &&
                    binary_search(a, a + n, make_pair<int, int>(a[i].first + x, a[i].second + y))) {
                    d = dd;
                    continue;
                }
                if(binary_search(a, a + n, make_pair<int, int>(a[j].first - x, a[j].second - y)) &&
                    binary_search(a, a + n, make_pair<int, int>(a[i].first - x, a[i].second - y))) {
                    d = dd;
                }
            }
        }
        cout << d << '\n';
        delete[] a;
    }
}