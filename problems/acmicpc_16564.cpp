#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll n, k; cin >> n >> k;
    auto a = new int[n]; for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    ll l = a[0], r = a[n - 1] + k + 1;
    ll res = l;
    while(l < r) {
        ll const m = (l + r) / 2;
        ll sum = 0;
        for(ll i = 0; i < n; i++) {
            if(a[i] >= m) break;
            sum += m - a[i];
        }
        if(sum <= k) {
            res = m;
            l = m + 1;
        }
        else {
            r = m;
        }
    }
    cout << res;
}
