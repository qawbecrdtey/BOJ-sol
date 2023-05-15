#include <iostream>
#include <limits>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll n; cin >> n;
    ll res = numeric_limits<ll>::max();
    for(ll i = 1; i * i <= n; i++) {
        ll const j = (n + i - 1) / i;
        res = min(res, (i + 1) * (j + 1));
    } cout << res;
}