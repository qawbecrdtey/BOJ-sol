#include <iostream>
#include <map>
#include <numeric>
using namespace std;
using ll = long long;
inline pair<ll, ll> normalize(ll x, ll y) {
    if(!x && !y) return {0, 0};
    ll g = gcd(x, y);
    x /= g; y /= g;
    if(x < 0 || (x == 0 && y < 0)) x = -x, y = -y;
    return {x, y};
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll n; cin >> n;
    map<pair<ll, ll>, ll> m;
    for(ll i = 0; i < n; i++) {
        ll x, y; cin >> x >> y;
        m[normalize(x, y)]++;
    }
    ll res = 0;
    for(auto [k, v] : m) {
        if(k == make_pair<ll, ll>(0, 0)) continue;
        if(auto it = m.find(normalize(k.second, -k.first)); it != m.end()) res += it->second * v;
    }
    res >>= 1;
    res += m[{0, 0}] * (n - m[{0, 0}]) + m[{0, 0}] * (m[{0, 0}] - 1) / 2;
    cout << res;
}