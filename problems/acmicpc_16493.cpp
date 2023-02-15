#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    auto dp = new int*[m + 1]; dp[0] = new int[n + 1]();
    for(int i = 1; i <= m; i++) {
        dp[i] = new int[n + 1]();
        int x, y; cin >> x >> y;
        for(int j = 1; j <= n; j++) {
            dp[i][j] = dp[i - 1][j];
            if(j >= x) dp[i][j] = max(dp[i][j], dp[i - 1][j - x] + y);
        }
    } cout << dp[m][n];
}