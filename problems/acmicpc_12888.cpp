#include <iostream>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll n; cin >> n;
    ll res = 1;
    for(ll i = 2; i <= n; i++) {
        res = (res << 1) + 1 - ((i & 1) << 1);
    } cout << res;
}