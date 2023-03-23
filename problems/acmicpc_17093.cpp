#include <iostream>
using namespace std;
using ll = long long;
inline ll dist2(pair<ll, ll> const &a, pair<ll, ll> const &b) {
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    auto a = new pair<ll, ll>[n];
    for(int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
    auto b = new pair<ll, ll>[m];
    ll res = 0;
    for(int i = 0; i < m; i++) {
        cin >> b[i].first >> b[i].second;
        ll val = 0;
        for(int j = 0; j < n; j++) val = max(val, dist2(a[j], b[i]));
        res = max(res, val);
    } cout << res;
}