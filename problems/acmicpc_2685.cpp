#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
inline vector<ll> to_bit(ll a, ll n) {
    vector<ll> res;
    while(n) {
        res.push_back(n % a);
        n /= a;
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        ll a, b, c; cin >> a >> b >> c;
        auto vb = to_bit(a, b);
        auto vc = to_bit(a, c);
        vector<int> v(max(vb.size(), vc.size()));
        ll idx = 0;
        for(idx = 0; idx < min(vb.size(), vc.size()); idx++) { v[idx] = (vb[idx] + vc[idx]) % a; }
        for(; idx < vb.size(); idx++) { v[idx] = vb[idx]; }
        for(; idx < vc.size(); idx++) { v[idx] = vc[idx]; }
        ll res = 0;
        for(auto it = v.rbegin(); it != v.rend(); ++it) { res = res * a + *it; }
        cout << res << '\n';
    }
}
