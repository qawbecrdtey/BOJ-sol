#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
using ll = long long;
inline ll sqrt(ll n) {
    if(!n) return 0;
    if(n < 4) return 1;
    ll l = 1, r = n, res = 1;
    while(l < r) {
        ll const m = min((l + r) >> 1, 1000000000LL);
        ll const x = m * m;
        if(x == n) return m;
        if(x < n) res = m, l = m + 1;
        else r = m;
    } return res;
}
inline vector<pair<ll, ll>> factor(ll n) {
    vector<pair<ll, ll>> v;
    ll i;
    for(i = 2; i * i <= n && i <= 1000000; i++) {
        if(n % i) continue;
        v.emplace_back(i, 0);
        while(n % i == 0) {
            v.back().second++;
            n /= i;
        }
    }
    if(n != 1) v.emplace_back(n, 1);
    if(i == 1000001) {
        cout << -1;
        exit(0);
    }
    return v;
}
ll power(ll n, ll p) {
    if(!p) return 1;
    if(p == 1) return n;
    ll const r = power(n, p >> 1);
    return r * r * power(n, p & 1);
}
inline ll divisors_cnt(vector<pair<ll, ll>> const &v) {
    ll res = 1;
    for(auto [val, cnt] : v) {
        res *= (cnt + 1);
    } return res;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll n; cin >> n;
    if(n == 1) {
        cout << 1;
        return 0;
    }
    ll const sq = sqrt(n);
    bool two = false;
    if(sq * sq == n) {
        two = true;
        n = sq;
    }
    auto factors = factor(n);
    if(two) for(auto &p : factors) p.second <<= 1;
    ll g = 0;
    for(auto [val, cnt] : factors) g = gcd(cnt, g);
    for(ll i = g; i; i--) {
        if(g % i) continue;
        ll val = 1;
        for(auto [v, c] : factors) val *= power(v, c / i);
        if(divisors_cnt(factor(val)) == i) {
            cout << val;
            return 0;
        }
    } cout << -1;
}