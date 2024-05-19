#include <iostream>
using namespace std;
using ll = long long;
ll area(pair<ll, ll> const *start, pair<ll, ll> const *end) {
    ll res = 0;
    auto p = start;
    while(p != end - 1) {
        res += p->first * (p + 1)->second;
        res -= p->second * (p + 1)->first;
        p++;
    }
    res += (end - 1)->first * start->second;
    res -= (end - 1)->second * start->first;
    return abs(res);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n; auto a = new pair<ll, ll>[n << 1];
    for(int i = 0; i < n; i++) { cin >> a[i].first >> a[i].second; }
    copy(a, a + n, a + n);
    ll const total = area(a, a + n);
    ll res = total;
    for(int i = 0; i < n; i++) {
        for(int j = 3; j < n; j++) {
            ll const slice = area(a + i, a + i + j);
            res = min(res, abs(total - 2 * slice));
        }
    } cout << (res >> 1) << '.' << (res & 1) * 5;
}
