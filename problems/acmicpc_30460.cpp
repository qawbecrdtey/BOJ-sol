#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto a = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll *dp[4];
    for(auto &i : dp) {
        i = new ll[n + 1]();
    }
    for(int i = 1; i <= n; i++) {
        dp[0][i] = dp[0][i - 1] + a[i - 1];
        if(i > 3) dp[0][i] = max(dp[0][i], dp[3][i - 1] + a[i - 1]);
        dp[1][i] = dp[0][i - 1] + 2 * a[i - 1];
        if(i > 3) dp[1][i] = max(dp[1][i], dp[3][i - 1] + 2 * a[i - 1]);
        if(i > 1) dp[2][i] = dp[1][i - 1] + 2 * a[i - 1];
        if(i > 2) dp[3][i] = dp[2][i - 1] + 2 * a[i - 1];
    }
//    for(auto const &dpp : dp) {
//        for(int i = 0; i <= n; i++) {
//            cout << dpp[i] << '\t';
//        }
//        cout << '\n';
//    }
    cout << max({dp[0][n], dp[1][n], dp[2][n], dp[3][n]});
}
