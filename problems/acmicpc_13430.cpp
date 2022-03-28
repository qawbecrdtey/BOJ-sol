#include <iostream>
using namespace std;
using ll = long long;
constexpr ll M = 1000000007;
ll power(ll a, ll n) {
    if(!n) return 1;
    if(n == 1) return a;
    ll const r = power(a, n >> 1);
    return ((r * r) % M * power(a, n & 1)) % M;
}
inline ll inv(ll n) {
    return power(n, M - 2);
}
int main() {
    ll k, n; cin >> k >> n;
    ll res = 1, rev = 1;
    for(ll i = n; i <= n + k; i++) {
        res = (res * i) % M;
    }
    for(int i = 1; i <= k + 1; i++) {
        rev = (rev * i) % M;
    }
    res = (res * inv(rev)) % M;
    cout << res;
}