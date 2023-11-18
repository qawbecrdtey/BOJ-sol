#include <iostream>
using namespace std;
using ll = long long;
// f(n, k) : A_1 <= l, A_k = 1
pair<ll, bool> sqrt(ll n) {
    ll l = 0, r = n + 1;
    ll res = 0;
    while(l < r) {
        ll const m = (l + r) >> 1;
        ll const M = m * m;
        if(M == n) return {m, true};
        if(M < n) res = m, l = m + 1;
        else r = m;
    }
    return {res, !n || n == 1};
}
ll f(ll **dp, bool **visited, ll n, ll k) {
    if(visited[n][k]) return dp[n][k];
    visited[n][k] = true;
    if(n < k) return dp[n][k] = 0;
    if(!k) return dp[n][0] = 0;
    if(k == 1) return dp[n][1] = (n >= 1);
    auto const [sq, is] = sqrt(n);
    return dp[n][k] = f(dp, visited, n - 1, k) + f(dp, visited, sq - is, k - 1);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    auto dp = new ll*[70001];
    auto visited = new bool*[70001];
    for(int i = 0; i <= 70000; i++) {
        dp[i] = new ll[501]();
        visited[i] = new bool[501]();
    }
    int n; cin >> n;
    while(n--) {
        int n, k; cin >> n >> k;
        ll val = f(dp, visited, n, k);
        if(k) val -= f(dp, visited, n - 1, k);
        cout << val << '\n';
    }
}