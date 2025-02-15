#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll n; cin >> n;
    auto a = new ll[n];
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll const M = *max_element(a, a + n);
    ll L; cin >> L;
    ll l = 0, r = max(M, L) + 1;
    ll res = r;
    while(l < r) {
        ll const m = (l + r) >> 1;
        ll val = 0;
        for(ll i = 0; i < n; i++) {
            if(m < a[i]) val += (m - a[i]) * 2;
            else val += m;
        }
        if(val < L) {
            l = m + 1;
            continue;
        }
        res = m;
        r = m;
    }
    cout << res;
}
