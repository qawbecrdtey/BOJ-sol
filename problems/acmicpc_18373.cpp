#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
static vector<ll> fact = []() {
    vector<ll> fact;
    ll val = 1;
    ll i = 1;
    while(val <= 1000000000000LL) {
        fact.push_back(val);
        val *= i++;
    }
    return fact;
}();
ll power(ll n, ll m, ll p) {
    if(!m) return 1;
    if(m == 1) return n;
    ll const r = power(n, m >> 1, p);
    return (r * r) % p * power(n, m & 1, p) % p;
}
ll inv(ll n, ll p) {
    return power(n % p, p - 2, p);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, k, p; cin >> n >> k >> p;
    if(n < 2) { cout << 1; return 0; }
    if(n == 2) { cout << 2 % p; return 0; }
    ll val = n;
    for(int i = 0; i < k; i++) {
        if(val >= p) { cout << 0; return 0; }
        if(val >= fact.size()) {
            if(i < k - 1) { cout << 0; return 0; }
            ll res = 1;
            if(val * 2 < 500000000) {
                for(ll j = 1; j <= val; j++) {
                    res = (res * j) % p;
                }
            }
            else {
                res = p - 1;
                ll mul = 1;
                for(ll j = p - 1; j > val; j--) {
                    mul = (mul * j) % p;
                }
                res = (res * inv(mul, p)) % p;
            }
            cout << res;
            return 0;
        }
        val = fact[val];
    }
    cout << val % p;
}