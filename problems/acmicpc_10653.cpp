#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, k; cin >> n >> k; k = min(n - 2, k);
    auto a = new pair<int, int>[n];
    for(int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
    auto const dist = [a](int from, int to) {
        return abs(a[from].first - a[to].first) + abs(a[from].second - a[to].second);
    };
    auto dp = new int*[n];
    for(int i = 1; i < n; i++) {
        dp[i] = new int[i]();
        dp[i][i - 1] = dist(0, i);
        for(int j = 0; j < i - 1; j++) {
            dp[i][j] = dp[i - j - 1][0] + dist(i - j - 1, i);
            for(int l = 1; l <= j; l++) {
                dp[i][j] = min(dp[i][j], dp[i - j - 1 + l][l] + dist(i - j - 1 + l, i));
            }
        }
    } cout << dp[n - 1][k];
}