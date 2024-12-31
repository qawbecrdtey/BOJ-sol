#include <iostream>
using namespace std;
using ll = long long;
static constexpr ll M = 1000000007;
ll power(ll const n, ll const p) {
    if(!p) return 1;
    if(p == 1) return n;
    ll const v = power(n, p >> 1);
    return ((v * v) % M) * power(n, p & 1) % M;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        ll n; cin >> n;
        if(n == 1) { cout << "5\n"; continue; }
        cout << (4 * power(5, n - 1)) % M << '\n';
    }
}
