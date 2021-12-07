#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n; cin >> n;
    auto a = new int[n];
    auto dp = new int*[n];
    for(int i = 0; i < n; i++) dp[i] = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        dp[i][i] = n * a[i];
        for(int j = i - 1; j >= 0; j--) {
            dp[j][i] = max(dp[j + 1][i] + (n - (i - j)) * a[j], dp[j][i - 1] + (n - (i - j)) * a[i]);
        }
    }
    cout << dp[0][n - 1];
}