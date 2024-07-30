#include <iostream>
#include <limits>
using namespace std;
void print(pair<int, int> const *const *const dp, int const n, int const m) {
    if(!dp[n][m].first) return;
    print(dp, n - dp[n][m].first, m - 1);
    cout << dp[n][m].first << ' ';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    auto a = new int[n + 1];
    auto sum = new int[n + 1]; sum[0] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    // dp[# of marbles count from left][# of segments] = max. of sum of segments
    auto dp = new pair<int, int>*[n + 1];
    for(int i = 0; i <= n; i++) {
        dp[i] = new pair<int, int>[m + 1]();
    }
    for(int i = 1; i <= n; i++) {
        dp[i][1] = {i, sum[i]};
        for(int j = 2; j <= min(i, m); j++) {
            dp[i][j] = {0, numeric_limits<int>::max()};
            for(int l = 1; l <= i - j + 1; l++) {
                int const val = max(dp[i - l][j - 1].second, sum[i] - sum[i - l]);
                if(dp[i][j].second > val) {
                    dp[i][j] = {l, val};
                }
            }
        }
    }
//    for(int i = 0; i <= n; i++) {
//        for(int j = 0; j <= m; j++) {
//            cout << '(' << dp[i][j].first << ", " << dp[i][j].second << ")\t";
//        } cout << '\n';
//    }
    cout << dp[n][m].second << '\n';
    char s[3] {'\0', ' ', '\0'};
    print(dp, n, m);
}
