#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n; auto a = new int[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    auto dp = new int[n];
    dp[n - 1] = 1;
    for(int i = n - 2; i >= 0; i--) {
        if(a[i] < a[i + 1]) dp[i] = dp[i + 1] + 1;
        else dp[i] = 1;
    }
    cout << *max_element(dp, dp + n);
}
