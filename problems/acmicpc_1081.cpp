#include <iostream>
using namespace std;
using ll = long long;
inline pair<ll, ll> nines(ll n) {
    ll res = 9, cnt = 1;
    while(res * 10 + 9 < n) res = res * 10 + 9, cnt++;
    return { res, cnt };
}
ll sum(ll n) {
    if(n < 10) return n * (n + 1) / 2;
    auto const [nine, power] = nines(n);
    ll res = 0;
    ll mult = 0;
    for(ll i = n, j = 0; i >= 0; i -= nine + 1, j++) {
        if(i <= nine) {
            res += j * (i + 1) + sum(i);
            break;
        }
        res += j * (nine + 1);
        mult++;
    }
    res += mult * sum(nine);
    return res;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll l, u; cin >> l >> u;
    if(!l) cout << sum(u);
    else cout << sum(u) - sum(l - 1);
}