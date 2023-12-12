#include <iostream>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll n, m, p; cin >> n >> m >> p;
    p = (p + 1) >> 1;
    ll res = 0;
    for(ll i = 1; i <= n; i++) {
        for(ll j = max(p - i, 1LL); j <= m; j++) {
            res += (n - i + 1) * (m - j + 1);
        }
    }
    cout << res;
}