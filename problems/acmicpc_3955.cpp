#include <iostream>
#include <numeric>
using namespace std;
using ll = long long;
pair<ll, ll> extended_gcd(ll m, ll n) {
    if(!n) return { 1, 0 };
    auto const [l, r] = extended_gcd(n, m % n);
    return { r, l - (m / n) * r };
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        ll m, n; cin >> m >> n;
        if(m == 1) {
            cout << "2\n";
            continue;
        }
        if(gcd(m, n) != 1) {
            cout << "IMPOSSIBLE\n";
            continue;
        }
        auto [l, r] = extended_gcd(m, n);
        if(r < 0) {
            r = (m - (-r) % m) % m;
        } else r %= m;
        while(r * n < m) r += m;
        if(r > 1000000000) cout << "IMPOSSIBLE\n";
        else cout << r << '\n';
    }
}