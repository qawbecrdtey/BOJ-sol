#include <iostream>
#include <string>
using namespace std;
int f(int *const *const dp, string const &s, int const l, int const r) {
    if(dp[l][r] != -1) return dp[l][r];
    if(l == r) return dp[l][r] = 0;
    if(l + 1 == r) return dp[l][r] = s[l] != s[r];
    dp[l][r] = min(f(dp, s, l + 1, r), f(dp, s, l, r - 1)) + 1;
    if(s[l] == s[r]) dp[l][r] = min(dp[l][r], f(dp, s, l + 1, r - 1));
    return dp[l][r];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; string s; cin >> n >> s;
    auto dp = new int*[n];
    for(int i = 0; i < n; i++) {
        dp[i] = new int[n];
        fill(dp[i], dp[i] + n, -1);
    }
    cout << f(dp, s, 0, n - 1);
}
