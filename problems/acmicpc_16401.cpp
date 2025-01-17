#include <iostream>
#include <set>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll m, n; cin >> m >> n;
    auto a = new ll[n];
    for(ll i = 0; i < n; i++) cin >> a[i];
    ll l = 0, r = 1000000001, res = 1000000001;
    while(l < r) {
        ll const mid = (l + r) >> 1;
        if(mid == 0) { res = mid; break; }
        ll cnt = 0;
        for(ll i = 0; i < n; i++) cnt += a[i] / mid;
        if(cnt < m) r = mid;
        else res = mid, l = mid + 1;
    }
    cout << res;
}
