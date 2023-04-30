#include <iostream>
#include <limits>
#include <vector>
using namespace std;
using ll = long long;
vector<ll> get_primes(ll n) {
    vector<ll> primes{2, 3};
    vector<bool> visited(n + 1);
    ll i = 5, d = 4;
    for(; i * i <= n; i += (d = 6 - d)) {
        if(visited[i]) continue;
        primes.push_back(i);
        for(ll j = i; j <= n; j += (i << 1)) visited[j] = true;
    }
    for(; i <= n; i += (d = 6 - d)) {
        if(!visited[i]) primes.push_back(i);
    }
    return primes;
}
inline ll calc(ll n, ll p, ll cnt) {
    if(n < p) return 0;
    __int128_t power = p;
    ll res = 0;
    while(n >= power) {
        res += static_cast<ll>(n / power);
        power *= p;
    } return res / cnt;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    auto a = new pair<ll, ll>[t];
    ll m = 0;
    for(int i = 0; i < t; i++) {
        cin >> a[i].first >> a[i].second;
        m = max(m, a[i].second);
    }
    auto const primes = get_primes(1000000);
    for(int tt = 0; tt < t; tt++) {
        auto const [n, k] = a[tt];
        ll tmp = k;
        ll res = numeric_limits<ll>::max();
        for(ll p : primes) {
            if(tmp % p) continue;
            ll cnt = 0;
            while(tmp % p == 0) {
                tmp /= p; cnt++;
            }
            res = min(res, calc(n, p, cnt));
        }
        if(tmp != 1) {
            res = min(res, calc(n, tmp, 1));
        }
        cout << res << '\n';
    }
}