#include <iostream>
#include <limits>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto a = new int*[n];
    for(int i = 0; i < n; i++) {
        a[i] = new int[n];
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    auto dp = new int[1 << n];
    fill(dp, dp + (1 << n), numeric_limits<int>::max());
    dp[0] = 0;
    auto next_dp = new int[1 << n];
    fill(next_dp, next_dp + (1 << n), numeric_limits<int>::max());
    next_dp[0] = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < (1 << n); j++) {
            if(dp[j] == numeric_limits<int>::max()) continue;
            for(int k = 0; k < n; k++) {
                if(j & (1 << k)) continue;
                next_dp[j | (1 << k)] = min(next_dp[j | (1 << k)], dp[j] + a[i][k]);
            }
        }
        delete[] dp;
        dp = next_dp;
        next_dp = new int[1 << n];
        fill(next_dp, next_dp + (1 << n), numeric_limits<int>::max());
        next_dp[0] = 0;
    }
    cout << dp[(1 << n) - 1];
}