#include <iostream>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll n; cin >> n;
    ll res = (2 * n + 1) * (2 * n + 1);
    for(ll i = -n; i <= n; i++) {
        if(!i) continue;
        for(ll j = -n; j <= n; j++) {
            res += (abs(1 - i - j) <= n);
        }
    }
    cout << res;
}
