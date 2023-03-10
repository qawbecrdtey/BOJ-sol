#include <iostream>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll n, p; cin >> n >> p;
    auto a = new ll[p + 1]();
    for(ll i = n; i > 0; i--) {
        ll x; cin >> x; a[(i - 1) % (p - 1) + 1] += x;
    } cin >> a[0]; a[0] %= p;
    for(int i = 0; i <= p; i++) a[i] %= p;
    for(int i = 0; i < p; i++) {
        ll res = 0;
        ll mul = 1;
        for(int j = 0; j <= p; j++) {
            res = (res + mul * a[j]) % p;
            mul = (mul * i) % p;
        } cout << res << '\n';
    }
}