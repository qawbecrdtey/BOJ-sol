#include <iostream>
using namespace std;
using ll = long long;
constexpr ll M = 2000000000;
ll f(ll **dp, ll **a, ll n, ll cur, ll visited) {
    if(dp[cur][visited] != -1) return dp[cur][visited];
    if(visited == (1 << n) - 2) return dp[cur][visited] = (a[cur][0] ? a[cur][0] : M);
    dp[cur][visited] = M;
    for(ll i = 1; i < n; i++) {
        if(visited & (1 << i)) continue;
        if(!a[cur][i]) continue;
        ll x = f(dp, a, n, i, visited | (1 << i)) + a[cur][i];
        if(dp[cur][visited] > x) dp[cur][visited] = x;
    }
    return dp[cur][visited];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll n; cin >> n;
    auto a = new ll*[n];
    auto dp = new ll*[n];
    for(ll i = 0; i < n; i++) {
        a[i] = new ll[n];
        for(ll j = 0; j < n; j++) cin >> a[i][j];
        dp[i] = new ll[1 << n];
        fill(dp[i], dp[i] + (1 << n), -1);
    }
    ll min = M;
    for(ll i = 1; i < n; i++) {
        if(!a[0][i]) continue;
        ll x = f(dp, a, n, i, 1 << i) + a[0][i];
        if(min > x) min = x;
    }
    cout << min;
}