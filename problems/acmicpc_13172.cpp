#include <iostream>
using ll = long long;
constexpr ll M = 1000000007;
using namespace std;
ll power(ll x, ll n) {
    if(!n) return 1;
    if(n == 1) return x;
    ll const r = power(x, n >> 1);
    return (((r * r) % M) * power(x, n & 1)) % M;
}
inline ll inv(ll x) { return power(x, M - 2); }
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto a = new pair<ll, ll>[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    ll num = 0, den = 1;
    for(int i = 0; i < n; i++) {
        den = (den * a[i].first) % M;
        ll nu = a[i].second;
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            nu = (nu * a[j].first) % M;
        }
        num = (num + nu) % M;
    }
    cout << (num * inv(den)) % M;
}