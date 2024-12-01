#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto a = new int[n]; for(int i = 0; i < n; i++) cin >> a[i];
    auto dp = new int[n]; copy(a, a + n, dp);
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(a[j] <= a[i]) continue;
            dp[i] = max(dp[i], dp[j] + a[i]);
        }
    }
    cout << *max_element(dp, dp + n);
}
