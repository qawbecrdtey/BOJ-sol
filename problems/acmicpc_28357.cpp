#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll n, k; cin >> n >> k;
    auto a = new ll[n];
    for(ll i = 0; i < n; i++) cin >> a[i];
    ll l = 0, r = *max_element(a, a + n);
    ll result = r + 1;
    while(l < r) {
        ll const m = (l + r) >> 1;
        ll res = 0;
        for(ll i = 0; i < n; i++) {
            if(a[i] <= m) continue;
            res += a[i] - m;
        }
        if(res <= k) {
            r = m;
            result = m;
            continue;
        }
        l = m + 1;
    }
    cout << result;
}
