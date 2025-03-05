#include <iostream>
#include <map>
using namespace std;
using ll = long long;
static constexpr ll M = 1000000007;
ll fac(ll const n) {
    ll res = 1;
    for(ll i = 1; i <= n; i++) {
        res *= i;
        res %= M;
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll n; cin >> n;
    map<ll, ll> m;
    for(ll i = 0; i < n; i++) {
        ll x; cin >> x; m[x]++;
    }
    ll res = 1;
    for(auto const [k, v] : m) { res *= v; res %= M; }
    res *= fac(n - static_cast<ll>(m.size()));
    cout << res % M;
}
