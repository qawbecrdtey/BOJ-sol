#include <iostream>
using namespace std;
using ll = long long;
static constexpr ll M = 1000000007;
inline ll power(ll n) {
    if(!n) return 1;
    if(n == 1) return 2;
    auto const r = power(n >> 1);
    return ((r * r) % M * power(n & 1)) % M;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        ll x; cin >> x;
        if(x == 1) cout << "1\n";
        else cout << power(x - 2) << '\n';
    }
}
