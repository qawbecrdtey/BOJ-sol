#include <iostream>
using namespace std;
using ll = unsigned long long;
inline ll phi(ll n) {
    ll res = n;
    for(ll i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            while(n % i == 0) n /= i;
            res /= i; res *= i - 1;
        }
    } if(n > 1) {
        res /= n; res *= n - 1;
    } return res;
}
ll power(ll a, ll n, ll p) {
    if(!n) return 1;
    if(n == 1) return a % p;
    ll const r = power(a, n >> 1, p);
    return (((r * r) % p) * power(a, n & 1, p)) % p;
}
inline ll get_fact(ll n, ll ph) {
    ll res = 1;
    for(ll i = 1; i <= n; i++) {
        res = (res * i) % ph;
    } return res;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; for(int tt = 1; tt <= t; tt++) {
        cout << "Case #" << tt << ": ";
        ll a, n, p;
        cin >> a >> n >> p;
        ll ph = phi(p);
        ll fact = (n >= ph ? 0 : get_fact(n, ph));
        cout << power((a + p - 1) % p + 1, (fact + ph - 1) % ph + 1, p) % p << '\n';
    }
}