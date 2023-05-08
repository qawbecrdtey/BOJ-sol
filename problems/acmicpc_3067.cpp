#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        int n; cin >> n;
        auto a = new int[n + 1];
        for(int i = 1; i <= n; i++) cin >> a[i];
        int m; cin >> m;
        auto dp = new int*[n + 1];
        dp[0] = new int[m + 1](); dp[0][0] = 1;
        for(int i = 1; i <= n; i++) {
            dp[i] = new int[m + 1]();
            for(int j = a[i]; j <= m; j++) {
                dp[i][j] += dp[i][j - a[i]];
                for(int k = 0; k < i; k++) {
                    dp[i][j] += dp[k][j - a[i]];
                }
            }
        }
        int res = 0;
        for(int i = 0; i <= n; i++) res += dp[i][m];
        cout << res << '\n';
        for(int i = 0; i <= n; i++) delete[] dp[i];
        delete[] dp;
        delete[] a;
    }
}