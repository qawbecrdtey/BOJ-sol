#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;
static constexpr ll M = 1000000007;
ll power(ll a, ll n) {
    if(!n) return 1;
    if(n == 1) return a;
    ll const r = power(a, n >> 1);
    return ((r * r) % M * power(a, n & 1)) % M;
}
ll inv(ll a) {
    return a == 0 ? 0 : power(a % M, M - 2);
}
ll comb(ll n, ll k) {
    if(n < k) return 0;
    ll res = 1;
    for(ll i = n; i != n - k; i--) res = (res * i) % M;
    for(ll i = 1; i != k + 1; i++) res = (res * inv(i)) % M;
    return res;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll n, a, b, c; cin >> n >> a >> b >> c;
    if(a + b + c < n) {
        cout << 0;
        return 0;
    }
    ll sign = 1;
    ll front = 1;
    ll A = comb(n, a);
    ll B = comb(n, b);
    ll C = comb(n, c);
    ll res = 0;
    ll k = 0;
    ll const m = n - max({a, b, c});
    while(k <= m) {
        res = (res + sign * front % M * A % M * B % M * C % M) % M;
        sign = M - sign;
        front = front * (n - k) % M * inv(k + 1) % M;
        ll const v = inv(n - k);
        A = A * (n - k - a) % M * v % M;
        B = B * (n - k - b) % M * v % M;
        C = C * (n - k - c) % M * v % M;
        k++;

    }
    cout << res;
}