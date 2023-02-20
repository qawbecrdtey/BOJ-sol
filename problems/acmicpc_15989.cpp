#include <algorithm>
#include <array>
#include <iostream>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    auto a = new int[t];
    for(int i = 0; i < t; i++) cin >> a[i];
    int n = *max_element(a, a + t);
    auto dp = new array<ll, 4>[n + 4]{};
    dp[1][1] = dp[2][1] = dp[2][2] = dp[3][1] = dp[3][2] = dp[3][3] = 1;
    for(int i = 4; i <= n; i++) {
        dp[i][1] = 1;
        dp[i][2] = dp[i - 2][1] + dp[i - 2][2];
        dp[i][3] = dp[i - 3][1] + dp[i - 3][2] + dp[i - 3][3];
    }
    for(int i = 0; i < t; i++) {
        cout << dp[a[i]][1] + dp[a[i]][2] + dp[a[i]][3] << '\n';
    }
}