#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll t; cin >> t; while(t--) {
        ll n; cin >> n;
        auto a = new pair<ll, ll>[n];
        ll x = 0, y = 0;
        for(ll i = 0; i < n; i++) {
            cin >> a[i].first >> a[i].second;
            a[i].first <<= 1;
            a[i].second <<= 1;
            x += a[i].first;
            y += a[i].second;
        }
        if(x % n || y % n) goto NO;
        x /= n; y /= n;
        x <<= 1; y <<= 1;
        sort(a, a + n);
        for(int i = 0; i < n; i++) {
            if(auto it = lower_bound(a, a + n, make_pair<ll, ll>(x - a[i].first, y - a[i].second)); it == a + n) {
                goto NO;
            }
        }
        cout << "yes\n";
        goto CLEAR;
NO:
        cout << "no\n";
CLEAR:
        delete[] a;
    }
}
