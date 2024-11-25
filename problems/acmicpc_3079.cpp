#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll n, m; cin >> n >> m;
    auto a = new ll[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    ll l = 0, r = m * *min_element(a, a + n) + 1; ll res = r;
    while(l < r) {
        ll const t = (l + r) >> 1;
        ll cnt = 0;
        for(int i = 0; i < n; i++) cnt += t / a[i];
        if(cnt >= m) {
            res = t;
            r = t;
        }
        else l = t + 1;
    }
    cout << res;
}
