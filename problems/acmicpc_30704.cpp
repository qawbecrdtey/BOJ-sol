#include <iostream>
using namespace std;
using ll = long long;
ll sqrt(ll n) {
    ll l = 0, r = n, res = 0;
    while(l < r) {
        ll const m = (l + r) >> 1;
        if(m * m == n) return m;
        if(m * m < n) {
            res = m;
            l = m + 1;
        }
        else r = m;
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        ll n; cin >> n;
        ll const l = sqrt(n);
        if(l * l == n) {
            cout << (l << 2) << '\n';
            continue;
        }
        if(l * l + l >= n) {
            cout << (l << 2) + 2 << '\n';
            continue;
        }
        cout << ((l + 1) << 2) << '\n';
    }
}