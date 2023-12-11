#include <iostream>
using namespace std;
using ll = long long;
static constexpr ll M = 1000000009;
ll calc(ll **dp, int const n, int const m) {
    if(dp[n][m] != -1) return dp[n][m];
    if(!m) return dp[n][0] = !n;
    ll res = 0;
    if(n) res += calc(dp, n - 1, m - 1);
    if(n > 1) res += calc(dp, n - 2, m - 1);
    if(n > 2) res += calc(dp, n - 3, m - 1);
    return dp[n][m] = res % M;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    auto dp = new ll*[1001];
    for(int i = 0; i < 1001; i++) {
        dp[i] = new ll[1001];
        fill_n(dp[i], 1001, -1);
    }
    while(t--) {
        int n, m; cin >> n >> m;
        cout << calc(dp, n, m) << '\n';
    }
}