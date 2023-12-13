#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
inline vector<ll> prime_factors(ll c) {
    vector<ll> res;
    ll n = 2;
    while(c > 1 && n * n <= c) {
        if(c % n) goto FLG;
        res.push_back(n);
        while(c % n == 0) c /= n;
    FLG:n++;
    }
    if(c != 1) res.push_back(c);
    return res;
}
ll count(ll const n, vector<ll> const &primes) {
    if(!n) return 0;
    auto const size = 1 << primes.size();
    ll res = 0;
    for(ll i = 0; i < size; i++) {
        ll count_one = 0;
        ll val = 1;
        for(ll j = 0; j < primes.size(); j++) {
            if(((i >> j) & 1)) {
                count_one++;
                val *= primes[j];
            }
        }
        res -= (((count_one & 1) << 1) - 1) * (n / val);
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; for(int tt = 1; tt <= t; tt++) {
        cout << "Case #" << tt << ": ";
        ll a, b, c; cin >> a >> b >> c;
        auto const primes = prime_factors(c);
        cout << count(b, primes) - count(a - 1, primes) << '\n';
    }
}