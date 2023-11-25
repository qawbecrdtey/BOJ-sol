#include <algorithm>
#include <array>
#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto dp = new array<int, 3>[n + 1];
    dp[0][0] = dp[0][1] = dp[0][2] = 0;
    for(int i = 1; i <= n; i++) {
        int val; cin >> val;
        dp[i][0] = *max_element(dp[i - 1].begin(), dp[i - 1].end());
        if(!val) {
            dp[i][1] = dp[i][2] = 0;
            continue;
        }
        dp[i][1] = dp[i - 1][0] + val;
        if(val == 1) {
            dp[i][2] = 0;
            continue;
        }
        dp[i][2] = dp[i - 1][1] + val / 2;
    }
    cout << *max_element(dp[n].begin(), dp[n].end());
}