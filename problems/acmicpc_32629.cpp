#include <iostream>
using namespace std;
using ll = long long;
ll sq(ll n) {
    ll l = 0, r = n + 1, res = n + 1;
    while(l < r) {
        ll const m = (l + r) >> 1;
        if(m * m >= n) res = m, r = m;
        else l = m + 1;
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        ll n; cin >> n; n <<= 2;
        ll const l = sq(n);
        cout << (l << 1) << '\n';
    }
}
