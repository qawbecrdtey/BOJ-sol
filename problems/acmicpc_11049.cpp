#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto a = new int[n + 1];
    for(int i = 0; i < n; i++) cin >> a[i] >> a[i + 1];
    auto dp = new int*[n + 1];
    for(int i = 0; i <= n; i++) dp[i] = new int[n + 1]();
    // (j, j + k) * (j + k, j + i)
    for(int i = 2; i < n + 1; i++) {
        for(int j = 0; j <= n - i; j++) {
            int const mul = a[j] * a[j + i];
            int res = dp[j + 1][j + i] + a[j + 1] * mul;
            for(int k = 2; k < i; k++) {
                int const x = dp[j][j + k] + dp[j + k][j + i] + a[j + k] * mul;
                if(res > x) res = x;
            }
            dp[j][j + i] = res;
        }
    }
    cout << dp[0][n];
}