#include <iostream>
using namespace std;
using ll = long long;
static constexpr ll M = 998244353;
ll power(ll const n, ll const p) {
    if(!p) return 1;
    if(p == 1) return n;
    ll const r = power(n, p >> 1);
    return ((r * r) % M * power(n, p & 1)) % M;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        ll n, k; cin >> n >> k;
        ll sum = 0;
        for(ll i = 2; i <= k + 1; i++) {
            sum = (sum + power(i, n)) % M;
        }
        cout << sum << '\n';
    }
}
