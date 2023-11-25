#include <iostream>
using namespace std;
using ll = long long;
inline ll f(ll n) {
    ll res = n;
    while(n) {
        res += n % 10;
        n /= 10;
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll n; cin >> n;
    for(ll i = max(1LL, n - 9 * 19); i < n; i++) {
        if(f(i) == n) {
            cout << i;
            return 0;
        }
    }
    cout << 0;
}