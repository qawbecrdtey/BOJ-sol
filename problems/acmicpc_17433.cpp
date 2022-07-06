#include <iostream>
using namespace std;
using ll = long long;
ll gcd(ll a, ll b) {
    if(!b) return a;
    return gcd(b, a % b);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll t; cin >> t; while(t--) {
        ll n; cin >> n;
        auto a = new ll[n];
        for(ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        ll g = 0;
        for(ll i = 1; i < n; i++) {
            g = gcd(g, abs(a[i] - a[i - 1]));
        }
        if(!g) cout << "INFINITY\n";
        else cout << g << '\n';
        delete[] a;
    }
}