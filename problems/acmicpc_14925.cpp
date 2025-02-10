#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    auto a = new int*[n];
    auto dp = new int*[n];
    for(int i = 0; i < n; i++) {
        a[i] = new int[m];
        dp[i] = new int[m]();
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int M = 0;
    for(int i = 0; i < n; i++) {
        dp[i][0] = !a[i][0];
        M = max(M, dp[i][0]);
    }
    for(int j = 0; j < m; j++) {
        dp[0][j] = !a[0][j];
        M = max(M, dp[0][j]);
    }
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            if(a[i][j]) dp[i][j] = 0;
            else if(a[i - 1][j] || a[i][j - 1] || a[i - 1][j - 1]) dp[i][j] = 1;
            else dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
            M = max(M, dp[i][j]);
        }
    }
    cout << M;
}
