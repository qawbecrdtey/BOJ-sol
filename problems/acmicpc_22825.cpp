#include <iostream>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll n; while(cin >> n) {
        if(!n) return 0;
        ll res = n * n * n;
        for(ll x = 1; x < n; x++) {
            for(ll y = x; y < n && x * x * x + y * y * y <= n * n * n; y++) {
                res = min(res, n * n * n - x * x * x - y * y * y);
            }
        } cout << res << '\n';
    }
}