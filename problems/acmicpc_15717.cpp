#include <iostream>
using namespace std;
using ll = long long;
static constexpr ll M = 1000000007;
ll power(ll n) {
    if(!n) return 1;
    if(n == 1) return 2;
    ll const r = power(n >> 1);
    return ((r * r) % M * power(n & 1)) % M;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll n; cin >> n; if(!n) cout << 1; else cout << power(n - 1);
}