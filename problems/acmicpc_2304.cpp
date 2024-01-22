#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;
bool comp(pair<ll, ll> const &a, pair<ll, ll> const &b) { return a.second < b.second; }
ll lo(pair<ll, ll> const *l, pair<ll, ll> const *r) {
    if(l == r) return 0;
    auto *const piv = max_element(l, r, comp);
    return lo(l, piv) + (r->first - piv->first) * piv->second;
}
ll hi(pair<ll, ll> const *l, pair<ll, ll> const *r) {
    if(l + 1 == r) return 0;
    auto *const piv = max_element(l + 1, r, comp);
    return (piv->first - l->first) * piv->second + hi(piv, r);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto a = new pair<ll, ll>[n];
    for(int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
    sort(a, a + n, [](pair<ll, ll> const &a, pair<ll, ll> const &b) {
        return a.first < b.first;
    });
    auto const *const piv = max_element(a, a + n, comp);
    cout << lo(a, piv) + piv->second + hi(piv, a + n);
}