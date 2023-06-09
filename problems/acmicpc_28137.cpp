#include <iostream>
#include <map>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll n, k; cin >> n >> k;
    map<ll, ll> m;
    for(ll i = 0; i < n; i++) {
        ll a, b; cin >> a >> b;
        m[b - a * k]++;
    } ll res = 0;
    for(auto [_, val] : m) res += val * (val - 1);
    cout << res;
}