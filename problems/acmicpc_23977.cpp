#include <iostream>
#include <numeric>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll k, n; cin >> k >> n;
    ll x; cin >> x;
    ll res = x - k;
    ll mul = x;
    for(int i = 1; i < n; i++) {
        cin >> x;
        while(res % x != x - k) res += mul;
        mul = lcm(mul, x);
    } cout << res;
}